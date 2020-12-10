#include "Types/DataTypes.h"
using namespace Arinc424::Type;

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

RunwayIdentifier::RunwayIdentifier() {}
RunwayIdentifier::~RunwayIdentifier() {}

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
