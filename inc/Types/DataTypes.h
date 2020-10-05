#pragma once

namespace Arinc424
{
  namespace Type
  {
    typedef int AltitudeValue;

    class Altitude
    {
      public:
        Altitude()
        :
          isNotDefined(true),
          isUnknown(false),
          isFlightLevel(false)
        {}
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
      AltitudeLimit()
          : Altitude(),
            isGround(false),
            isMSL(false),
            isNotam(false),
            isNotSpecified(true),
            isUnlimited(false)
      {
      }

    private:
      bool isGround;
      bool isMSL;
      bool isNotam;
      bool isNotSpecified;
      bool isUnlimited;
    };
  } // namespace Type
} // namespace Arinc424
