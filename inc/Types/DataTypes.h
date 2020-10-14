#pragma once

namespace Arinc424
{
  namespace Type
  {
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
