#pragma once

#include "Type/SupplementalData.h"

namespace Arinc424
{
  namespace Record
  {
    class Base
    {
      public:
        Base();
        virtual ~Base();

        SupplementalData *getSupplementalData();
        void setSupplementalData(SupplementalData *pSupplementalData);

      private:
        SupplementalData *pSupplementalData;
    };
  }
}