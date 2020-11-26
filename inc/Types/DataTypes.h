#pragma once

#include "Enumerations.h"

#include "../xs.h"

namespace Arinc424
{
  namespace Type
  {
    /// This Class represents the "Alpha" character type of the Arinc 424 data.
    class Alpha
    {
      public:
        Alpha();
        virtual ~Alpha();

      private:
    };

    /// The all-numeric altitude field will contain altitudes in feet with a resolution of one foot.
    /// If isFlightLevel is true, this element represents altitude as a flight level.
    /// The contents of this field only contain the numerical portion of the flight level expressed in hundreds of feet (e.g., 120, 1, or 10).
    /// Restricted to the range -2000 to 99999.
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

    /// The “ATA/IATA” field contains the Airport/Heliport ATA/IATA designator code to which the data contained in the record relates.
    typedef xs::string ATAIATADesignator;

    /// Identifies the approach types published on a given approach procedure which require Airport or Helicopter Operations SBAS path points.
    /// Limited to 10 characters.
    typedef xs::string ApproachTypeIdentifier;

    /// The “GNSS Channel Number” field identifies the channel to be used for a given approach.
    /// The “MLS Channel” field specifies the channel of the Azimuth, Elevationand Data transmissions for the MLS identified in the “MLS Identifier” field of the record.
    /// Restricted to exactly 5 digits.
    typedef xs::unsignedInt Channel;

    /// Restricted to the range 0 to 360 degrees
    typedef xs::decimal CompassValue;

    /// Restricted to 4 digits, one fraction digit.
    typedef CompassValue BearingValue;

    /// “Outbound Magnetic Course” is the published outbound magnetic course from the waypoint identified in the record’s “Fix Ident” field.
    /// In addition, this field is used for Course/Heading/Radials on SID/STAR Approach Records through requirements of the Path Terminator and coding rules contained in Attachment 5 of this specification.
    typedef CompassValue CourseValue;

    /// “Outbound Magnetic Course” is the published outbound magnetic course from the waypoint identified in the record’s “Fix Ident” field.
    /// In addition, this field is used for Course/Heading/Radials on SID/STAR Approach Records through requirements of the Path Terminator and coding rules contained in Attachment 5 of this specification.
    class Course
    {
      public:
        Course();
        ~Course();

      private:
        Type::CourseValue courseValue;
        xs::boolean isTrue;
    };

    /// The “Course Width At Threshold” field defines the width of the lateral course at the Landing Threshold Point (LTP) or Fictitious Helipoint (or helipoint).
    /// This width, in conjunction with the location of the Flight Path Alignment Point (FPAP) defines the sensitivity of the lateral deviations throughout the approach.
    typedef xs::decimal CourseWidthAtThreshold;

    ///Restricted to 6 digits and 3 fraction digits
    typedef xs::decimal DistanceNMThousanths;

    /// The “ARC Radius” field is used to define the radius of a precision turn.
    /// In Terminal Procedures, this is the “Constant Radius To A Fix” Path and Termination, for “RF” Leg.
    /// In Holding Patterns, this is the turning radius, inbound to outbound leg, for RNP Holding.
    /// The ARC Radius field is also used to specify the turn radius of RNP holding patterns included in SID, STAR, and Approach Records as HA, HF, and HM legs.
    typedef DistanceNMThousanths ARCRadius;

    /// The “Core Identifier” field contains the character-name-code, or other series of characters, with which the object is identified.
    /// This includes Waypoint Identifiers, VHF NAVAID Identifiers, NDB NAVAID identifier, Airport Identifiers, Runway Identifiers, and other objects.
    typedef xs::string CoreIdentifier;

    /// The “Customer Area Code” field permits the categorization of standard records by geographical area and of tailored records by the airlines for whom they are provided in the master file.
    /// Several record types do not adhere to the established geographical boundaries.
    /// There is no “AREA” in such records.
    typedef xs::string CustomerCode;

