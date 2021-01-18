#include "FixedLengthParser.h"
#include "Header.h"
#include "Logger.h"
using namespace Arinc424;

#include <cctype>
using std::isdigit;

#include <iostream>
using std::istream;
using std::clog;
using std::endl;

#include <sstream>
using std::istringstream;

#include <string>
using std::string;

namespace
{
  // Converts a character string into an integer
  // Returns 0 if the convertion fails
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

  /// Section 6.2.1 defines the date format: DD-MMM-YYYY
  bool isMonthValid(const string &month)
  {
    return
      month == "JAN" || month == "FEB" || month == "MAR" || month == "APR" ||
      month == "MAY" || month == "JUN" || month == "JUL" || month == "AUG" ||
      month == "SEP" || month == "OCT" || month == "NOV" || month == "DEC";
  }

  bool isDateValid(const string &date)
  {
    return
      date.length() == 11 &&
      isdigit(date[0]) && isdigit(date[1]) &&
      date[2] == '-' &&
      isMonthValid(date.substr(3, 3)) &&
      date[6] == '-' &&
      isdigit(date[7]) && isdigit(date[8]) && isdigit(date[9]) && isdigit(date[10]);
  }

  /// Section 6.2.1 defines the time format: hh:mm:ss
  bool isTimeValid(const string &time)
  {
    return
      time.length() == 8 &&
      isdigit(time[0]) && isdigit(time[1]) &&
      time[2] == ':' &&
      isdigit(time[3]) && isdigit(time[4]) &&
      time[5] == ':' &&
      isdigit(time[6]) && isdigit(time[7]);
  }

  /// Return true if the string is not empty and contains only blank characters
  bool isBlank(const string &s)
  {
    return !s.empty() && s.find_first_not_of(' ') == string::npos;
  }

  // Returns true if the fields from column 1 thru 21 of the raw record correspond to the data stored in the provided airport record.
  bool areFieldsAsOnAirportPrimaryRecord(const string &record, const Record::Airport &airport)
  {
    return
      airport.recordType == Enum::getRecordType(record[0]) &&
      airport.custAreaCode == Type::CustAreaCode(record.substr(1, 3)) &&
      record[4] == 'P' &&
      record[5] == ' ' &&
      airport.identifier == record.substr(6, 4) &&
      airport.icaoCode == record.substr(10, 2) &&
      record[12] == 'A' &&
      airport.ataIATADesignator == record.substr(13, 3) &&
      isBlank(record.substr(18, 3));
  }

  // Returns true if the Continuation Record Number is in the set [0-9] or [A-Z]
  bool isValidContinuationRecordNumber(const char continuationRecordNumber)
  {
    return
      (continuationRecordNumber >= '0' && continuationRecordNumber <= '9') ||
      (continuationRecordNumber >= 'A' && continuationRecordNumber <= 'Z');
  }

  // Returns true if the continuation record number identifies a primary record
  bool isPrimaryRecordNumber(const char continuationRecordNumber)
  {
    return continuationRecordNumber == '0' || continuationRecordNumber == '1';
  }
}

FixedLengthParser::FixedLengthParser(istream &is, Record::AeroPublication &aeroPublication)
: is(is),
  aeroPublication(aeroPublication),
  numRecords(0),
  numIncorrectRecords(0),
  numStandardRecords(0),
  numTailoredRecords(0),
  numHeaderRecords(0)
{}

FixedLengthParser::~FixedLengthParser()
{}

bool FixedLengthParser::parse()
{
  size_t lineNo = 0;

  while (is.good())
  {
    // A line is a null-terminated string of 132 characters
    char line[133] = { 0 };

    // A line from the stream is 132 characters plus the End-Of-Line (EOL) delimiter
    is.getline(line, 133);
    ++lineNo;

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
        if (is.gcount() == 132)
        {
          log(Logger::Level::Error) << "Line " << lineNo << " has no EOL or exceeds 132 characters." << endl;
        }
        else
        {
          log(Logger::Level::Error) << "Line " << lineNo << " is too short: " << is.gcount() << endl;
        }
        break;
      }
    }
  }

  return is.eof();
}

bool FixedLengthParser::processRecord(const char line[])
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
        log(Logger::Level::Warning) << "Unrecognized ARINC-424 Supplement 22 record: '" << record << '\'' << endl;
        unknownRecordList.push_back(record);
      }
    }
  }
  return false;
}

bool FixedLengthParser::processStandardRecord(const string &record)
{
  ++numStandardRecords;

  const char &section = record[4];
  switch (section)
  {
    case 'A':
    case 'D':
    case 'E':
    case 'H':
      log(Logger::Level::Info) << "Section '" << section << "' not decoded yet." << endl;
      break;

    case 'P': return processAirportSection(record);

    case 'R':
    case 'T':
    case 'U':
      log(Logger::Level::Info) << "Section '" << section << "' not decoded yet." << endl;
      break;

    default:
      log(Logger::Level::Error) << "Unrecognized Section Code '" << section << '\'' << endl;
      break;
  }

  return false;
}

