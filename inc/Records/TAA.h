#pragma once

#include "BasicClasses.h"

#include "../xs.h"

#include <list>

namespace Arinc424
{
  namespace Record
  {
    class TAA : public A424Record
    {
      public:
        TAA();
        virtual ~TAA();

      private:
        std::list<Type::ApproachTypeIdentifier> approachTypeIdentifier;
        Enum::MagneticTrueIndicator magneticTrueIndicator;
        Enum::TAASectorIdentifier taaFixPositionIndicator;
        std::list<Type::TAASectorDetails> sectorTAADetails;
        Type::PointReference taaIAFWaypointReference;
        xs::IDREF sectorBearingWaypointRef;
        xs::ID referenceID;
    };
  }
}