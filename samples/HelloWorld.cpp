// The simplest complete program using the ARINC-424 library.
#include "Arinc424.h"

#include <iostream>
using std::cout;
using std::cerr;
using std::endl;

int main(int argc, char *argv[])
{
  cout << "Hello ARINC-424 World !!" << endl;

  if (argc != 2)
  {
    cerr << "Usage: " << argv[0] << " 'file'" << endl;
    cerr << "Where 'file' is the name of your ARINC-424 data file (fixed length or XML format)" << endl;
    return 1;
  }

  cout << "Loading '" << argv[1] << '\'' << endl;

  Arinc424::Reader reader;
  bool loadSuccessful = reader.load(argv[1]);

  cout << "Load " << (loadSuccessful ? "succeeded" : "failed") << endl;

  return loadSuccessful ? 0 : 1;
}