    /// The “Customer Area Code” field permits the categorization of standard records by geographical area
    /// and of tailored records by the airlines for whom they are provided in the master file.
    /// Several record types do not adhere to the established geographical boundaries.
    /// There is no “AREA” in such records.
    class CustAreaCode : public Alpha
    {
      public:
        CustAreaCode();
        virtual ~CustAreaCode();

      private:
        Enum::AreaCode areaCode;
        CustomerCode customerCode;
    };

    /// The "Cycle Date" field identifies the calendar period in which the record was added to the file or last revised.
    /// A change in any ARINC 424 field, except Dynamic Magnetic Variation, Frequency Protection, Continuation Record Number and File Record Number, requires a cycle date change.
    /// The cycle date will not change if there is no change in the data.
    /// The first two digits of the field contain the last two digits of the year in which the addition or revision was made.
    /// The last two digits contain the numeric identity of the 28-day data update cycle during which the change occurred.
    /// Each calendar year contains 13 such cycles; however, on rare occasions 14 cycles will be encountered.
    /// Note: This field does not indicate changes on elements/attributes of type ID or IDREF.
    typedef xs::string CycleDate;

    /// The “Daylight” Time Indicator” field is used to indicate if the airport observes Daylight or Summer time when such time changes are in effect for the country or state the airport resides in.
    typedef bool DaylightIndicator;

    /// Restricted to exactly 4 digits.
    typedef xs::unsignedInt DistanceFeet;

    /// Restricted to exactly 5 digits.
    typedef xs::unsignedInt DistanceFeetFiveDigits;

    /// Restricted to 3 digits and 1 decimal.
    typedef xs::decimal DistanceMeters;

    /// Restricted to 4 digits and 1 fraction digit.
    typedef xs::decimal DistanceNM;

    /// Limited to 4 digits
    typedef xs::unsignedInt DistanceIntegerNMFourDigits;

    /// Limited to 3 digits
    typedef DistanceIntegerNMFourDigits DistanceIntegerNM;

    /// Limited to 2 digits
    typedef DistanceIntegerNM DistanceIntegerNMTwoDigits;

    /// Elevation of the respective feature.
    /// Restricted to the range -1500 to 20000
    typedef int Elevation;

    /// The “Ellipsoidal Height” field is the height of a surveyed point in reference to the WGS-84 ellipsoid.
    typedef xs::decimal EllipsoidHeight;

    /// The “Final Approach Segment Data CRC Remainder” field is an eight (8) character hexadecimal representation of the 32-bit CRC value provided by the source for the information contained in the aeronautical data fields being monitored for integrity.
    /// The value is calculated by a specific mathematical algorithm, which is both machine and man processible.
    typedef xs::string FinalApproachSegmentDataCRCRemainder;

    /// This field specifies frequency and unit of measure of the frequency information.
    class Frequency
    {
      public:
        Frequency();
        ~Frequency();

      private:
        Enum::FreqUnitOfMeasure freqUnitOfMeasure;
        float frequencyValue;
    };

    /// The “Glide Path Angle” field is an angle, expressed in degrees, tenths and hundredths of degrees, measured at the Flight Path Control Point (FPCP) of those approach procedures that require the coding of a Airport or Helicopter Operations SBAS Path Point record or GBAS Path Point Record. It establishes the intended descent gradient for the final approach flight path. For an illustration of the GPA and related points.
    typedef xs::decimal GlidePathAngle;

    /// The “High Precision Latitude” field contains the latitude of the navigation feature identified in the record.
    /// When used on Airport Path Point Records, one navigation feature is the LTP/FTP, the other is the FPAP.
    /// When used on Helicopter Operations Path Point Records, one navigation feature is the Fictitious Helipoint (or Helipoint), the other is the FPAP.
    typedef xs::string HighPrecisionLatitude;

    /// The “High Precision Longitude” field contains the longitude of the navigation feature identified in the record.
    /// When used on Airport Path Point Records, one navigation feature is the LTP/FTP, the other is the FPAP.
    /// When used on Helicopter Operations Path Point Records, one navigation feature is the Fictitious Helipoint (or Helipoint), the other is the FPAP.
    typedef xs::string HighPrecisionLongitude;

