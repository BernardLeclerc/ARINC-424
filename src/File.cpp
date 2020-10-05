#include "File.h"
using namespace Arinc424;

#include <iostream>

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

  std::istream &operator>>(std::istream &is, File &file)
  {
    // Attempt to read exactly 132 characters
    char line[133] = {0};
    is.getline(line, 133);

    // Check how many characters were actually read
    if (is.gcount() == 132)
    {
      // Section 6.2 specifies that "There will be at least one 132-character header record for each data file." a fixed-length format file requires at least one header record.
      // If the input format is indeed a FixedLengthFormat, then the first 3 characters
      // Process As Fixed Lenght Format
      file.inputFormat = File::FixedLengthFormat;
    }
    // Is the stream still in good shape ?
    else if (is.good())
    {
      // Assume an XML format
      file.inputFormat = File::XmlFormat;
    }

    return is;
  }

  bool File::ok() const
  {
    return status == 0;
  }
}
