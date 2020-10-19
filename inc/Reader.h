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

      /// The two load() functions provide the mean to parse a file or a stream
      /// into a useful Arinc424::File object.
      bool load(const char *file);
      bool load(std::istream &is);

      /// If the input file or stream has been loaded successfully,
      /// the internal Arinc424::File object contains useful data.
      File &getFile()
      {
        return file;
      }

    private:
      File file;
  };
} // namespace Arinc424
