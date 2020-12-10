#include "Types/DataTypes.h"

using namespace Arinc424::Type;

Alpha::Alpha() {}
Alpha::~Alpha() {}

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

CustAreaCode::CustAreaCode() {}
CustAreaCode::~CustAreaCode() {}

Latitude::Latitude() {}
Latitude::~Latitude() {}

Location::Location() {}
Location::~Location() {}

Longitude::Longitude() {}
Longitude::~Longitude() {}

MagneticVariation::MagneticVariation()
{
}

MagneticVariation::~MagneticVariation()
{
}

TimeZone::TimeZone()
{
}

TimeZone::~TimeZone()
{
}