/// Airport records divided into several subsections
bool FixedLengthParser::processAirportSection(const string &record)
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
      log(Logger::Level::Info) << "Airport Subsection '" << subsection << "' not decoded yet." << endl;
      break;

    default:
      log(Logger::Level::Error) << "Unrecognized Subsection Code '" << subsection << '\'' << endl;
  }

  return false;
}

/// PA records
bool FixedLengthParser::processAirportRecord(const string &record)
{
  char continuationRecordNumber = record[21];

  // Is this a primary or continuation record?
  if (continuationRecordNumber == '0' || continuationRecordNumber == '1')
  {
    Record::Airport newAirport;
    aeroPublication.airports.push_back(newAirport);
  }
  else if (aeroPublication.airports.empty())
  {
    log(Logger::Level::Error) << "Continuation record found without the corresponding primary record." << endl;
    return false;
  }

  return decodeAirportRecord(record, aeroPublication.airports.back());
}

///
bool FixedLengthParser::decodeAirportRecord(const string &record, Record::Airport &airport)
{
  bool valid = true;

  // Ref: 5.2
  airport.recordType = Enum::getRecordType(record[0]);

  // Ref: 5.3
  switch (airport.recordType)
  {
    case Enum::RecordType::Standard:
      airport.custAreaCode.areaCode = Enum::getAreaCode(record.substr(1, 3));
      airport.custAreaCode.customerCode = record.substr(1, 3);
      valid &= airport.custAreaCode.areaCode != Enum::AreaCode::Undefined;
      break;

    case Enum::RecordType::Tailored:
      airport.custAreaCode.areaCode = Enum::AreaCode::Undefined;
      airport.custAreaCode.customerCode = record.substr(1, 3);
      valid &= !isBlank(airport.custAreaCode.customerCode);
      break;

    default:
      valid = false;
  }

  // Ref: 5.16
  char continuationRecordNumber = record[21];
  valid &= isValidContinuationRecordNumber(continuationRecordNumber);

  if (valid)
  {
    if (isPrimaryRecordNumber(continuationRecordNumber))
    {
      // Ref: 5.6
      airport.identifier = record.substr(6, 4);
      valid &= !isBlank(airport.identifier);

      // Ref: 5.14
      airport.icaoCode = record.substr(10, 2);
      valid &= !isBlank(airport.icaoCode);

      // Ref: 5.107
      airport.ataIATADesignator = record.substr(13, 3);
    }
    else
    {
      // Make sure this is a continuation record of the current airport
      if (areFieldsAsOnAirportPrimaryRecord(record, airport))
      {
        //
      }

      // Error - This otherwise valid continuation record is not related to the previous records.
      else
      {
        log(Logger::Level::Error) << "Not a continuation record of the current airport" << endl;
        log(Logger::Level::Error) << "Current Airport:" << endl;
        log(Logger::Level::Error) << "  Record Type: " << airport.recordType << endl;
        log(Logger::Level::Error) << "  Area/Customer Code: " << airport.custAreaCode << endl;
        log(Logger::Level::Error) << "  Airport ICAO Identifier: " << airport.identifier << endl;
        log(Logger::Level::Error) << "  ICAO Code: " << airport.icaoCode << endl;
        log(Logger::Level::Error) << "  ATA/IATA Designator: " << airport.ataIATADesignator << endl;
        log(Logger::Level::Error) << "First 21 characters of the continuation record: " << record.substr(0, 21) << endl;
        valid = false;
      }
    }

  }
  else
  {
    log(Logger::Level::Error) << "This is not a valid continuation record number: '" << continuationRecordNumber << '\'' << endl;
    log(Logger::Level::Error) << "Valid range is '0' thru '9' and 'A' thru 'Z'." << endl;
  }

  return valid;
}

/// \todo Implement processTailoredRecord
bool FixedLengthParser::processTailoredRecord(const string &record)
{
  ++numTailoredRecords;
  log(Logger::Level::Error) << "Method '" << __PRETTY_FUNCTION__ << "' is not implemented yet." << endl;
  return false;
}

bool FixedLengthParser::processHeaderRecord(const string &record)
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
        log(Logger::Level::Error) << "Invalid header number: '" << record.substr(3, 2) << '\'' << endl;
      }

  }

  return false;
}

bool FixedLengthParser::processHeader01(const string &record)
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
  header.dataSupplierIdent = record.substr(61, 16);
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

bool FixedLengthParser::processHeader02(const string &record)
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
