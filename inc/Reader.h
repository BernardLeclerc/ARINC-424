#pragma once

#include "File.h"

#include <istream>

namespace Arinc424
{
  /// The Arinc424::Reader is the main class to access an
  /// ARINC-424 file in either the fixed length or XML format.
  class Reader
  {
    public:
      Reader();
      ~Reader();

      /// The two load() methods provide the mean to parse a file or a stream
      /// into a useful Arinc424::File object.
      /// \brief Loads an Arinc424::File from a named file.
      /// \details Opens the file by constructing an input stream and, if successful, calls the second Reader::load method.
      /// \returns True if the internal File object has been loaded successfully; false otherwise.
      bool load(const char *file);

      /// \brief  Loads an Arinc424::File from an input stream.
      /// \returns True if the internal File object has been loaded successfully; false otherwise.
      bool load(std::istream &is);

      /// If the input file or stream has been loaded successfully,
      /// the internal Arinc424::File object contains useful data.
      /// \returns A (non-const) reference to the internal File object.
      File &getFile()
      {
        return file;
      }

    private:
      File file;
  };
}
