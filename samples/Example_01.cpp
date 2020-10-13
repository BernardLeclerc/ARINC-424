#include "Arinc424.h"

#include <iostream>
using std::cout;
using std::cerr;
using std::endl;

#include <fstream>
using std::ifstream;

int main(int argc, char *argv[])
{
  cout << "Example #1: How to read an ARINC-424 file using the C++ Extraction Operator" << endl;

  // Make sure that exactly one argument is provided
  if (argc != 2)
  {
    cerr << "Usage: " << argv[0] << " 'file'" << endl;
    cerr << "Where 'file' is the name of your ARINC-424 data file (fixed length or XML format)" << endl;
    return 1;
  }

  cout << "Loading '" << argv[1] << '\'' << endl;

  // Step 1: Open the ARINC-424 file
  ifstream inputFile(argv[1]);
  if (inputFile.fail())
  {
    cerr << "Error - Failed to open the file!" << endl;
    return 1;
  }

  // Step 2: Create ARINC-424 Object that will receive the file
  Arinc424::File arinc424File;

  // By default, the Arinc424::File object detects the format of the input file by first 
  // trying to parse it as a 132-character fixed lenght text file. If this first attempt
  // fails, a second attempt is made assuming the input is an XML file.
  inputFile >> arinc424File;

  // At this point, the input file should have been read completely.
  // If it's not the case, we can assume that the input file is damaged.
  if (!inputFile.eof())
  {
    cout << "Warning - EOF not reached. Data is most likely incomplete." << endl;
  }
  
  //Step 3: The input file has been read completely, but was the parsing successful ?
  if (!arinc424File.ok())
  {
    // By default, the Arinc424::File object will print warning and error messages while
    // parsing the input file. These messages explain why the parsing failed and what is
    // wrong with the input file.
    cerr << "The ARINC-424 file wasn't parsed correctly." << endl;
    return 1;
  }

  // You can now process the data that is contained in the Arinc424::File object :-)
  cout << "Load succeeded" << endl;

  return 0;
}
