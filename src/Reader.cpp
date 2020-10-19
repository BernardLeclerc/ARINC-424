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

// Opens the file and, if successful, loads its contents.
bool Reader::load(const char *file)
{
  if (file == nullptr)
  {
    return false;
  }

  ifstream inputFileStream(file);
  return inputFileStream.good() ? load(inputFileStream) : false;
}

// Uses the extraction operator to load the content of the input stream into the internal File object.
bool Reader::load(std::istream &is)
{
  is >> file;
  return file.ok();
}
