#include "Record/Base.h"

using namespace Arinc424::Record;

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

void Base::setSupplementalData(SupplementalData *pSupplementalData)
{
  pSupplementalData = pData;
}
