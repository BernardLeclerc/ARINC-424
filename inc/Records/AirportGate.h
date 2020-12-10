#pragma once

#include "BasicClasses.h"

namespace Arinc424
{
  namespace Record
  {
    /// This following record contains the fields used in Airport Gate Record.
    class AirportGate : public A424Point
    {
      public:
        AirportGate();
        virtual ~AirportGate();

      private:
    };
  }
}