    /// High Precision Location
    class HighPrecisionLocation
    {
      public:
        HighPrecisionLocation();
        ~HighPrecisionLocation();

      private:
        Type::HighPrecisionLatitude highPrecisionLatitude;
        Type::HighPrecisionLongitude highPrecisionLongitude;
    };

    /// The Horizontal Alert Limit (HAL) is the radius of a circle in the horizontal plane (the local plane tangent to the WGS-84 ellipsoid), with its center being at the true position, which describes the region which is required to contain the indicated horizontal position with the required probability for a particular navigation mode assuming the probability of a GPS satellite integrity failure being included in the position solution is less than or equal to 10-4 per hour.
    typedef DistanceMeters HorizontalAlertLimit;

    /// This element provides the 2 character code to identify a state
    typedef xs::string IcaoCode;

    /// The “IFR Capability” field indicates if the Airport/Heliport has any published Instrument Approach Procedures.
    typedef xs::boolean IFRCapability;

    /// This is an abstract class that is the parent class for degrees.
    typedef int LatLongDegree;

    /// Contains degrees of a coordinate as an integer from 0 to 90.
    typedef LatLongDegree LatDegree;

    /// Contains degrees of a coordinate as an integer from 0 to 180.
    typedef LatLongDegree LongDegree;

    /// The “Length Offset” field is the distance from the stop end of the runway (SER) to the FPAP.
    /// This distance defines the location where lateral sensitivity changes to the missed approach sensitivity.
    /// If the FPAP is located at the designated center of the opposite runway end, the distance is zero.
    /// Additionally, if the procedure is a Point in Space procedure and there is no runway, the value is set to 0000 (all zeros).
    typedef DistanceFeet LengthOffset;

    /// Leg distance element used on procedure and airway legs, and terminal procedure flight planning records.
    typedef DistanceNM LegDistance;

    ///
    typedef xs::string LegInboundIndicator;

    typedef xs::unsignedInt LongestRunway;

    /// The “Name” field defines the name commonly applied to the navigation entity defined in the record.
    /// The field is restricted to a maximum of 50 characters.
    typedef xs::string Name;

    ///
    typedef xs::string NotesText;

    /// The “Orthometric Height” field is the height of a surveyed point in reference to Mean Sea Level (MSL).
    /// Restricted to the range -9999 to +9999.
    typedef xs::decimal OrthometricHeight;

    /// On procedures to runways or helipads, the Path Point TCH is the height above the runway threshold (LTP) or the helicopter alighting point. On procedures which are Point in Space, the height of the fictitious helipoint (or helipoint) above the height of the heliport. It is the same as the TCH defined in Section 5.67, but has greater resolution due to the required precision.  The value may be expressed in feet to a resolution of tenths of feet, or meters to a resolution of hundredths of meters. Whether the value is in feet or meters can be determined from the TCH Units Indicator.
    /// Restricted to 6 digits and 2 decimals
    typedef xs::decimal PathPointTCH;

    /// This element provides a way to reference any child element of A424Point.
    typedef xs::string PointReference;

    /// Contains minutes of a coordinate as an integer from 0 to 60.
    typedef int Minute;

    /// Contains seconds of a coordinate as an integer from 0 to 60.
    typedef int Second;

    /// Contains hundredths of a coordinate as an integer from 0 to 99.
    typedef int HundredthSecond;

    /// The “Latitude” field contains the latitude of the navigational feature identified in the record.
    /// The latitude is a complex type that consists of children elements that contain scaled integers.
    class Latitude
    {
      public:
        Latitude();
        virtual ~Latitude();

      private:
        LatDegree deg;
        Minute min;
        Second sec;
        HundredthSecond hSec;
        Enum::NorthSouth northSouth;

        /// This field is optional for convenience in data processing.
        /// The value of this field is not authoritative.
        double decimalDegreesLatitude;
    };

    /// The Longitude field contains the longitude of the geographic position of the navigational feature identified in the record.
    class Longitude
    {
      public:
        Longitude();
        ~Longitude();

