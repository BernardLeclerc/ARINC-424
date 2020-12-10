#pragma once

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

      private:
        std::list<Airport> airports;
    };
  } // namespace Record
} // namespace Arinc424
