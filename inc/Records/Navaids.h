#pragma once

#include "BasicClasses.h"

#include "../Types/DataTypes.h"
#include "../Types/Enumerations.h"

namespace Arinc424
{
  namespace Record
  {
    ///
    class Navaid : public A424Point
    {
      public:
        Navaid();
        virtual ~Navaid();

      private:
        Type::PointReference portRef; ///< Defines the location of a designated point using a combination of angles and distances based on the guidance service. The set of angles and distances must not under specify the location.
        Type::Elevation elevation;    ///< Elevation of the navaid location in feet.
    };

    ///
    class NDB : public Navaid
    {
      public:
        NDB();
        virtual ~NDB();

      private:
        Type::NdbNavaidClass ndbClass;
        Type::Frequency ndbFrequency;
        Enum::TypeOfEmission typeOfEmission;
        Type::RepetitionRate repetitionRate;
        Enum::NavaidNDBEmissionType navaidNdbEmissionType;
        Type::PointReference dmeRef; ///< This field identifies a reference to a DME navaid which originated in the same source data record as the NDB (i.e. is paired with the NDB)
    };

    /// This following record contains the fields used in NDB NAVAID Primary Records Record
    class TerminalNDB : public NDB
    {
      public:
        TerminalNDB();
        virtual ~TerminalNDB();

      private:
        
    };
  }
}