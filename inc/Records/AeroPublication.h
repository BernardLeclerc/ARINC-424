#pragma once

#include "MetaData.h"
#include "Ports.h"
#include <list>

namespace Arinc424
{
  namespace Record
  {
    class AeroPublication
    {
      public:
        AeroPublication();
        ~AeroPublication();

      public:
        std::list<Airport> airports;
        MetaData metaData;
    };
  }
}
