#pragma once

#include "Types/SupplementalData.h"

namespace Arinc424
{
  namespace Record
  {
    class Base
    {
      public:
        Base();
        virtual ~Base();

        Type::SupplementalData *getSupplementalData();
        void setSupplementalData(Type::SupplementalData *pSupplementalData);

      private:
        Type::SupplementalData *pSupplementalData;
    };
  }
}