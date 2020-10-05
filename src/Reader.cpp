#include "Reader.h"
#include "File.h"
using namespace Arinc424;

#include <fstream>
using std::istream;
using std::ifstream;

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

  ifstream inputFileStream(file);
  return inputFileStream.good() ? load(inputFileStream) : false;
}

bool Reader::load(istream &is)
{
  is >> file;
  return file.ok();
}