      private:
        LongDegree deg;
        Minute min;
        Second sec;
        HundredthSecond hSec;
        Enum::EastWest eastWest;

        /// This field is optional for convenience in data processing.
        /// The value of this field is not authoritative.
        double decimalDegreesLongitude;
    };

    /// Latitude and Longitude details of this point.
    class Location
    {
      public:
        Location();
        virtual ~Location();

      private:
        Latitude latitude;
        Longitude longitude;
    };

    /// The “Magnetic Variation” field specifies the angular difference between True North and Magnetic North at the location defined in the record.
    /// “Dynamic Magnetic Variation” is a computer model derived value and takes location and date into consideration.
    /// For the “Station Declination” used in some record types, refer to Section 5.66.
    /// Limited to the range 0 to 180 degrees.
    /// Limited to 4 digits and 1 decimal.
    typedef xs::decimal MagneticVariationValue;

    /// The “Magnetic Variation” field specifies the angular difference between True North and Magnetic North at the location defined in the record.
    /// “Dynamic Magnetic Variation” is a computer model derived value and takes location and date into consideration.
    /// For the “Station Declination” used in some record types, refer to Section 5.66.
    class MagneticVariation
    {
      public:
        MagneticVariation();
        ~MagneticVariation();

        private:
          Enum::MagneticVariationEWT magneticVariation;
          MagneticVariationValue magneticVariationValue;
    };

    ///
    typedef unsigned char MultipleIndicator;

    /// The “Name Format Indicator” field is used to describe the format of the “Waypoint Name/Description” field (5.43).
    /// This field will be formatted according to the rules described in Chapter 7 of this Specification, Waypoint Naming Conventions.
    class NameFormatIndicator
    {
      public:
        NameFormatIndicator();
        ~NameFormatIndicator();

      private:
        Enum::FixType fixType;
        Enum::LocalizerMarkerIndicator localizerMarkerIndicator;
    };

    ///
    class NdbNavaidClass
    {
      public:
        NdbNavaidClass();
        ~NdbNavaidClass();

      private:
        xs::boolean isBFORequired; ///< BFO Operation.  Use of Beat Frequency Oscillator type of equipment is required to received an aural identification signal.
        Enum::NdbNavaidCoverage ndbNavaidCoverage;
        Enum::NdbNavaidIfMarkerInfo ndbNavaidIfMarker;
        Enum::NdbNavaidType ndbNavaidType;
        Enum::NavaidWeatherInfo ndbNavaidWeatherInfo;
        xs::boolean isNoVoice;
    };

    /// This type provides the aircraft category(s) for which the procedure or portion of a procedure (transition) was designed.
    class ProcedureDesignAircraftCategories
    {
      public:
        ProcedureDesignAircraftCategories();
        ~ProcedureDesignAircraftCategories();

      private:
        xs::boolean isCategoryA;
        xs::boolean isCategoryB;
        xs::boolean isCategoryC;
        xs::boolean isCategoryD;
        xs::boolean isCategoryE;
        xs::boolean isCategoryHelicopter;
    };

    /// This type provides the aircraft type(s) for which the procedure or portion of a procedure (transition) was designed.
    class ProcedureDesignAircraftTypes
    {
      public:
        ProcedureDesignAircraftTypes();
        ~ProcedureDesignAircraftTypes();

      private:
        xs::boolean isTypeJet;
        xs::boolean isTypeTurboJet;
        xs::boolean isTypeTurboprop;
        xs::boolean isTypeProp;
        xs::boolean isTypePiston;
        xs::boolean isTypeNonJets;
        xs::boolean isTypeNotLimited;
        xs::boolean isTypeNonTurbojets;
    };

    /// This class represents the waypoint description information used by procedure legs.
    class ProcedureWaypointDescription
    {
      public:
        ProcedureWaypointDescription();
        ~ProcedureWaypointDescription();

      private:
        xs::boolean isEssential;
        xs::boolean isFlyOver;
        xs::boolean isHolding;
        xs::boolean isNoProcedureTurn;

