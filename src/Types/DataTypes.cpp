#include "Types/DataTypes.h"

using namespace Arinc424::Type;

Altitude::Altitude()
    : isNotDefined(true),
      isUnknown(false),
      isFlightLevel(false),
      altitude(0)
{
}

Altitude::~Altitude()
{
}

AltitudeLimit::AltitudeLimit()
    : Altitude(),
      isGround(false),
      isMSL(false),
      isNotam(false),
      isNotSpecified(true),
      isUnlimited(false)
{
}

AltitudeLimit::~AltitudeLimit()
{
}
