#include "Header.h"
using namespace Arinc424;

Header::Header()
    : versionNumber(0),
      recordLength(0),
      recordCount(0),
      fileCrc(0),
      isProduction(false)
{
}

Header::~Header()
{
}