        /// A database waypoint established during procedure coding to facilitate more accurate navigation by the Flight Management Computer than would be allowed using air-mass related Path Terminators to replicate source data.
        /// The waypoint finds use when such considerations as increased environmental restrictions and the congestion of the available airspace come into play.
        /// Used to permit route construction with track to a fix (TF) legs.
        xs::boolean isPhantomFix;
        xs::boolean isSourceProvidedEnrouteWaypoint;

        /// The “TAA Procedure Turn” field is used to indicate whether or a course reversal is necessary when flying within a particular TAA Area.
        xs::boolean isTaaProcedureTurn;

        /// Compulsory Reporting Point: Essential or nonessential waypoints may be classified as ATC compulsory points.
        /// ATC requires the pilot to make a communications report at these waypoints.
        /// All other waypoints may be classified as non compulsory reporting points and are reported only when specifically requested by ATC.
        xs::boolean isAtcCompulsoryReportingPoint;
    };

    /// The altitude shown in the Sector Altitude field provides a 1000 foot obstacle clearance with a specified radius from the navigational facility/fix. The Radius Limit, field allows the radius to be specified.
    typedef DistanceIntegerNMTwoDigits RadiusLimit;

    /// The “Reference Path Data Selector” field enables the automatic tuning of a procedure by Ground Based Augmentation Systems (GBAS) avionics.
    /// This data is not used for SBAS operations.
    /// Limited to exactly 2 digits.
    typedef xs::unsignedInt ReferencePathDataSelector;

    /// The Reference Path Identifier field represents the three or four alphanumeric characters used to uniquely designate the reference path.
    /// The Reference Path Identifier is synonymous with the approach ID located beneath the Channel Number on Instrument Approach Plates and is unique only for a given airport.
    typedef xs::string ReferencePathIdentifier;

    /// The Facility Characteristics field identifies the characteristics of the NAVAID facility.
    typedef xs::unsignedInt RepetitionRate;

    /// Required Navigation Performance (RNP) is a statement of the Navigation Performance necessary for operation within a defined airspace in accordance with ICAO Annex 15 and/or State published rules.  e.g., .15, 4, 1, .3
    /// Restricted to 9 digits
    typedef xs::decimal RequiredNavigationPerformance;

    /// “RHO” is defined as the geodesic distance in nautical miles to the waypoint identified in the record’s “Fix Ident” field from the NAVAID in the “Recommended NAVAID” field.
    typedef DistanceNM Rho;

    /// 
    class RNPLOS
    {
      public:
        RNPLOS();
        ~RNPLOS();

      private:
        xs::decimal rnp;
        Enum::RnpLOSAuthorized rnpLOSAuthorized;
    };

    /// The “Route Indicator” field is a single alpha character used to differentiate between multiple final approach segments to the same runway or helipad contained in the Final Approach Coding.
    typedef unsigned char RouteIndicator;

    /// This element provides boolean expressions describing qualifications of the route.
    /// The qualifications in this element are common to different types of routes.
    class RouteQualifications
    {
      public:
        RouteQualifications();
        ~RouteQualifications();

      private:
        xs::boolean isDmeReq;
        xs::boolean isGnssReq;
        xs::boolean isRadarReq;
        xs::boolean isFmsReq;
        xs::boolean isConventional;
    };

    /// The “RunwayNumber” field identifies the runways described in runway records and runways served by the ILS/MLS described in ILS/MLS records. The runway Number is only part of the Runway Identifier.
    /// Limited to the range of 1 to 36.
    typedef xs::unsignedInt RunwayNumber;

    /// The “Runway Identifier” field identifies the runways described in runway records and runways served by the ILS/MLS described in ILS/MLS records.
    class RunwayIdentifier
    {
      public:
        RunwayIdentifier();
        ~RunwayIdentifier();

      private:
        Enum::RunwayLeftRightCenterType runwayLeftRightCenterType;
        Type::RunwayNumber runwayNumber;
    };

    /// This XML element is designed as an abstraction for Runway Identifier or Pad Identifier, this is done by using the XML attribute "choice", so that only one of the elements can be present in the XML file.
    class RunwayOrPadIdentifier
    {
      public:
        RunwayOrPadIdentifier();
        ~RunwayOrPadIdentifier();

