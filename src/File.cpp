#include "File.h"
#include "Logger.h"
#include "FixedLengthParser.h"
using namespace Arinc424;

#include <iostream>
using std::endl;
using std::istream;
using std::ostream;

#include <string>
using std::string;

namespace Arinc424
{
  File::File()
  : status(0),
    inputFormat(Format::Unknown),
    outputFormat(Format::Unknown)
  {
  }

  File::~File()
  {
  }

  /// \todo It makes sense to allow the operator to be used multiple times on the same File object.
  /// \todo Multiple use of the extraction operator would permit the incremental build of the File object.
  /// \todo is1 >> file; is2 >> file; ...
  istream &operator>>(istream &is, File &file)
  {
    switch (file.inputFormat)
    {
      case File::Format::FixedLength:
        file.loadFromFixedLenght(is);
        break;

      case File::Format::Xml:
        file.loadFromXml(is);
        break;

      case File::Format::Unknown:
      default:
        file.load(is);
    }

    return is;
  }

  bool File::ok() const
  {
    return status == 0;
  }

  bool File::empty() const
  {
    return aeroPublication.empty();
  }

  File::Format File::setInputFormat(Format newInputFormat)
  {
    Format previousInputFormat = inputFormat;
    inputFormat = newInputFormat;
    return previousInputFormat;
  }

  bool File::load(istream &is)
  {
    // Start by assuming a fixed length format.
    // If the file loads successfully, we're good !!
    if (loadFromFixedLenght(is))
    {
      log(Logger::Level::Info) << "Fixed-length format detected." << endl;
      inputFormat = outputFormat = Format::FixedLength;
      status = 0;
      return true;
    }

    // Attempt to rewind the stream ...
    is.clear();
    is.seekg(0);
    if (is.fail())
    {
      log(Logger::Level::Error) << "Failed to rewind the input stream." << endl;
      inputFormat = outputFormat = Format::Unknown;
      status = 1;
      return false;
    }

    // ... and try an XML format
    if (loadFromXml(is))
    {
      log(Logger::Level::Info) << "XML format detected." << endl;
      inputFormat = outputFormat = Format::Xml;
      status = 0;
      return true;
    }

    // Apparently, the input stream has an unsupported format
    log(Logger::Level::Error) << "Could not detect the format of the input stream." << endl;
    inputFormat = outputFormat = Format::Unknown;
    status = 1;
    return false;
  }

  bool File::loadFromFixedLenght(istream &is)
  {
    FixedLengthParser parser(is, aeroPublication);
    bool success = parser.parse();
    status = success ? 0 : 1;
    return success;
  }

  /// \todo Implement loadFromXml()
  bool File::loadFromXml(istream &is)
  {
    status = 1;
    return ok();
  }

  ostream &operator<<(ostream &os, File::Format format)
  {
    switch (format)
    {
      case File::Format::FixedLength: return os << "Fixed Length Format";
      case File::Format::Xml:         return os << "XML Format";
      case File::Format::Unknown:
      default:                        return os << "Unknown Format";
    }
  }
}
