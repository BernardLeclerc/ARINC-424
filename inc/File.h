#pragma once

#include "Header.h"

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

      // True if no file or input stream has been processed yet
      bool empty() const;

      // True if the input stream has been parsed successfully; false otherwise.
      bool ok() const;

      // To determine what input format has been detected and what output format will be used.
      enum Format
      {
        UnknownFormat,
        FixedLengthFormat,
        XmlFormat
      };

      Format getInputFormat() const;
      bool setOutputFormat(Format format);

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

      friend std::istream &operator>>(std::istream &is, File &file);
      friend std::ostream &operator<<(std::ostream &os, File &file);

    private:
      /// \brief Processes one line obtained from the input stream.
      /// \details Determines the type of records and then calls the appropriate method.
      /// \returns true if the record is properly formatted; false otherwise.
      bool processRecord(const char line[]);

      /// \brief Processes a standard record
      /// \returns true if the record is properly formatted; false otherwise.
      bool processStandardRecord(const std::string &record);

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
      int status;

      // The input format detected be the extraction operator
      Format inputFormat;

      // The output format used by the insertion operator; defaults to the same as the input format
      Format outputFormat;

      // The output stream used to log messages; defaults to std::clog
      std::ostream *logStream;

      // The number of fixed length records (lines) read from the input stream.
      size_t numRecords;

      // List of Unknown records
      std::list<std::string> unknownRecordList;

      // All files have a header
      Header header;
  };

  /// This extraction operator reads an ARINC-424 file from a standard input stream,
  /// parses its content, and stores the resul into the specified Arinc424::File object.
  /// By default, the operator detects the input stream format by first trying a
  /// 132-character fixed length format, and - in case of failure - by assuming an XML
  /// input stream.
  std::istream &operator>>(std::istream &is, File &file);

  /// This insertion operator writes an Arinc424::File to a standard output stream.
  /// The format is controlled by the state of the File object.
  std::ostream &operator<<(std::ostream &os, File &file);

  std::ostream &operator<<(std::ostream &os, File::LogCodes code);

} // namespace Arinc424