      private:
        CoreIdentifier padIdentifier;
        RunwayIdentifier runwayIdentifier;
    };

    /// When used on MSA Records, the “Sector Bearing” contains beginning and ending bearing values, referenced to the MSA Center, for each sector of the MSA.
    /// When used on TAA records, the “Sector Bearing” contains the beginning and ending bearings that define a TAA Area and are referenced to the TAA Initial Approach Fix (IAF) Waypoint.
    /// Limited to 3 digits
    typedef xs::unsignedInt SectorBearing;

    /// This class represents the details for a MSA or TAA Sector.
    class Sector
    {
      public:
        Sector();
        ~Sector();

      private:
        xs::unsignedInt sectorAltitude;
        Type::SectorBearing sectorBearingBegin;
        Type::SectorBearing sectorBearingEnd;
        Type::RadiusLimit sectorRadius;
    };

    /// For Route Type Records - A route of flight is defined by a series of records taken in order.
    /// The “Sequence Number” field defines the location of the record in the sequence defining the route of flight identified in the route identifier field.
    /// For Boundary Type Records - A boundary is defined by a series of records taken in order.
    /// The “Sequence Number” field defines the location of the record in the sequence defining a boundary. For Record Types requiring more than one primary record to define the complete content – In a series of records used to define a complete condition, the “Sequence Number” is used to define each primary record in the sequence. For Airport and Heliport TAA Records – Sequence Number 1 will always be assigned to the record based on the Center Fix upon which the Straight-In Area is predicated, Sequence Number 2 will always be assigned to the record based on the Center Fix upon which the Left Base Area is predicated, and Sequence Number 3 will always be assigned to the record based on the Center Fix upon which the Right Base Area is predicated. Therefore, if a TAA Record has a Straight-In Area and a Right Base Area, but no Left Base Area, only Sequence Numbers 1 and 3 will be used. If a TAA Record has a Straight-In Area and a Left Base Area but no Right Base Area, only Sequence Numbers 1 and 2 will be used.
    /// Restricted to 4 digits.
    typedef unsigned int SequenceNumber;

    /// The Speed Limit field defines a speed, expressed in Knots, Indicated (K.I.A.S.), for a fix in a terminal procedure or for an airport or heliport terminal environment.
    /// Restricted to less than 1000.
    typedef unsigned int SpeedLimit;

    /// This class represents the details for a TAA Sector.
    class TAASectorDetails : public Sector
    {
      public:
        TAASectorDetails();
        virtual ~TAASectorDetails();

      private:
        Type::RadiusLimit sectorRadiusStart;
        Type::RadiusLimit sectorRadiusEnd;
        xs::boolean procedureTurn;
    };

    /// “Theta” is defined as the magnetic bearing to the waypoint identified in the record’s “FIX Ident” field from the Navaid in the “Recommended Navaid” field.
    typedef BearingValue Theta;

    /// The “Threshold Crossing Height” specifies the height above the landing threshold on a normal glide path.
    /// Limited to 3 digits.
    typedef xs::unsignedInt ThresholdCrossingHeight;

    /// The standard time zone system is based on the division of world into 24 zones, each of 15 degrees longitude.
    /// The “zero” time zone is entered at Greenwich meridian with longitudes 7 degrees, 30 minutes West and 7 degrees, 30 minutes east, and there is no difference in the standard time of this time zone and Greenwich Mean Time.
    /// Time zones are designated by an integer offset from Greenwich Mean Time, which represets the time difference from GMT in hours, and a minute offset for non-standard time zone offsets.
    /// See ARINC 424 5.178 for further explanation.
    class TimeZone
    {
      public:
        TimeZone();
        ~TimeZone();

      private:
        int hourOffset; ///< From -14 to +12
        int minuteOffset;
    };

