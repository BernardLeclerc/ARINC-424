#include "Records/Base.h"

using namespace Arinc424::Record;
using namespace Arinc424::Type;

Base::Base()
:
  pSupplementalData(nullptr)
{
}

Base::~Base()
{
  delete pSupplementalData;
  pSupplementalData = nullptr;
}

SupplementalData *Base::getSupplementalData()
{
  return pSupplementalData;
}

void Base::setSupplementalData(SupplementalData *pData)
{
  pSupplementalData = pData;
}
