#include "Header.h"
using namespace Arinc424;

#include <iostream>
using std::cout;
using std::endl;

Header::Header()
    : versionNumber(0),
      recordLength(0),
      recordCount(0),
      fileCrc(0),
      isProduction(false)
{
  cout << "Header ctor" << endl;
}

Header::~Header()
{
}
