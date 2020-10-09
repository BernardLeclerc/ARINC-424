#pragma once

#include <list>
#include <string>

namespace Arinc424
{
  /// \brief All fields defined in Section 6.2, Header Records
  /// \details A well-formed ARINC-424 Supplement 22 file has at least one header record
  class Header
  {
    public:
      Header() {}
      ~Header() {}

    public:
      std::string filename;             // 15-char
      std::string cycleDate;            //  4-char
      std::string creationDate;         // 11-char
      std::string creationTime;         //  8-char
      std::string dataSupplierIdent;    // 16-char
      std::string targetCustomerIdent;  // 16-char
      std::string databasePartNumber;   // 20-char
      std::string effectiveDate;        // 11-char
      std::string expirationDate;       // 11-char
      std::string supplierTextField;    // 30-char
      std::string descriptiveText;      // 30-char
      size_t versionNumber;             //  3-char, 001 to 999
      size_t recordLength;              //  4-char, must be 0132
      size_t recordCount;               //  7-char, number of data records (without header records)
      unsigned int fileCrc;             //  8-char, 32-bit unsigned integer
      bool isProduction;                //  1-char, P (production) = true, T (test) = false

      std::list<std::string> additionalRecords;
  };
} // namespace Arinc424
