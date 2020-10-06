#pragma once

#include <istream>
#include <ostream>

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

      /// \brief Processes one line obtained from the input stream
      bool process(const char line[]);
      
      friend std::istream &operator>>(std::istream &is, File &file);
      friend std::ostream &operator<<(std::ostream &os, File &file);

    private:
      int status;

      // The input format detected be the extraction operator
      Format inputFormat;

      // The output format used by the insertion operator; defaults to the same as the input format
      Format outputFormat;

      std::ostream *log; // The output stream used to log messages; defaults to std::clog
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

} // namespace Arinc424
