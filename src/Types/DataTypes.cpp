#include "Types/DataTypes.h"
using namespace Arinc424::Type;

#include <iomanip>
using namespace std;

AdditionalSectorization::AdditionalSectorization() {}
AdditionalSectorization::~AdditionalSectorization() {}

AirportHeliportCommunicationServiceIndicator::AirportHeliportCommunicationServiceIndicator() {}
AirportHeliportCommunicationServiceIndicator::~AirportHeliportCommunicationServiceIndicator() {}

Alpha::Alpha() {}
Alpha::~Alpha() {}

Altitude::Altitude()
    : isNotDefined(true),
      isUnknown(false),
      isFlightLevel(false),
      altitude(0)
{
}

Altitude::~Altitude() {}

AltitudeLimit::AltitudeLimit()
    : Altitude(),
      isGround(false),
      isMSL(false),
      isNotam(false),
      isNotSpecified(true),
      isUnlimited(false)
{
}

AltitudeLimit::~AltitudeLimit() {}

Bearing::~Bearing() {}
Bearing::Bearing() {}

CommonSegmentDetails::CommonSegmentDetails() {}
CommonSegmentDetails::~CommonSegmentDetails() {}

Course::Course() {}
Course::~Course() {}

CustAreaCode::CustAreaCode() {}
CustAreaCode::~CustAreaCode() {}

CustAreaCode::CustAreaCode(const string &s)
{
  areaCode = Enum::getAreaCode(s);
  customerCode = s;
}

bool CustAreaCode::operator==(const CustAreaCode& custAreaCode) const
{
  return
    areaCode != custAreaCode.areaCode ?
      false
    :
      areaCode == Enum::AreaCode::Undefined ?
        customerCode == custAreaCode.customerCode
      :
        true;
}

Frequency::Frequency() {}
Frequency::~Frequency() {}

HighPrecisionLocation::HighPrecisionLocation() {}
HighPrecisionLocation::~HighPrecisionLocation() {}

IntermediateFixDetails::IntermediateFixDetails() {}
IntermediateFixDetails::~IntermediateFixDetails() {}

Latitude::Latitude() {}
Latitude::~Latitude() {}

LegTypeCode::LegTypeCode() {}
LegTypeCode::~LegTypeCode() {}

Location::Location() {}
Location::~Location() {}

Longitude::Longitude() {}
Longitude::~Longitude() {}

MagneticVariation::MagneticVariation() {}
MagneticVariation::~MagneticVariation() {}

NameFormatIndicator::NameFormatIndicator() {}
NameFormatIndicator::~NameFormatIndicator() {}

NdbNavaidClass::NdbNavaidClass() {}
NdbNavaidClass::~NdbNavaidClass() {}

PrecisionApproachNavaidReference::PrecisionApproachNavaidReference() {}
PrecisionApproachNavaidReference::~PrecisionApproachNavaidReference() {}

ProcedureDesignAircraftCategories::ProcedureDesignAircraftCategories() {}
ProcedureDesignAircraftCategories::~ProcedureDesignAircraftCategories() {}

ProcedureDesignAircraftTypes::ProcedureDesignAircraftTypes() {}
ProcedureDesignAircraftTypes::~ProcedureDesignAircraftTypes() {}

ProcedureWaypointDescription::ProcedureWaypointDescription() {}
ProcedureWaypointDescription::~ProcedureWaypointDescription() {}

RNPLOS::RNPLOS() {}
RNPLOS::~RNPLOS() {}

RouteQualifications::RouteQualifications() {}
RouteQualifications::~RouteQualifications() {}

RunwayIdentifier::RunwayIdentifier() {}
RunwayIdentifier::~RunwayIdentifier() {}

RunwayOrPadIdentifier::RunwayOrPadIdentifier() {}
RunwayOrPadIdentifier::~RunwayOrPadIdentifier() {}

Sector::Sector() {}
Sector::~Sector() {}

SegmentDetails::SegmentDetails() {}
SegmentDetails::~SegmentDetails() {}

StartOrEndTime::StartOrEndTime() {}
StartOrEndTime::~StartOrEndTime() {}

StationDeclination::StationDeclination() {}
StationDeclination::~StationDeclination() {}

TAASectorDetails::TAASectorDetails() {}
TAASectorDetails::~TAASectorDetails() {}

TimesOfOperation::TimesOfOperation() {}
TimesOfOperation::~TimesOfOperation() {}

TimeOfOperationInterval::TimeOfOperationInterval() {}
TimeOfOperationInterval::~TimeOfOperationInterval() {}

TimeZone::TimeZone() {}
TimeZone::~TimeZone() {}

WaypointType::WaypointType() {}
WaypointType::~WaypointType() {}

WaypointUsage::WaypointUsage() {}
WaypointUsage::~WaypointUsage() {}

namespace Arinc424
{
  namespace Type
  {
    ostream& operator<<(ostream& os, const CustomerCode& customerCode)
    {
      return os << setw(3) << customerCode.substr(0, 3);
    }

    ostream& operator<<(ostream& os, const CustAreaCode& custAreaCode)
    {
      if (custAreaCode.areaCode == Enum::AreaCode::Undefined)
      {
        return os << custAreaCode.customerCode;
      }
      else
      {
        return os << custAreaCode.areaCode;
      }
    }
  }
}