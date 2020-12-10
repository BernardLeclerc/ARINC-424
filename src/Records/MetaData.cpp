#include "Records/MetaData.h"

using namespace Arinc424::Record;

MetaData::MetaData()
:
  cycleDate(0),
  fileCRC(0),
  recordCount(0),
  versionNumber(0)
{}

MetaData::~MetaData()
{}
