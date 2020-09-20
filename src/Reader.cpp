#include "Reader.h"
using namespace Arinc424;

// Default Constructor
Reader::Reader()
{
  // Nothing special
}

// Destructor
Reader::~Reader()
{
  // Nothing special
}

// Opens the file, detects the format, loads its contents, and then closes it.
bool Reader::load(const char *file)
{
  if (file == nullptr)
  {
    return false;
  }

  return false;
}
