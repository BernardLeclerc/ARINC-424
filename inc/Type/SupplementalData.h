#pragma once

#include <string>

namespace Arinc424
{
  namespace Type
  {
    class SupplementalData
    {
      public:
        SupplementalData()
        :
          pData(nullptr)
        {
        }

        virtual ~SupplementalData()
        {
          delete pData;
          pData = nullptr;
        }

      private:
        std::string *pData;
    };
  }
}