#pragma once

#include "Header.h"
#include "Records/AeroPublication.h"

#include <istream>
#include <ostream>
#include <list>
#include <string>

namespace Arinc424
{
  class File
  {
    public:
      File();
      ~File();

      /// \returns True when aeroPublication is empty.
      bool empty() const;

      /// \returns True if the last operation on a stream was successful; false otherwise.
      bool ok() const;

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

      /// To determine what input format has been set or detected and what output format will be used.
      enum class Format
      {
        Unknown,
        FixedLength,
        Xml
      };

      /// \returns The input format that has been detected by the last call to the extraction (>>) operator.
      /// The initial input format is Format::Unknown.
      /// \see setInputFormat().
      Format getInputFormat() const
      {
        return inputFormat;
      }

      /// \todo Not defined yet
      /// \returns The previous input format
      Format setInputFormat(Format format);

      /// \returns The output format that has been set
      /// By default, the output format is set to the same value as the input format that is detected.
      /// If the input format is explicitly set, the output format is left unchanged; that is, it keeps its current value.
      /// The initial output format is Format::Unknown.
      Format getOutputFormat() const
      {
        return outputFormat;
      }

      /// \todo Not defined yet
      /// \returns The previous output format
      Format setOutputFormat(Format format);

      friend std::istream &operator>>(std::istream &is, File &file);
      friend std::ostream &operator<<(std::ostream &os, File &file);

    private:
      /// \brief Loads the File object from an input stream whose format is unknown.
      /// \details First tries a fixed-length format then, if it fails, tries an XML format.
      /// \returns true if no error occured while reading the input stream; false otherwise.
      bool load(std::istream &is);

      /// \brief Loads the File object from an XML input stream.
      /// \returns true if no error occured while reading the input stream; false otherwise.
      bool loadFromXml(std::istream& is);

      /// \brief Loads the File object from a 132-character fixed length input stream.
      /// \return true if no error occured while reading the input stream; false otherwise.
      bool loadFromFixedLenght(std::istream &is);

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
      /// The status of the last operation on the File object through the insertion or extraction operators
      ///   0 = last operation succeeded
      ///   1 = last operation failed
      int status;

      // The input format detected be the extraction operator
      Format inputFormat;

      // The output format used by the insertion operator; defaults to the same as the input format
      Format outputFormat;

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

      /// This is the actual data once read from the source stream.
      Record::AeroPublication aeroPublication;
  };

  /// This extraction operator reads an ARINC-424 file from a standard input stream,
  /// parses its content, and stores the result into the specified Arinc424::File object.
  /// By default, the operator detects the input stream format by first trying a
  /// 132-character fixed length format, and - in case of failure - by assuming an XML
  /// input stream.
  std::istream &operator>>(std::istream &is, File &file);

  /// This insertion operator writes an Arinc424::File to a standard output stream.
  /// The output format is controlled by the state of the File object.
  std::ostream &operator<<(std::ostream &os, File &file);
}
