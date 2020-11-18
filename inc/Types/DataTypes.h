#pragma once

#include "Enumerations.h"

#include "../xs.h"

#include <string>

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
    typedef std::string ATAIATADesignator;

    ///Restricted to 6 digits and 3 fraction digits
    typedef xs::decimal DistanceNMThousanths;

    /// The “ARC Radius” field is used to define the radius of a precision turn.
    /// In Terminal Procedures, this is the “Constant Radius To A Fix” Path and Termination, for “RF” Leg.
    /// In Holding Patterns, this is the turning radius, inbound to outbound leg, for RNP Holding.
    /// The ARC Radius field is also used to specify the turn radius of RNP holding patterns included in SID, STAR, and Approach Records as HA, HF, and HM legs.
    typedef DistanceNMThousanths ARCRadius;

    /// The “Core Identifier” field contains the character-name-code, or other series of characters, with which the object is identified.
    /// This includes Waypoint Identifiers, VHF NAVAID Identifiers, NDB NAVAID identifier, Airport Identifiers, Runway Identifiers, and other objects.
    typedef std::string CoreIdentifier;

    /// The “Customer Area Code” field permits the categorization of standard records by geographical area and of tailored records by the airlines for whom they are provided in the master file.
    /// Several record types do not adhere to the established geographical boundaries.
    /// There is no “AREA” in such records.
    typedef std::string CustomerCode;

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
    typedef std::string CycleDate;

    /// The “Daylight” Time Indicator” field is used to indicate if the airport observes Daylight or Summer time when such time changes are in effect for the country or state the airport resides in.
    typedef bool DaylightIndicator;

    /// Restricted to 4 digits and 1 fraction digit.
    typedef xs::decimal DistanceNM;

    /// Elevation of the respective feature.
    /// Restricted to the range -1500 to 20000
    typedef int Elevation;

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

    /// This element provides the 2 character code to identify a state
    typedef std::string IcaoCode;

    /// The “IFR Capability” field indicates if the Airport/Heliport has any published Instrument Approach Procedures.
    typedef bool IFRCapability;

    /// This is an abstract class that is the parent class for degrees.
    typedef int LatLongDegree;

    /// Contains degrees of a coordinate as an integer from 0 to 90.
    typedef LatLongDegree LatDegree;

    /// Contains degrees of a coordinate as an integer from 0 to 180.
    typedef LatLongDegree LongDegree;

    /// Leg distance element used on procedure and airway legs, and terminal procedure flight planning records.
    typedef DistanceNM LegDistance;

    ///
    typedef xs::string LegInboundIndicator;

    typedef unsigned int LongestRunway;

    /// The “Name” field defines the name commonly applied to the navigation entity defined in the record.
    /// The field is restricted to a maximum of 50 characters.
    typedef std::string Name;

    ///
    typedef std::string NotesText;

    ///
    typedef std::string PointReference;

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
    typedef double MagneticVariationValue;

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
    class NdbNavaidClass
    {
      public:
        NdbNavaidClass();
        ~NdbNavaidClass();

      private:
        bool isBFORequired; ///< BFO Operation.  Use of Beat Frequency Oscillator type of equipment is required to received an aural identification signal.
        Enum::NdbNavaidCoverage ndbNavaidCoverage;
        Enum::NdbNavaidIfMarkerInfo ndbNavaidIfMarker;
        Enum::NdbNavaidType ndbNavaidType;
        Enum::NavaidWeatherInfo ndbNavaidWeatherInfo;
        bool isNoVoice;
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

    /// The Facility Characteristics field identifies the characteristics of the NAVAID facility.
    typedef xs::unsignedInt RepetitionRate;

    /// “RHO” is defined as the geodesic distance in nautical miles to the waypoint identified in the record’s “Fix Ident” field from the NAVAID in the “Recommended NAVAID” field.
    typedef DistanceNM Rho;

    /// For Route Type Records - A route of flight is defined by a series of records taken in order.
    /// The “Sequence Number” field defines the location of the record in the sequence defining the route of flight identified in the route identifier field.
    /// For Boundary Type Records - A boundary is defined by a series of records taken in order.
    /// The “Sequence Number” field defines the location of the record in the sequence defining a boundary. For Record Types requiring more than one primary record to define the complete content – In a series of records used to define a complete condition, the “Sequence Number” is used to define each primary record in the sequence. For Airport and Heliport TAA Records – Sequence Number 1 will always be assigned to the record based on the Center Fix upon which the Straight-In Area is predicated, Sequence Number 2 will always be assigned to the record based on the Center Fix upon which the Left Base Area is predicated, and Sequence Number 3 will always be assigned to the record based on the Center Fix upon which the Right Base Area is predicated. Therefore, if a TAA Record has a Straight-In Area and a Right Base Area, but no Left Base Area, only Sequence Numbers 1 and 3 will be used. If a TAA Record has a Straight-In Area and a Left Base Area but no Right Base Area, only Sequence Numbers 1 and 2 will be used.
    /// Restricted to 4 digits.
    typedef unsigned int SequenceNumber;

    /// The Speed Limit field defines a speed, expressed in Knots, Indicated (K.I.A.S.), for a fix in a terminal procedure or for an airport or heliport terminal environment.
    /// Restricted to less than 1000.
    typedef unsigned int SpeedLimit;

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

  } // namespace Type
} // namespace Arinc424
