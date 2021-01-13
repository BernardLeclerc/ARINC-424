#pragma once

#include "Header.h"
#include "Records/AeroPublication.h"
#include <istream>
#include <string>

namespace Arinc424
{
  class FixedLengthParser
  {
    public:
      FixedLengthParser(std::istream &is, Record::AeroPublication &aeroPublication);
      ~FixedLengthParser();

      /// Parses the input stream
      /// \brief Loads the File object from a 132-character fixed length input stream.
      /// \return true if no error occured while reading the input stream; false otherwise.
      bool parse();

      /// \returns The number of fixed-length records extracted from the input stream
      size_t getNumRecords() const
      {
        return numRecords;
      }

      /// \returns The number of fixed-length records that are not properly formatted
      size_t getNumIncorrectRecords() const
      {
        return numIncorrectRecords;
      }

      /// \returns The number of fixed-length header records that are not properly formatted
      size_t getNumHeaderRecords() const
      {
        return numHeaderRecords;
      }

    private:
      /// \brief Processes one line obtained from the input stream.
      /// \details Determines the type of records and then calls the appropriate method.
      /// \returns true if the record is properly formatted; false otherwise.
      bool processRecord(const char line[]);

      /// \brief Processes a standard record
      /// \returns true if the record is properly formatted; false otherwise.
      bool processStandardRecord(const std::string &record);

      /// \brief Processes one P record
      /// \returns true if the record is properly formatted; false otherwise.
      bool processAirportSection(const std::string &record);

      /// \brief Processes one PA record
      /// \returns true if the record is properly formatted; false otherwise.
      bool processAirportRecord(const std::string &record);

      /// \brief Decodes a fixed-length PA record
      /// \returns true if the record is properly formatted; false otherwise.
      bool decodeAirportRecord(const std::string &record, Record::Airport &airport);

      /// \brief Processes a tailored record
      /// \returns true if the record is properly formatted; false otherwise.
      bool processTailoredRecord(const std::string &record);

      /// \brief Processes a header record
      /// \returns true if the record is properly formatted; false otherwise.
      bool processHeaderRecord(const std::string &record);
      bool processHeader01(const std::string &record);
      bool processHeader02(const std::string &record);

    private:
      // The parsing will take place from this input stream.
      std::istream &is;

      // The data from fixed-length records is stored here.
      Record::AeroPublication &aeroPublication;

      // The number of fixed length records (lines) read from the input stream.
      size_t numRecords;

      // The number of records that are not properly formatted.
      size_t numIncorrectRecords;

      // Other counters for debugging and statistics purposes
      size_t numStandardRecords;
      size_t numTailoredRecords;
      size_t numHeaderRecords;

      // List of Unknown records
      std::list<std::string> unknownRecordList;

      // All files have a header
      Header header;
  };
}
