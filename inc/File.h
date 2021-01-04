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

      /// \returns True if no file or input stream has been processed yet; false otherwise.
      bool empty() const;

      /// \returns True if the input stream has been parsed successfully; false otherwise.
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

      /// To determine what input format has been detected and what output format will be used.
      enum Format
      {
        UnknownFormat,
        FixedLengthFormat,
        XmlFormat
      };

      /// \returns The input format that has been detected
      Format getInputFormat() const
      {
        return inputFormat;
      }

      /// \returns The output format that has been detected
      Format getOutputFormat() const
      {
        return outputFormat;
      }

      /// \todo Not defined yet
      bool setOutputFormat(Format format);

      friend std::istream &operator>>(std::istream &is, File &file);
      friend std::ostream &operator<<(std::ostream &os, File &file);

    private:
      /// \brief Uses the indicated format to build the File object from the input stream.
      /// \details load is a wrapper for loadFromXmlFormat and loadFromFixedLenght.
      /// \return true if the File object was successfully loaded; false otherwise.
      bool load(std::istream &is);

      /// \brief Loads the File object from an XML input stream.
      /// \return true if the File object was successfully loaded; false otherwise.
      bool loadFromXmlFormat(std::istream &is);

      /// \brief Loads the File object from a 132-character fixed length input stream.
      /// \return true if the File object was successfully loaded; false otherwise.
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

      enum LogCodes
      {
        Error,
        Warning
      };

      friend std::ostream &operator<<(std::ostream &os, LogCodes code);

      std::ostream &log(LogCodes code)
      {
        return *logStream << code << " - ";
      }
      
    private:
      // The internal status of the File object:
      //  -1 = empty - the object contains no data
      //   0 = successfully loaded - the object contains useful data
      //   1 = unsuccessfully loaded - the object may (or may not) contain data that may (or may not) be useful
      int status;

      // The input format detected be the extraction operator
      Format inputFormat;

      // The output format used by the insertion operator; defaults to the same as the input format
      Format outputFormat;

      // The output stream used to log messages; defaults to std::clog
      std::ostream *logStream;

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

  std::ostream &operator<<(std::ostream &os, File::LogCodes code);
}
