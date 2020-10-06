#include "File.h"
using namespace Arinc424;

#include <iostream>
using std::clog;
using std::endl;

namespace Arinc424
{
  File::File()
      : status(0),
        inputFormat(UnknownFormat),
        outputFormat(UnknownFormat),
        log(&std::clog)
  {
  }

  File::~File()
  {
  }

  // Extraction operator
  std::istream &operator>>(std::istream &is, File &file)
  {
    // Start by assuming a fixed length
    file.inputFormat = File::Format::FixedLengthFormat;

    // If the file loads successfully, we're good !!
    if (file.load(is)) return is;

    // Attempt to rewind the stream ...
    is.seekg(0);
    if (!is.good()) return is;

    // ... and try an XML format
    file.inputFormat = File::Format::XmlFormat;
    file.load(is);

    return is;
  }

  bool File::ok() const
  {
    return status == 0;
  }

  bool File::load(std::istream &is)
  {
    switch(inputFormat)
    {
      case Format::FixedLengthFormat:
        return loadFromFixedLenght(is);

      case Format::XmlFormat:
        return loadFromXmlFormat(is);

      case Format::UnknownFormat:
      default:
        *log << "Cannot load the Arinc424::File object from an unknown input stream" << endl;
        return false;
    }
  }

  bool File::loadFromFixedLenght(std::istream &is)
  {
    while (!is.eof())
    {
      // A line is a null-terminated string of 132 characters
      char line[133] = {0};

      // Attempt to read exactly 132 characters
      is.getline(line, 133);

      // Check how many characters were actually read
      if (is.gcount() == 132)
      {
        process(line);
      }
    }

    return false;
  }

  /// \todo Implement loadFromXmlFormat()
  bool File::loadFromXmlFormat(std::istream &is)
  {
    return false;
  }

  /// \todo Implement process()
  bool File::process(const char line[])
  {
    return false;
  }
} // namespace Arinc424
