#include "File.h"
#include "Records/Ports.h"
using namespace Arinc424;

#include <cctype>
using std::isdigit;

#include <iostream>
using std::istream;
using std::ostream;
using std::clog;
using std::endl;

#include <sstream>
using std::istringstream;

#include <string>
using std::string;

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

  /// Section 5.32 defines the cycle date as 2 digits representing
  /// the year followed by 2 digits for the cycle number.
  bool isCycleDateValid(const string &cycleDate)
  {
    return cycleDate.length() == 4 &&
           isdigit(cycleDate[0]) && isdigit(cycleDate[1]) && isdigit(cycleDate[2]) && isdigit(cycleDate[3]) &&
           ((cycleDate[2] == '0' && cycleDate[3] != '0') || (cycleDate[2] == '1' && cycleDate[3] <= '4'));
  }

  /// Format is DD-MMM-YYYY
  bool isDateValid(const string &date)
  {
    clog << "Function '" << __PRETTY_FUNCTION__ << "' is not implemented yet." << endl;
    return false;
  }

  /// \todo implement isTimeValid
  bool isTimeValid(const string &time)
  {
    clog << "Function '" << __PRETTY_FUNCTION__ << "' is not implemented yet." << endl;
    return false;
  }

  /// \todo implement isBlank
  bool isBlank(const string &s)
  {
    clog << "Function '" << __PRETTY_FUNCTION__ << "' is not implemented yet." << endl;
    return false;
  }
}

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

  /// \todo It makes sense to allow the operator to be used multiple times on the same File object.
  /// \todo Multiple use of the extraction operator would permit the incremental build of the File object.
  /// \todo is1 >> file; is2 >> file; ...
  istream &operator>>(istream &is, File &file)
  {
    // Start by assuming a fixed length
    file.inputFormat = file.outputFormat = File::Format::FixedLengthFormat;

    // If the file loads successfully, we're good !!
    if (file.load(is)) return is;

    // Attempt to rewind the stream ...
    is.seekg(0);
    if (!is.good()) return is;

    // ... and try an XML format
    file.inputFormat = file.outputFormat = File::Format::XmlFormat;
    if (file.load(is)) return is;

    // Apparently, the input stream has an unsupported format
    file.inputFormat = file.outputFormat = File::Format::UnknownFormat;
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

  /// \todo The semantic is not well-defined.
  /// \todo The confusion comes from reading an empty stream; should the file be considered empty ?
  /// \todo Should the meaning of empty be related to the input stream that was used to build the object ? Or should it be solely defined by the content of the File object ?
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
        log(Error) << "Cannot load an Arinc424::File object from an input stream when the input format is unknown." << endl;
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

    const char &section = record[4];
    switch (section)
    {
      case 'A':
      case 'D':
      case 'E':
      case 'H':
        log(Error) << "Section '" << section << "' not decoded yet." << endl;
        break;

      case 'P': return processAirportSection(record);

      case 'R':
      case 'T':
      case 'U':
        log(Error) << "Section '" << section << "' not decoded yet." << endl;
        break;

      default:
        log(Error) << "Unrecognized Section Code '" << section << '\'' << endl;
        break;
     }

    return false;
  }

  /// Airport records divided into several subsections
  bool File::processAirportSection(const string &record)
  {
    const char &subsection = record[12];
    switch (subsection)
    {
      case 'A': return processAirportRecord(record);
      case 'B':
      case 'C':
      case 'D':
      case 'E':
      case 'F':
      case 'G':
      case 'H':
      case 'I':
      case 'K':
      case 'L':
      case 'M':
      case 'N':
      case 'P':
      case 'Q':
      case 'R':
      case 'S':
      case 'T':
      case 'V':
        log(Error) << "Airport Subsection '" << subsection << "' not decoded yet." << endl;
        break;

      default:
        log(Error) << "Unrecognized Subsection Code '" << subsection << '\'' << endl;
    }

    return false;
  }

  /// PA records
  bool File::processAirportRecord(const string &record)
  {
    Record::Airport airport;

    bool success = decodeAirportRecord(record, airport);

    if (success)
    {
      aeroPublication.airports.push_back(airport);
    }

    return success;
  }

  ///
  bool File::decodeAirportRecord(const string &record, Record::Airport &airport)
  {
    log(Error) << "Method '" << __PRETTY_FUNCTION__ << "' is not implemented yet." << endl;
    return false;
  }

  /// \todo Implement processTailoredRecord
  bool File::processTailoredRecord(const string &record)
  {
    ++numTailoredRecords;
    log(Error) << "Method '" << __PRETTY_FUNCTION__ << "' is not implemented yet." << endl;
    return true;
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

    // Field #3: File Name
    header.filename = record.substr(5, 15);

    // Field #4: Version Number
    header.versionNumber = parseInt(record.substr(20, 3));
    valid &= header.versionNumber > 0 && header.versionNumber < 1000;

    // Field #5: Production/Test Flag
    header.isProduction = record[23] == 'P';
    valid &= record[23] == 'P' || record[23] == 'T';

    // Field #6: Record Length
    header.recordLength = parseInt(record.substr(24, 4));
    valid &= header.recordLength == 132;

    // Field #7: Record Count
    header.recordCount = parseInt(record.substr(28, 7));
    valid &= header.recordCount > 0 && header.recordCount < 10000000;

    // Field #8: Cycle Date
    header.cycleDate = record.substr(35, 4);
    valid &= isCycleDateValid(header.cycleDate);

    // Field #9: Blank (spacing)
    valid &= record[39] == ' ';

    // Field #10: Creation Date
    header.creationDate = record.substr(41, 11);
    valid &= isDateValid(header.creationDate);

    // Field #11: Creation Time
    header.creationTime = record.substr(52, 8);
    valid &= isTimeValid(header.creationTime);

    // Field #12: Blank (spacing)
    valid &= record[60] == ' ';

    // Field #13: Data Supplier Ident
    header.dataSupplierIdent = record.substr(61,16);
    valid &= !isBlank(header.dataSupplierIdent);

    // Field #14: Target Customer Ident (optional)
    header.targetCustomerIdent = record.substr(77, 16);

    // Field #15: Database Part Number (optional)
    header.databasePartNumber = record.substr(93, 20);

    // Field #16: Reserved (blank)
    valid &= isBlank(record.substr(113, 11));

    // Field #17: File CRC
    header.fileCrc = parseInt(record.substr(124, 8));
    valid &= header.fileCrc > 0 && header.fileCrc < 100000000;

    return valid;
  }

  bool File::processHeader02(const std::string &record)
  {
    bool valid = true;

    // Field #3: Effective Date (optional)
    header.effectiveDate = record.substr(5, 11);
    valid &= isDateValid(header.effectiveDate) || isBlank(header.effectiveDate);

    // Field #4: Expiration Date (optional)
    header.expirationDate = record.substr(16, 11);
    valid &= isDateValid(header.expirationDate) || isBlank(header.expirationDate);

    // Field #5: Blank (spacing)
    valid &= record[27] == ' ';

    // Field #6: Supplier Text (optional)
    header.supplierTextField = record.substr(28, 30);

    // Field #7: Descriptive Text (optional)
    header.descriptiveText = record.substr(58, 30);

    // Field #8: Reserved (blank)
    valid &= isBlank(record.substr(88, 44));

    return valid;
  }

}
