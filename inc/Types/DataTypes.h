#pragma once

#include "Enumerations.h"
#include "../xs.h"
#include <list>

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

    /// The “Service Indicator” field is used to further define the use of the frequency for the specified Communication Type.
    class AirportHeliportCommunicationServiceIndicator
    {
      public:
        AirportHeliportCommunicationServiceIndicator();
        ~AirportHeliportCommunicationServiceIndicator();

      private:
        Enum::ServiceIndicatorAirportHeliportFrequency serviceIndicatorAirportHeliportFrequency;
        Enum::ServiceIndicatorAirportHeliportInformation serviceIndicatorAirportHeliportInformation;
        Enum::ServiceIndicatorAirportHeliportService serviceIndicatorAirportHeliportService;
    };

    /// The all-numeric altitude field will contain altitudes in feet with a resolution of one foot.
    /// If isFlightLevel is true, this element represents altitude as a flight level.
    /// The contents of this field only contain the numerical portion of the flight level expressed in hundreds of feet (e.g., 120, 1, or 10).
    /// Restricted to the range -2000 to 99999.
    typedef xs::integer AltitudeValue;

    /// The "Altitude/Minimum Altitude" field is a choice element that may contain one of either an element of type FlightLevel or an element of type Altitude.
    /// The “Altitude / Minimum Altitude” field indicates the reference altitude associated with
    ///   (1) Enroute Airways(MEA, MFA or other minimum altitudes as defined by source),
    ///   (2) holding pattern path of Holding Pattern record,
    ///   (3) altitudes at fixes in terminal proceduresand terminal procedure path termination defined by the Path Terminator in the Airport or Heliport SID / STAR / Approach Elements and
    ///   (4) lowest altitude of the “blocked altitudes” for a Preferred Route.
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

    /// This class is an abstraction used to represent the details for an Additional Sectorization used in Airport Communications.
    class AdditionalSectorization
    {
      public:
        AdditionalSectorization();
        ~AdditionalSectorization();

      private:
        Altitude additionalSectorizationAltitude1;
        Altitude additionalSectorizationAltitude2;
        Enum::AltitudeDescription additionalSectorizationAltitudeDescription;
    };

    /// Identifies the approach types published on a given approach procedure which require Airport or Helicopter Operations SBAS path points.
    /// Limited to 10 characters.
    typedef xs::string ApproachTypeIdentifier;

    /// The “ATA/IATA” field contains the Airport/Heliport ATA/IATA designator code to which the data contained in the record relates.
    typedef xs::string ATAIATADesignator;

    /// The “ATC Identifier” field used on Flight Planning Arrival/Departure Data Records is the indication of the officially published procedure designation which is required for Flight Planning.
    /// Limited to 7 characters.
    typedef xs::string ATCIdentifier;

    /// The “Azimuth Coverage Sector” fields define the limit of the azimuth transmitter signal on the right and left side of the MLS Bearing (Section 6.167).
    /// The Back Azimuth Coverage Sector is identical to the Azimuth Coverage Sector and also provides guidance for Missed Approach Procedures and departures.
    /// Must be less than 360 degrees; limited to 3 digits.
    typedef xs::unsignedInt AzimuthCoverageSectorRightLeft;

    /// The MLS Azimuth and Back Azimuth Proportional Angle fields define the limits of proportional guidance of the azimuth transmitter signal on the right and left side of the MLS Azimuth bearing (Section 6.167).
    /// The BAZ is identical to the AZ and also provides guidance for Missed Approach Procedures and departures.
    /// See figure under Section 6.172.
    /// Must be less than 360 degrees; limited to 3 digits.
    typedef xs::unsignedInt AzimuthProportionalAngleRightLeft;

    /// The Beam Position” field defines the location of the facility antenna relative to one end of the runway or threshold.
    /// Restricted to 4 digits.
    typedef xs::unsignedInt BeamPosition;

    /// The “GNSS Channel Number” field identifies the channel to be used for a given approach.
    /// The “MLS Channel” field specifies the channel of the Azimuth, Elevationand Data transmissions for the MLS identified in the “MLS Identifier” field of the record.
    /// Restricted to exactly 5 digits.
    typedef xs::unsignedInt Channel;

    /// The “Communication Distance” field is used to define the distance restriction a communication frequency is to be used within or beyond when such restrictions apply.
    /// This field is used in conjunction with the Distance Description field.
    /// Limited to 2 digits
    typedef xs::unsignedInt CommunicationDistance;

    /// Restricted to the range 0 to 360 degrees
    typedef xs::decimal CompassValue;

    /// Restricted to 4 digits, one fraction digit.
    typedef CompassValue BearingValue;

    ///
    class Bearing
    {
      public:
        Bearing();
        ~Bearing();

      private:
        BearingValue bearingValue;
        xs::boolean isTrueBearing;
    };

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

    /// The “Call Sign” field contains the name of a communications service provider that is to be used when contacting that service/used by the service to identify itself when contacting aircraft on the frequencies contained in the record.
    /// The field is also used to provide the broadcast identification name of automated services.
    /// Limited to 25 characters.
    typedef xs::string CallSign;

    /// The “Core Identifier” field contains the character-name-code, or other series of characters, with which the object is identified.
    /// This includes Waypoint Identifiers, VHF NAVAID Identifiers, NDB NAVAID identifier, Airport Identifiers, Runway Identifiers, and other objects.
    typedef xs::string CoreIdentifier;

    /// A standard cruising level table is established by ICAO and is to be observed except when, on the basis of regional air navigation agreements, a modified table of cruising levels is prescribed for use.
    /// This field permits the enroute airway record to identify the Cruise Table record that is to be used for cruise levels.
    /// Exactly 2 characters.
    typedef xs::string CruiseTableIdentifier;

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

    /// Restricted to 2 digits.
    typedef DistanceNM DistanceNMTwoDigits;

    /// The “Category Radii” fields, expressed in tenths of nautical miles, specifies the obstacle clearance area for aircraft maneuvering to land on a runway which is not aligned with the FAC of the approach procedure.
    /// The limits of the circling area are defined to be an arc from the center of the end of each usable runway.
    /// The extremities of the adjacent arcs are joined by lines drawn tangent to the arcs.
    /// The area thus enclosed is the circling approach area.
    typedef DistanceNMTwoDigits CategoryDistance;

    /// Limited to 4 digits
    typedef xs::unsignedInt DistanceIntegerNMFourDigits;

    /// Limited to 3 digits
    typedef DistanceIntegerNMFourDigits DistanceIntegerNM;

    /// The Along Track Distance field used on Flight Planning Arrival/Departure Data Records is the total distance for a given transition, from the initial fix to the ending fix in the transition.
    /// A single occurrence of a Flight Planning Arrival/Departure Data record can contain up to three Along Track Distance fields, one for each of the transition types that can make up a single terminal route in the Primary Record and up to four possible intermediate fix points in each Continuation Record.
    /// Collectively, the values equal the along track distance from the first fix in the first transition to the last fix in the last transition.
    typedef DistanceIntegerNM AlongTrackDistance;

    /// Limited to 2 digits
    typedef DistanceIntegerNM DistanceIntegerNMTwoDigits;

    /// The distance from the extremity of a runway to a threshold not located at that extremity of that runway, in feet.
    typedef DistanceFeet DisplacedThresholdDistance;

    /// Elevation of the respective feature.
    /// Restricted to the range -1500 to 20000
    typedef xs::integer Elevation;

    /// The “Elevation Angle Span” field defines the scan of the elevation transmitter signal between the lower and upper limits.
    /// Must be less than 360 degrees; limited to 3 digits.
    typedef xs::unsignedInt ElevationAngleSpan;

    /// The “Ellipsoidal Height” field is the height of a surveyed point in reference to the WGS-84 ellipsoid.
    typedef xs::decimal EllipsoidHeight;

    /// The “Facility Elevation” field provides the elevation of navaids and communication transmitters.
    typedef xs::integer FacilityElevation;

    /// The “Final Approach Segment Data CRC Remainder” field is an eight (8) character hexadecimal representation of the 32-bit CRC value provided by the source for the information contained in the aeronautical data fields being monitored for integrity.
    /// The value is calculated by a specific mathematical algorithm, which is both machine and man processible.
    typedef xs::string FinalApproachSegmentDataCRCRemainder;

    /// The “Altitude” field used on Flight Planning Arrival/Departure Data Records is a simplification of the altitude concept used in the full procedure records.
    /// It will provide an altitude indication in hundreds of feet, no AGL, MSL, FL etc indication provided.
    /// Limited to 3 digits.
    typedef xs::unsignedInt FlightPlanningAltitude;

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

    /// The “Glide Slope Beam Width” field specifies the glide path beam width of the Glide Slope defined in the record.
    typedef xs::decimal GlideslopeBeamWidth;

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
    typedef xs::integer LatLongDegree;

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

    /// The “Leg Type Code” field used on Flight Planning Arrival/Departure Data Records is a simplification of the Path Terminator concept.
    /// It will provide the information on the path between intermediate waypoints as straight or curved and provide an indication of the change in direction of flight, expressed as left or right, at an intermediate waypoint.
    class LegTypeCode : public Alpha
    {
      public:
        LegTypeCode();
        virtual ~LegTypeCode();

      private:
        Enum::LegTypeCodeSC legTypeCodeSC;
        Enum::LegTypeTurnIndication legTypeTurnIndication;
    };

    typedef xs::unsignedInt LongestRunway;

    /// The Maximum Allowable Helicopter Weight represents the maximum weight, expressed in hundreds of pounds, that a helipad or FATO can support.
    /// Limited to the range 0, 999.
    typedef xs::integer MaxHelicopterWeight;

    /// The “Minor Axis Bearing” field indicates the true bearing of the minor axis of marker beacons.
    typedef BearingValue MinorAxisBearing;

    /// The “Name” field defines the name commonly applied to the navigation entity defined in the record.
    /// The field is restricted to a maximum of 50 characters.
    typedef xs::string Name;

    ///
    typedef xs::string NotesText;

    /// The Number of Engines Restriction field used on Flight Planning Arrival/Departure Data Records is derived from government source and is included whenever a given procedure, normally departure, is restricted to, or designed for, aircraft with a specific number of engines.
    /// Exactly 4 characters.
    typedef xs::string NumberOfEnginesRestriction;

    /// The “Orthometric Height” field is the height of a surveyed point in reference to Mean Sea Level (MSL).
    /// Restricted to the range -9999 to +9999.
    typedef xs::decimal OrthometricHeight;

    /// On procedures to runways or helipads, the Path Point TCH is the height above the runway threshold (LTP) or the helicopter alighting point. On procedures which are Point in Space, the height of the fictitious helipoint (or helipoint) above the height of the heliport. It is the same as the TCH defined in Section 5.67, but has greater resolution due to the required precision.  The value may be expressed in feet to a resolution of tenths of feet, or meters to a resolution of hundredths of meters. Whether the value is in feet or meters can be determined from the TCH Units Indicator.
    /// Restricted to 6 digits and 2 decimals
    typedef xs::decimal PathPointTCH;

    /// This element provides a way to reference any child element of A424Point.
    typedef xs::string PointReference;

    /// This type represents the details for a Common Segment.
    class CommonSegmentDetails
    {
      public:
        CommonSegmentDetails();
        ~CommonSegmentDetails();

      private:
        AlongTrackDistance alongTrackDistance;
        PointReference fix;
    };

    /// This type represents the details of an intermediate Fix
    class IntermediateFixDetails
    {
      public:
        IntermediateFixDetails();
        ~IntermediateFixDetails();

      private:
        Enum::FixRelatedTransitionCode fixRelatedTransitionCode;
        AlongTrackDistance intermediateDistance;
        PointReference fix;
    };

    /// The “Glide Slope Angle” field defines the glide slope angle of an ILS facility/GLS approach. 
    /// The “Minimum Elevation Angle” field defines the lowest elevation angle authorized for the MLS procedure.
    typedef xs::decimal PrecisionApproachAngle;

    /// Element which encapsulates the localizer details for the corresponding Runway.
    /// This element contains the localizer ident and localizer class.
    class PrecisionApproachNavaidReference
    {
      public:
        PrecisionApproachNavaidReference();
        ~PrecisionApproachNavaidReference();

      private:
        Enum::PrecisionApproachCategory approachCategory;
        Type::PointReference navaidReference;
    };

    /// Contains minutes of a coordinate as an integer from 0 to 60.
    typedef xs::integer Minute;

    /// Contains seconds of a coordinate as an integer from 0 to 60.
    typedef xs::integer Second;

    /// Contains hundredths of a coordinate as an integer from 0 to 99.
    typedef xs::integer HundredthSecond;

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

    /// The “Multiple Code” field will be used to indicate Restrictive Airspace Areas or MSA Centers having the same designator but subdivided or differently divided by lateral and/or vertical detail.
    typedef unsigned char MultipleCode;

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

    /// The “Nominal Elevation Angle” field defines the normal glide path angle for the MLS installation.
    typedef xs::unsignedInt NominalElevationAngle;

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

    /// The “Procedure Description” field used on Flight Planning Arrival/Departure Data Records is the textual representation of the procedure name.
    /// Limited to 15 characters.
    typedef xs::string ProcedureDescription;

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

    /// If required, additional information concerning a runway can be included in a record in the “Runway Description” field.
    /// Limited to 22 characters.
    typedef xs::string RunwayDescription;

    /// The Runway Gradient field indicates an overall gradient in percent, measured from the start of take-off roll end of the runway designated in the record.
    /// The gradient is expressed as a positive or negative gradient; positive being an upward and negative being a downward gradient.
    /// Limited to the range [-9.0, 9.0]
    typedef xs::decimal RunwayGradient;

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

    /// The “Runway Length” field defines the total length of the runway surface declared suitable and available for ground operations of aircraft for the runway identified in the records’ Runway Identifier field, in feet.
    typedef DistanceFeetFiveDigits RunwayLength;

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

    /// The width of the runway identified in the “Runway Identifier” field is specified in the “Runway Width” field.
    /// Limited to 3 digits.
    typedef xs::unsignedInt RunwayWidth;

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

    /// The “Sectorization” field is used to define the airspace sector a communication frequency is applicable for when an airport defines sectors by bearing from the same point.
    /// Limited to 6 characters.
    typedef xs::unsignedInt Sectorization;

    /// The “Sectorization Narrative” field is used to define sectors of operations for communications services on specific frequencies in a narrative format when that data cannot be formatted in the Sectorization (5.183) field.
    /// The field may also be used to qualify the Sectorization information.
    /// This is usually the “and” situation, meaning the communications service/frequency is to be used in the defined sector and in some other defined situation that cannot be formatted such as Sectorization.
    /// An example is “309127” in the Sectorization field and “When Departing Runway 31L/R” in the Narrative field.
    /// Limited to 60 characters.
    typedef xs::string SectorizationNarrative;

    /// This type represents the details for a segment.
    class SegmentDetails
    {
      public:
        SegmentDetails();
        ~SegmentDetails();

      private:
        CoreIdentifier transitionIdentifier;
        AlongTrackDistance alongTrackDistance;
        PointReference fix;
    };

    /// For Route Type Records - A route of flight is defined by a series of records taken in order.
    /// The “Sequence Number” field defines the location of the record in the sequence defining the route of flight identified in the route identifier field.
    /// For Boundary Type Records - A boundary is defined by a series of records taken in order.
    /// The “Sequence Number” field defines the location of the record in the sequence defining a boundary. For Record Types requiring more than one primary record to define the complete content – In a series of records used to define a complete condition, the “Sequence Number” is used to define each primary record in the sequence. For Airport and Heliport TAA Records – Sequence Number 1 will always be assigned to the record based on the Center Fix upon which the Straight-In Area is predicated, Sequence Number 2 will always be assigned to the record based on the Center Fix upon which the Left Base Area is predicated, and Sequence Number 3 will always be assigned to the record based on the Center Fix upon which the Right Base Area is predicated. Therefore, if a TAA Record has a Straight-In Area and a Right Base Area, but no Left Base Area, only Sequence Numbers 1 and 3 will be used. If a TAA Record has a Straight-In Area and a Left Base Area but no Right Base Area, only Sequence Numbers 1 and 2 will be used.
    /// Restricted to 4 digits.
    typedef xs::unsignedInt SequenceNumber;

    /// The service volume radius identifies the radius of the service volume around the transmitter in Nautical miles.
    typedef DistanceIntegerNMTwoDigits ServiceVolumeRadius;

    /// The Speed Limit field defines a speed, expressed in Knots, Indicated (K.I.A.S.), for a fix in a terminal procedure or for an airport or heliport terminal environment.
    /// Restricted to less than 1000.
    typedef xs::unsignedInt SpeedLimit;

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

    ///
    class StartOrEndTime
    {
      public:
        StartOrEndTime();
        ~StartOrEndTime();

      private:
        /// This field supports specifying a continuous time interval across multiple days.
        /// It should not be used if the "dayOfWeek" in TimeOfOperationInterval is specified.
        /// If used, it should be specified for both start and end times, and they should be different otherwise the TimeOfOperationInterval field should be used.
        Enum::DayOfWeek dayOfWeek;

        /// This field represents the start or end time of the TimeOfOperationInterval.
        /// A timezone may be set for this field, in which case the time is specified in the local timezone.
        /// If no timezone is set, UTC is assumed.
        /// If a timezone is set indicating a local time, it should be the same for both start and end times, and the "adjustForDST" field in the enclosing TimesOfOperation instance may be set to indicate that the time follows daylight saving time in accordance with the local DST calendar.
        xs::time time;

        /// This field supports specifying the StartOrEndTime as an offset from sunrise or sunset.
        /// In this case, the "time" field is just the offset amount such as 01:00:00 or 00:30:00.
        /// If used, there should be no timezone set in the "time" field.
        Enum::RelativeTimeIndicator relativeTimeIndicator;
    };

    /// For VHF NAVAIDS, the “Station Declination” field contains the angular difference between true north and the zero degree radial of the NAVAID at the time the NAVAID was last site checked.
    /// For ILS localizers, the field contains the angular difference between true north and magnetic north at the localizer antenna site at the time the magnetic bearing of the localizer course was established.
    class StationDeclination
    {
      public:
        StationDeclination();
        ~StationDeclination();

      private:
        Enum::StationDeclinationEWT stationDeclinationEWT;
        MagneticVariationValue stationDeclinationValue;
    };

    /// This field identifies the WGS84 elevation of the GLS ground station described in the record.
    typedef Elevation StationElevationWGS84;

    /// The station type identifies the type of the differential ground station.
    /// The first character will be L for LAAS/GLS ground station, C for SCAT-1 station.
    /// The second and third character will be blank for the moment.
    /// They will indicate the interoperability standard to which the station conforms.
    /// Limited to 3 characters.
    typedef xs::string StationType;

    /// “Stopway” means the length of an area beyond the take-off runway, no less wide than the runway and centered upon the extended centerline of the runway, and designated for use in decelerating the airplane during an aborted takeoff.
    typedef DistanceFeet StopWay;

    /// The TDMA identifies the time slot(s) in which the ground station transmits the related approach.
    /// The high precision time source available through GPS permits utilization of Time division multiplexing or TDMA (Time Division Multiple Access), allowing multiple ground stations to share a common frequency by dividing it into eight time slots.
    /// An individual station may broadcast in one or more of eight slots.
    /// Exactly 2 characters.
    typedef xs::string TDMASlots;

    /// “Theta” is defined as the magnetic bearing to the waypoint identified in the record’s “FIX Ident” field from the Navaid in the “Recommended Navaid” field.
    typedef BearingValue Theta;

    /// The “Threshold Crossing Height” specifies the height above the landing threshold on a normal glide path.
    /// Limited to 3 digits.
    typedef xs::unsignedInt ThresholdCrossingHeight;

    /// The “Time of Operation” field is used to indicate the times of operation of a Facility or Restriction.
    /// See ARINC 424 5.195.
    class TimeOfOperationInterval
    {
      public:
        TimeOfOperationInterval();
        ~TimeOfOperationInterval();

      private:
        /// This field supports specifying the same time interval on multiple days of the week in a single interval instance.
        /// It should not be used if the "dayOfWeek" in the start and end times is specified (see documentation for StartOrEndTime).
        /// If this field is used, and the "end" time is earlier than the "start" time, the time interval crosses midnight (00:00).
        Enum::DayOfWeek dayOfWeek;
        Type::StartOrEndTime start;
        Type::StartOrEndTime end;
    };

    /// Used on airspace, flight planning, communications, and preferred route records to specify the times of operations of those entities.
    class TimesOfOperation
    {
      public:
        TimesOfOperation();
        ~TimesOfOperation();

      private:
        Enum::TimeCode timeCode;
        std::list<Type::TimeOfOperationInterval> times;

        /// The “Time Narrative” field is used to provide Time of Operations and/or Conditions of Operations in a narrative form when source information is too complex to be formatted in accordance with ARINC 424 Section 5.195.
        /// This field is used in conjunction with the TimeCode value "Complex".
        /// This field is used on Airport, Heliport, and Enroute Communication Continuation records.
        xs::string timeNarrative;

        /// Restrictive Airspace areas and communications facilities may not have established active times and are activated by NOTAM only or may be active by NOTAM in addition to established times.
        /// If this field is "True", the area or communcations facility is active by NOTAM in addition to the specified time intervals.
        /// If the the area or communication facility is active by NOTAM only, this field should not be used and the timeCode "ByNotam" should be used.
        /// Used on Controlled and Restrictive Airspace Primary and Continuation records, and Airport, Heliport and Enroute Communications Continuation records.
        xs::boolean byNotam;

        /// Indicates that the "times" instances in this record follow daylight saving time in accordance with the local DST calendar.
        /// See documentation for the "time" field in the StartOrEndTime records.
        xs::boolean adjustForDST;
    };

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
        xs::integer hourOffset; ///< From -14 to +12
        xs::integer minuteOffset;
    };

    /// The “Touchdown Zone Elevation” is the highest elevation in the first 3,000 feet of the landing surface beginning at the threshold.
    typedef xs::integer TouchDownZoneElevation;

    /// The “Transition Altitude” field defines the altitude in the vicinity of an airport or heliport at or below which the vertical position of an aircraft is controlled by reference to altitudes (MSL).
    /// The “Transition Level” field defines the lowest flight level available for use above the transition altitude.
    /// Aircraft descending through the transition layer will use altimeters set to local station pressure, while departing aircraft climbing through the layer will be using standard altimeter setting (QNE) of 29.92 inches of mercury, 1013.2 millibars or 1013.2 hectopascals.
    /// Restricted to a total of 5 digits.
    typedef AltitudeValue TransitionAltitude;

    /// The “Magnetic Bearing” for ILS localizer, MLS Azimuth, MLS Back Azimuth and Runway records is given in the primary record.
    /// This field allows the true bearing to be entered independently of the magnetic variation.
    /// Restricted to 5 digits and 2 decimals.
    typedef CompassValue TrueBearing;

    /// A Universally Unique Identifier (UUID) consists of 32 hexadecimal digits, displayed in 5 groups separated by hyphens, in the form 8-4-4-4-12 for a total of 36 characters (32 digits and 4 hyphens).
    /// For example: 550e8400-e29b-41d4-a716-446655440000.
    /// See RFC 4122 for further details
    /// Pattern: [0-9a-fA-F]{8}-[0-9a-fA-F]{4}-[0-9a-fA-F]{4}-[0-9a-fA-F]{4}-[0-9a-fA-F]{12}
    /// Length: 36
    typedef xs::string UUID;

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

  }
}