    /// The “Transition Altitude” field defines the altitude in the vicinity of an airport or heliport at or below which the vertical position of an aircraft is controlled by reference to altitudes (MSL).
    /// The “Transition Level” field defines the lowest flight level available for use above the transition altitude.
    /// Aircraft descending through the transition layer will use altimeters set to local station pressure, while departing aircraft climbing through the layer will be using standard altimeter setting (QNE) of 29.92 inches of mercury, 1013.2 millibars or 1013.2 hectopascals.
    /// Restricted to a total of 5 digits.
    typedef AltitudeValue TransitionAltitude;

    typedef xs::string Vectoring;

    /// The Vertical Alert Limit (VAL) is half the length of a segment on the vertical axis (perpendicular to the horizontal plane of WGS-84 ellipsoid), with its center being at the true position, which describes the region which is required to contain the indicated vertical position with a probability of 1-10-7 per approach, assuming the probability of a GPS satellite integrity failure being included in the position solution is less than or equal to 10-4 per hour.
    typedef xs::decimal VerticalAlertLimit;

    /// Vertical Scale Factor (VSF) is used to set the vertical deviation scale.
    /// Restricted to 3 digits
    typedef xs::unsignedInt VerticalScaleFactor;

    /// The “Waypoint Type” field identifies a number of data conditions.
    ///
    ///   1. The first is whether or not the waypoint has been published in an official government source or created during database coding of routes or procedures.
    ///   2. The second is whether or not the waypoint is an intersection and /or DME fix formed with reference to ground based navaids or is an RNAV Waypoint formed by the latitude and longitude.
    ///   3. The third is an indication of one or more functions assigned to that waypoint in terminal procedure coding.
    ///   4. The fourth is an indication of location of the waypoint with reference to airspace boundaries and /or grid lines.
    ///   5. The fifth is an indication of how ATC might be using the waypoint in operational clearances.
    ///   6. The sixth is an indication that the waypoint has been published for VFR use only.
    ///   7. Lastly, there is an indication of whether the waypoint is published for use in terminal procedure coding of a specific type, multiple types or not published at all.
    class WaypointType
    {
      public:
        WaypointType();
        ~WaypointType();

      private:
        xs::boolean isAirwayIntersection;
        xs::boolean isArcCenter;
        xs::boolean isBackMarker;
        xs::boolean isControlledAirspaceIntersection;
        xs::boolean isEnroute;
        xs::boolean isFACF;
        xs::boolean isFAF;
        xs::boolean isFIRorFRAEntryPoint;
        xs::boolean isFIRorFRAExitPoint;
        xs::boolean isFirUirFix;
        xs::boolean isForApproach;
        xs::boolean isForSID;
        xs::boolean isForStar;
        xs::boolean isForMultipleProcedures;
        xs::boolean isFRADepartureTransitionPoint;
        xs::boolean isFRATerminalHoldingPoint;
        xs::boolean isFullDegreeLatFix;
        xs::boolean isHalfDegreeLatFix;
        xs::boolean isHelicopterOnlyAirwayFix;
        xs::boolean isInitialApproachFix;
        xs::boolean isInitialDepartureFix;
        xs::boolean isInnerMarker;
        xs::boolean isIntermediateApproachFix;
        xs::boolean isIntersectionDmeFix;
        xs::boolean isMiddleMarker;
        xs::boolean isMissedApproachPoint;
        xs::boolean isNDB;
        xs::boolean isOceanicGateway;
        xs::boolean isOffRoute;
        xs::boolean isOuterMarker;
        xs::boolean isRequiredOffRoute;
        xs::boolean isRfLegNotProcedureFix;
        xs::boolean isRNAV;
        xs::boolean isUsageRNAV;
        xs::boolean isSourceProvidedEnroute;
        xs::boolean isStepDownFix;
        xs::boolean isUncharted;
        xs::boolean isUnnamed;
        xs::boolean isVFR;
    };

    /// The waypoint usage field is employed to indicate the structure in which the waypoint is utilized.
    class WaypointUsage
    {
      public:
        WaypointUsage();
        ~WaypointUsage();

      private:
        xs::boolean isHi;
        xs::boolean isLo;
        xs::boolean isTerminal;
    };

  } // namespace Type
} // namespace Arinc424
