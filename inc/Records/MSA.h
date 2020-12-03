#pragma once

#include "BasicClasses.h"
#include <list>

namespace Arinc424
{
  namespace Record
  {
    class MSA : public A424Record
    {
      public:
        MSA();
        virtual ~MSA();

      private:
        Type::CoreIdentifier centerFix;
        Type::IcaoCode icaoCode;
        Enum::MagneticTrueIndicator magneticTrueIndicator;
        Type::MultipleCode multipleCode;
        std::list<Type::Sector> sector;
        Type::PointReference centerFixRef;
        xs::ID referenceID;
    };
  }
}