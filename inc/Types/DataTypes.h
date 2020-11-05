#pragma once

#include "Enumerations.h"

#include <string>

namespace Arinc424
{
  namespace Type
  {
    typedef std::string CoreIdentifier;
    typedef std::string CycleDate;
    typedef std::string CustomerCode;
    typedef std::string NotesText;
    typedef std::string PointReference;

    typedef unsigned int LongestRunway;

    union CustAreaCode
    {
      Enum::AreaCode areaCode;
      CustomerCode customerCode;
    };

    /// \todo Consider defining a class to implement the restriction in the range of valid integers: from -2000 to 99999
    typedef int AltitudeValue;

    class Altitude
    {
      public:
        Altitude();
        virtual ~Altitude();

      private:
        bool isNotDefined;
        bool isUnknown;
        bool isFlightLevel;
        AltitudeValue altitude;
    };

    class AltitudeLimit : public Altitude
    {
      public:
        AltitudeLimit();
        virtual ~AltitudeLimit();

      private:
        bool isGround;
        bool isMSL;
        bool isNotam;
        bool isNotSpecified;
        bool isUnlimited;
    };
  } // namespace Type
} // namespace Arinc424
