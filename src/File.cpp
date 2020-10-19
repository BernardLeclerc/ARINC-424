#include "File.h"
using namespace Arinc424;
using std::string;

#include <iostream>
using std::istream;
using std::ostream;
using std::clog;
using std::endl;

#include <sstream>
using std::istringstream;

namespace
{
  /// \brief Converts a character string into an integer
  /// \returns 0 when the convertion fails
  int parseInt(const string &s)
  {
    istringstream is(s);
    int i = 0;
    is >> i;
    return is.fail() ? 0 : i;
  }

  /// \todo implement isCycleDateValid
  bool isCycleDateValid(const string &cycleDate)
  {
    return false;
  }

  /// \todo implement isDateValid
  bool isDateValid(const string &date)
  {
    return false;
  }

  /// \todo implement isTimeValid
  bool isTimeValid(const string &time)
  {
    return false;
  }

  /// \todo implement isBlank
  bool isBlank(const string &s)
  {
    return false;
  }
} // namespace
namespace Arinc424
{
  File::File()
      : status(-1),
        inputFormat(UnknownFormat),
        outputFormat(UnknownFormat),
        logStream(&clog),
        numRecords(0),
        numIncorrectRecords(0),
        numStandardRecords(0),
        numTailoredRecords(0),
        numHeaderRecords(0)
  {
  }

  File::~File()
  {
  }

  // Extraction operator
  istream &operator>>(istream &is, File &file)
  {
    // Start by assuming a fixed length
    file.inputFormat = File::Format::FixedLengthFormat;

    // If the file loads successfully, we're good !!
    if (file.load(is)) return is;

    // Attempt to rewind the stream ...
    is.seekg(0);
    if (!is.good()) return is;

    // ... and try an XML format
    file.inputFormat = File::Format::XmlFormat;
    if (file.load(is)) return is;

    // Apparently, the input stream has an unsupported format
    file.inputFormat = File::Format::UnknownFormat;
    return is;
  }

  std::ostream &operator<<(std::ostream &os, File::LogCodes code)
  {
    switch (code)
    {
    case File::LogCodes::Error:
      return os << "Error";

    case File::LogCodes::Warning:
      return os << "Warning";

    default:
      return os << int(code);
    }
  }

  bool File::ok() const
  {
    return status == 0;
  }

  bool File::empty() const
  {
    return status == -1;
  }

  bool File::load(istream &is)
  {
    switch(inputFormat)
    {
      case Format::FixedLengthFormat:
        return loadFromFixedLenght(is);

      case Format::XmlFormat:
        return loadFromXmlFormat(is);

      case Format::UnknownFormat:
      default:
        log(Error) << "Cannot load the Arinc424::File object from an unknown input stream" << endl;
        return false;
    }
  }

  bool File::loadFromFixedLenght(istream &is)
  {
    while (is.good())
    {
      // A line is a null-terminated string of 132 characters
      char line[133] = {0};

      // A line from the stream is 132 characters plus the End-Of-Line (EOL) delimiter
      is.getline(line, 133);

      // Check how many characters were actually read
      if (is.gcount() == 133)
      {
        if (!processRecord(line))
        {
          ++numIncorrectRecords;
        }
      }
      else
      {
        // We've asked for 133 characters but we got something else; it's an error ...
        // ... unless it's the end of the stream.
        if (!is.eof())
        {
          log(Error) << "Unexpected number of characters on line " << numRecords << ": " << is.gcount() << endl;
          break;
        }
        
      }
      
    }

    // We succeeded if we have reached the end of the stream, otherwise we failed.
    status = is.eof() ? 0 : 1;

    return ok();
  }

  /// \todo Implement loadFromXmlFormat()
  bool File::loadFromXmlFormat(istream &is)
  {
    return false;
  }

  bool File::processRecord(const char line[])
  {
    // Each line is a record
    string record(line);
    ++numRecords;

    // Determine the type of record?
    switch (record[0])
    {
      case 'S':
        return processStandardRecord(record);

      case 'T':
        return processTailoredRecord(record);

      default:
      {
        // It might be a header record ?
        if (record.substr(0, 3) == "HDR")
        {
          return processHeaderRecord(record);
        }
        else
        {
          log(Warning) << "Unrecognized ARINC-424 Supplement 22 record: '" << record << '\'' << endl;
          unknownRecordList.push_back(record);
        }
      }
    }
    return false;
  }

  /// \todo Implement processStandardRecord
  bool File::processStandardRecord(const string &record)
  {
    ++numStandardRecords;
    return false;
  }

  /// \todo Implement processTailoredRecord
  bool File::processTailoredRecord(const string &record)
  {
    ++numTailoredRecords;
    return false;
  }

  bool File::processHeaderRecord(const string &record)
  {
    ++numHeaderRecords;
    
    // The header number is located in column 4 and 5
    int headerNumber = parseInt(record.substr(3, 2));

    // Supplement 22 defines only header 01 and 02 but allows additional headers from 03 to 99
    switch (headerNumber)
    {
      case 1:
        return processHeader01(record);

      case 2:
        return processHeader02(record);

      default:
        if (headerNumber > 2 && headerNumber < 100)
        {
          header.additionalRecords.push_back(record);
          return true;
        }
        else
        {
          log(Error) << "Invalid header number: '" << record.substr(3, 2) << '\'' << endl;
        }
        
    }

    return false;
  }

  bool File::processHeader01(const std::string &record)
  {
    bool valid = true;

    header.filename = record.substr(5, 15);
    header.versionNumber = parseInt(record.substr(20, 3));
    valid &= header.versionNumber > 0 && header.versionNumber < 1000;
    header.isProduction = record[23] == 'P';
    valid &= !header.isProduction && record[23] == 'T';
    header.recordLength = parseInt(record.substr(24, 4));
    valid &= header.recordLength == 132;
    header.recordCount = parseInt(record.substr(28, 7));
    valid &= header.recordCount > 0 && header.recordCount < 10000000;
    header.cycleDate = record.substr(35, 4);
    valid &= isCycleDateValid(header.cycleDate);
    valid &= record[39] == ' ';
    header.creationDate = record.substr(41, 11);
    valid &= isDateValid(header.creationDate);
    header.creationTime = record.substr(52, 8);
    valid &= isTimeValid(header.creationTime);
    valid &= record[60] == ' ';
    header.dataSupplierIdent = record.substr(61,16);
    valid &= !isBlank(header.dataSupplierIdent);
    header.targetCustomerIdent = record.substr(77, 16);
    header.databasePartNumber = record.substr(93, 20);
    valid &= isBlank(record.substr(113, 11));
    header.fileCrc = parseInt(record.substr(124, 8));
    valid &= header.fileCrc > 0 && header.fileCrc < 100000000;

    return valid;
  }

  /// \todo implement processHeader02
  bool File::processHeader02(const std::string &record)
  {
    bool valid = true;

    header.effectiveDate = record.substr(5, 11);
    valid &= isDateValid(header.effectiveDate) || isBlank(header.effectiveDate);
    header.expirationDate = record.substr(16, 11);
    valid &= isDateValid(header.expirationDate) || isBlank(header.expirationDate);
    valid &= record[27] == ' ';
    header.supplierTextField = record.substr(28, 30);
    header.descriptiveText = record.substr(58, 30);
    valid &= isBlank(record.substr(88, 44));

    return valid;
  }

} // namespace Arinc424
