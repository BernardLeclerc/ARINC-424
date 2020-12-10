#pragma once

#include "../xs.h"

namespace Arinc424
{
  namespace Enum
  {
    /// The field NDBNavaidAddInfo is the fourth character of the 5 character Navaid class, when used in NDB Navaid Record – NDBs and Terminal NDBs.
    /// It contains additional information on the Navaid.
    enum class AhLocalizerMarkerLocatorAddInfo
    {
      NoVoiceOnFrequency,
      VoiceOnFrequency
    };

    /// The field NDBNavaidCollocation is the fifth character of the 5 character Navaid class, when used in NDB Navaid Record – NDBs and Terminal NDBs.
    /// It contains additional information on the Navaid.
    /// It has information on the Navaid collocation.
    enum class AhLocalizerMarkerLocatorCollocation
    {
      /// BFO Operation.
      /// Use of Beat Frequency Oscillator type of equipment is required to received an aural identification signal.
      BfoOperation,

      /// Locator/Marker Collocated.
      /// The latitude/longitude position of the Locator and Marker are identical.
      LocatorMarkerCollocated,

      /// Locator/Middle Marker Not Collocated.
      /// The latitude/longitude position of Locator and Marker are not identical.
      LocatorMiddleMarkerNotCollocated
    };

    /// The field NDBNavaidCoverage is the first character of the 5 character Navaid class, when used in NDB Navaid Record – NDBs and Terminal NDBs.
    enum class AhLocalizerMarkerLocatorCoverage
    {
      /// Generally usable within 75NM of the facility at all altitudes.
      HighPowerNdb,

      /// Generally usable within 50NM of the facility at all altitudes.
      Ndb,

      /// Generally usable within 25NM of the facility at all altitudes.
      LowPowerNdb,

      /// Generally usable within 15NM of the facility at all altitudes.
      Locator
    };

    /// The field NDBNavaidFacility1 is the first character of the 5 character Navaid class, when used in NDB Navaid Record – NDBs and Terminal NDBs.
    enum class AhLocalizerMarkerLocatorFacility1
    {
      Ndb,
      Sabh,
      MarineBeacon
    };

    /// The field NDBNavaidFacility2 is the second character of the 5 character Navaid class, when used in NDB Navaid Record – NDBs and Terminal NDBs.
    enum class AhLocalizerMarkerLocatorFacility2
    {
      InnerMarker,
      MiddleMarker,
      OuterMarker,
      BackMarker
    };

    /// The "Altitude Description" field will designate whether a waypoint should be crossed "at," "at or above," "at or below" or "at or above to at or below" specified altitudes. The field is also used to designate recommended altitudes and cases where two distinct altitudes are provided at a single fix.
    enum class AltitudeDescription
    {
      AtOrAboveFirst, ///< At or above altitude specified in first Altitude field. Also used with Localizer Only Altitude field and the FACF Waypoint on Precision Approach Procedures with Electronic Glide Slope.
      AtOrBelow, ///< At or below altitude specified in first Altitude field. Also used with Localizer Only Altitude field and the FACF Waypoint on Precision Approach Procedures with Electronic Glide Slope.
      At, ///< At altitude specified in first Altitude field. Also used with Localizer Only Altitude field, and the FACF Waypoint on Precision Approach Coding with Electronic Glide Slope.
      B, ///< At or above to at or below altitudes specified in the first and second Altitude fields. Not used on FAF or MAP Waypoint Records in Precision Approach Coding with Electronic Glide Slope
      C, ///< "At or above" altitude specified in second "Altitude" field.
      G, ///< Glide Slope Altitude (MSL) At Fix, specified in the first Altitude field on the FAF Waypoint and Glide Slope Intercept Altitude (MSL) in second altitude of FAF Waypoint in Precision Approach Coding with electronic Glide Slope.
      I ///< Glide Slope Intercept Altitude specified in second "Altitude" field and "at" altitude specified in first "Altitude" field on the FACF Waypoint in Precision Approach Coding with electronic Glide Slope
    };

    /// This field provides information on the ICAO PBN Navigation Specification appliable to this approach
    enum class ApproachPbnNavSpec
    {
      Rnav1,
      Rnp1,
      RnpAr,
      AdvRnp,
      Rnp0_3,
      PbnUnspecified,
      RnpApch
    };

    /// The “Approach Performance Designator” field is used to indicate the type or category of approach.
    enum class ApproachPerformanceDesignator
    {
      Zero,
      One,
      Two,
      Three,
      Four,
      Five,
      Six,
      Seven
    };

    /// Route Qualifier 1 for Airport Approach (PF) and Heliport (HF) Records – Route Type
    enum class ApproachQualifier1
    {
      RnavVisual,
      DmeRequired,
      GpsRequiredDmeDmeNotAuthorized,
      RnpAr,
      AdvancedRnp,
      Gbas,
      DmeNotRequired,
      GnssRequired,
      GnssorDmeDmeRequired,
      DmeDmeRequired,
      RnavSensorNotSpecified,
      VorDmeRnav,
      RnavRequiresFasDataBlock
    };

    /// Route Type Qualifier 2 for Airport Approach (PF) and Heliport (HF) Records – Route Type
    enum class ApproachQualifier2
    {
      PrimaryMissedApproach,
      SecondaryMissedApproach,
      EngineOutMissedApproach,
      CircleToLandMinimums,
      HelicopterStraightInMinimums,
      HelicopterCircleToLandMinimums,
      HelicopterLandingMinimums,
      StraightInMinimums,
      VmcMinimums
    };

    /// The "Route Type" field defines the type of Airport Approach (PF) and Heliport Approach (HF) Records.
    enum class ApproachRouteType
    {
      LocBackcourse,
      VorDme,
      Fms,
      Igs,
      Rnp,
      Ils,
      Gls,
      LocOnly,
      Mls,
      Ndb,
      Gps,
      NdbDme,
      Rnav,
      VorUsingVorDmeOrVortac,
      Tacan,
      Sdf,
      Vor,
      Lda
    };

    /// The “Customer Area Code” field permits the categorization of standard records by geographical area and of tailored records by the airlines for whom they are provided in the master file.
    /// Several record types do not adhere to the established geographical boundaries.
    /// There is no “AREA” in such records.
    enum class AreaCode
    {
      AFR, ///< Africa
      CAN, ///< Canada
      EEU, ///< Eastern Europe and Asia
      EUR, ///< Europe
      LAM, ///< Latin America
      MES, ///< Middle East
      PAC, ///< Pacific
      SAM, ///< South America
      SPA, ///< South Pacific
      USA  ///< United States
    };

    /// The ATC Indicator field will be used to indicate that the altitudes shown in the altitude fields can be modified by ATC or the altitude will be assigned by ATC.
    enum class ATCIndicator
    {
      ModifiedOrAssigned, ///< Altitude can be modified or assigned by ATC.
      AssignedIfNotProvided ///< Official government source states that the altitude will be assigned by ATC or if no altitude is supplied
    };

    /// The ATC Weight Category field used on Flight Planning Arrival/Departure Data Records is derived from government source and is included whenever a given procedure included in the record is restricted to, or designed for, a specific aircraft weight grouping.
    enum class ATCWeightCategory
    {
      Heavy,  ///< Heavy, all aircraft types of 136,000kg (300000LB) or more.
      Medium, ///< Medium, aircraft types less than 136,000kg (300,000LB) and more than 7,000kg (155,000LB).
      Light,  ///< Light, aircraft types of 7,000kg (155,000LB) or less.
    };

    /// The Communication Class field will designate the major grouping of the Communication Types contained in the record.
    enum class CommunicationClass
    {
      LIRC,
      LIRI,
      USVC,
      ASVC,
      ATCF,
      GNDF,
      AOTF,
      AFAC
    };

    /// The “Communication Type” is a three-character code indicating the type of communications service available on the frequency contained in the record.
    /// Decoding is available in the Communication Type Translation Table.
    enum class CommunicationType
    {
      ACC, ///< Area Control Center
      ACP, ///< Airlift Command Post
      AIR, ///< Air to Air
      APP, ///< Approach Control
      ARR, ///< Arrival Control
      ASO, ///< Automatic Surface Observing System (ASOS)
      ATI, ///< Automatic Terminal Info Service (ATIS)
      AWI, ///< Airport Weather Information Broadcast (AWIB)
      AWO, ///< Automatic Weather Observing Service (AWOS)
      AWS, ///< Aerodrome Weather Information Services (AWIS)
      CBA, ///< Class B Airspace
      CCA, ///< Class C Airspace
      CLD, ///< Clearance Delivery
      CPT, ///< Clearance, Pre-Taxi
      CTA, ///< Control Area (Terminal)
      CTF, ///< Common Traffic Advisory Frequencies (Note 2)
      CTL, ///< Control
      DEP, ///< Departure Control
      DIR, ///< Director (Approach Control Radar)
      EFS, ///< Enroute Flight Advisory Service (EFAS)
      EMR, ///< Emergency
      FSS, ///< Flight Service Station
      GCO, ///< Ground Comm Outlet
      GND, ///< Ground Control
      GTE, ///< Gate Control
      HEL, ///< Helicopter Frequency
      INF, ///< Information
      MBZ, ///< Mandatory Broadcast
      MIL, ///< Military Frequency Zone (note 2)
      MUL, ///< Multicom
      OPS, ///< Operations
      PAL, ///< Pilot Activated Lighting (Note 1)
      RDO, ///< Radio
      RDR, ///< Radar
      RFS, ///< Remote Flight Service Station (RFSS)
      RMP, ///< Ramp/Taxi Control
      RSA, ///< Airport Radar Service Area (ARSA)
      TCA, ///< Terminal Control Area (TCA)
      TMA, ///< Terminal Control Area (TMA)
      TML, ///< Terminal
      TRS, ///< Terminal Radar Service Area (TRSA)
      TWE, ///< Transcriber Weather Broadcast (TWEB)
      TWR, ///< Tower, Air Traffic Control
      UAC, ///< Upper Area Control
      UNI, ///< Unicom
      VOL  ///< Volnet
    };

    enum class ControlledASIndicator
    {
      Undefined,
      WithinOrBelowClassC,
      WithinOrBelowCta,
      WithinOrBelowTmsTca,
      WithinOrBelowRadarZone,
      WithinOrBelowClassB
    };

    enum class DatumCode
    {
      Undefined,
      ADA,
      AFG,
      AIA,
      AIN,
      AMA,
      ANO,
      ANS,
      ARF,
      ARS,
      ASC,
      ASM,
      ASQ,
      ATF,
      AUA,
      AUG,
      BAT,
      BER,
      BID,
      BOO,
      BUR,
      CAC,
      CAI,
      CAO,
      CAP,
      CAZ,
      CCD,
      CGE,
      CHI,
      CHU,
      COA,
      DAL,
      DAN,
      DID,
      DOB,
      EAS,
      ENW,
      EST,
      EUR,
      EUS,
      FAH,
      FLO,
      FOT,
      GAA,
      GAN,
      GEO,
      GIZ,
      GRA,
      GRX,
      GSE,
      GUA,
      HEN,
      HER,
      HIT,
      HJO,
      HKD,
      HTN,
      IBE,
      IDN,
      IGF,
      IND,
      INF,
      ING,
      INH,
      IRL,
      ISG,
      IST,
      JOH,
      KAN,
      KEA,
      KEG,
      KUS,
      LCF,
      LEH,
      LIB,
      LUZ,
      MAS,
      MCN,
      MER,
      MID,
      MIK,
      MIN,
      MOD,
      MOL,
      MPO,
      MVS,
      NAH,
      NAN,
      NAP,
      NAR,
      NAS,
      NSD,
      OEG,
      OGB,
      OHA,
      PAM,
      PDM,
      PHA,
      PIT,
      PLN,
      POS,
      PRD,
      PRP,
      PTB,
      PTN,
      PUK,
      PUR,
      QAT,
      QUO,
      REU,
      RPE,
      RTS,
      SAE,
      SAN,
      SAO,
      SAP,
      SCK,
      SGM,
      SHB,
      SOA,
      SPK,
      SRL,
      STO,
      SYO,
      TAN,
      TDC,
      TIL,
      TOY,
      TRI,
      TRN,
      UNK,
      VOI,
      VOR,
      WAK,
      WGA,
      WGB,
      WGC,
      WGE, /// World Geodetic System 1984
      YAC, /// Yacare
      ZAN  /// Zanderij
    };

    enum class DayOfWeek
    {
      Monday,
      Tuesday,
      Wednesday,
      Thursday,
      Friday,
      Saturday,
      Sunday
    };

    /// The “Distance Description” field will designate whether a communication frequency is to be used from the facility out to a specified distance or from a specified distance and beyond in the Airport Communication Record.
    /// In the VHF Navaid Limitation Continuation Record, the field is used to define whether the limitation applies from the navaid out to a specified distance or from a specified distance and beyond.
    enum class DistanceDescription
    {
      OutToSpecifiedDistance, ///< The communication frequency or navaid limitation is out to a specified distance.
      AppliesBeyondDistance,  ///< The communication frequency is used or the navaid limitation applies beyond a specified distance.
      NoRestriction           ///< No restrictions/limitations apply
    };

    /// This data type indicates if the longitude is east or west.
    enum class EastWest
    {
      East,
      West
    };

    /// The Fix Related Transition Code is used on Flight Planning Arrival/Departure Data Continuation Records containing Intermediate Fix information and provides an indication, through use of the standard coding practices of separating the procedure into transitions, as to where in the procedure the intermediate fix is located.
    enum class FixRelatedTransitionCode
    {
      One,    ///< Fix Located in SID Runway Transition
      Two,    ///< Fix Located in SID Common Portion
      Three,  ///< Fix Located in SID Enroute Transition
      Four,   ///< Fix Located in STAR Enroute Transition
      Five,   ///< Fix Located in STAR Common Portion
      Six,    ///< Fix Located in STAR Runway Transition
    };

    /// Fix Type Enums for the field Name Format Indicator
    enum class FixType
    {
      Abeam,
      BearingDistance,
      AirportName,
      Fir,
      PhoeneticLetterName,
      AirportIdent,
      LatLong,
      MultipleWord,
      Navaid,
      PublishedFiveLetterName,
      PublishedLessThanFiveLetterName,
      AptRwyRelated,
      Uir
    };

    /// The Frequency Units field will designate the frequency spectrum area for the frequency in the Communication Frequency (Section 5.103) field as indicated in the table or will designate the content of the Communication Frequency field as a channel.
    /// For VHF based units, the field will also designate the established frequency spacing required of the frequency for unambiguous use.
    enum class FrequencyUnits
    {
      LowFreq,            ///< Low Frequency
      MediumFreq,         ///< Medium Frequency
      HighFreq,           ///< High Frequency(3000 kHz to 30,000 kHz)
      Vhf100kHzSpacing,   ///< Very High Frequency 100 kHz spacing
      Vhf50kHzSpacing,    ///< Very High Frequency 50 kHz spacing
      Vhf25kHzSpacing,    ///< Very High Frequency 25 kHz spacing
      VhfNonStandard,     ///< Very High Frequency (30,000 kHz to 200 MHz) Non-standard spacing
      Uhf,                ///< Ultra High Frequency (200 MHz to 3000 MHz)
      Vhf8_33Spacing,     ///< Very High Frequency Communication Channel for 8.33kHz spacing
      DigitalService      ///< Digital Service
    };

    ///
    enum class FreqUnitOfMeasure
    {
      megaHertz,
      kiloHertz
    };

    /// The “Operation Type” field indicates whether the operation is an approach procedure, an advanced operation or other operational to be defined later.
    enum class GBASOperationType
    {
      Zero,     ///< Straight-in approach path
      One,      ///< Terminal Area Path definition (not for FAS Datablock)
      Two,      ///< Missed Approach (not for FAS Datablock)
      Three,    ///< Spare
      Four,     ///< Spare
      Five,     ///< Spare
      Six,      ///< Spare
      Seven,    ///< Spare
      Eight,    ///< Spare
      Nine,     ///< Spare
      Ten,      ///< Spare
      Eleven,   ///< Spare
      Twelve,   ///< Spare
      Thirteen, ///< Spare
      Fourteen, ///< Spare
      Fifteen   ///< Spare
    };

    /// The GNSS/FMS Indicator field provides an indication of whether or not the responsible government agency has authorized the overlay of a conventional, ground based approach procedure with the use of a sensor capable of processing GNSS data or if the procedure may be flown with FMS as the primary navigation equipment. The field is also used to indicate when and RNAV procedure has been authorized for GNSS-based vertical navigation.
    enum class GNSSFMSIndicator
    {
      GnssFmsOverlayAuthNotPublished,
      GnssOverlayAuthNavaidOperatingAndMonitored,
      GnssOverlayAuthNoMonitorNavaidAuth,
      GnssOverlayTitleIncludesGpsOrGnss,
      FmsOverlayAuthorized,
      SbasVerticalAuthorized,
      SbasVerticalNotAuthorized,
      SbasVerticalNotPublished,
      StandAloneGNSS,
      SbasVerticalNA,
      OverlayAuthNotPublished,
      PbnRnpGps,
      LocOnlyIls
    };

    /// The “24H Indicator” field is used to indicate whether a communication service frequency is available for use on a continual, i.e. 24 hours a day, seven days a week, basis or not.
    enum class H24Indicator
    {
      Unknown,
      Continious,   ///< Frequency is continually available
      NotContinious ///< Frequency is not continually available
    };

    /// The Helipad Performance Requirement is used to identify any restriction imposed on helicopter performance in order to use a given helipad.
    enum class HelicopterPerformanceReq
    {
      Unknown,
      MultiEngine,
      SingleEngineOnly
    };

    /// The Helipad Shape field defines the geometric shape of a helipad as being either circle, or rectangular.
    /// If the object is a runway the port contains runway elements.
    enum class HelipadShape
    {
      Undefined,
      Circle,
      SquareAndOrRectangle
    };

    /// This field provides information on the type of heliport facility.
    enum class HeliportType
    {
      NotProvided,
      Hospital,
      OilRig,
      Other
    };

    /// The Facility Characteristics field identifies the characteristics of the NAVAID facility.
    enum class ILSBackCourse
    {
      Undefined,
      Usable,
      Unusable,
      Restricted
    };

    /// The “ILSDMELocation” field identifies the characteristics of the NAVAID facility.
    enum class ILSDMELocation
    {
      NotCollocated,        ///< Not collocated with Localizer or Glide Slope
      CollocatedLocalizer,  ///< Collocated with localizer
      CollocatedGlideSlope  ///< Collocated with Glide Slope
    };

    /// Difference between Runway Landing Threshold Elevation (A424 PG 5.68) and runway landing threshold elevation measured with an independent means is 5 meters or less.
    enum class LandingThresholdElevationAccuracyCompliance
    {
      Compliant,
      NotCompliant,
      NotEvaluated
    };

    /// The Leg Inbound/Outbound Indicator is used to identify the Leg Length or Leg Time field values (5.64 or 5.65) as being applicable to either the inbound or the outbound leg of a holding pattern or race track course reversal.
    enum class LegInboundOutboundIndicator
    {
      Inbound,
      Outbound
    };

    ///
    enum class LegTypeCodeSC
    {
      PointToPoint, ///< Straight Point to Point
      Curved        ///< Curved line Flight Track
    };

    ///
    enum class LegTypeTurnIndication
    {
      Left,
      Right
    };

    /// The “Level of Service Authorized” field defines whether the Level of Service designated in an associated field (Section 5.275) is authorized or not authorized for a procedure.
    enum class LevelOfServiceAuthorised
    {
      Authorized,
      NotAuthorized
    };

    /// The “Level of Service Name” field identifies the official procedure level of service based on published procedure operating minimums information for Approach Procedures authorized for SBAS and/or RNP.
    enum class LevelOfServiceName
    {
      LPV,
      LPV200,
      LP,
      LNAV,
      LNAV_VNAV
    };

    /// The “Localizer/Azimuth Position Reference” field indicates whether the antenna is situated beyond the stop end of the runway, ahead of or beyond the approach end of the runway.
    /// The “Back Azimuth Position Reference” field indicates whether the antenna is situated ahead of the approach end of the runway, ahead of or beyond the stop end of the runway.
    enum class LocalizerAzimuthPositionReference
    {
      /// For Localizer and Azimuth positions the field is blank (@) when the antenna is situated beyond the stop end of the runway.
      /// For Back Azimuth positions the field is blank (@) when the antenna is situated ahead of the approach end of the runway.
      cBeyondStopEnd,

      /// For Localizer and Azimuth positions the field contains a plus (+) sign when the antenna is situated ahead of the approach end of the runway.
      /// For Back Azimuth positions the field contains a plus (+) sign when the antenna is situated beyond the stop end of the runway.
      BeforeApproachEnd,

      /// For Localizer and Azimuth positions the field contains a plus (-) sign when the antenna is located off to one side of the runway.
      /// For Back Azimuth positions the field contains a plus (-) sign when it is located off to one side of the runway.
      OffToSide
    };

    /// The localizer Marker Indicator enums for the Name format Indicator Field.
    enum class LocalizerMarkerIndicator
    {
      OfficialFiveLetter,
      NoPublishedFiveLetter
    };

    /// The “Longest Runway Surface Code” field is used to define whether or not there is a hard surface runway at the airport, the length of which is indicated in the Longest Runway field.
    enum class LongestRunwaySurfaceCode
    {
      Undefined,  ///< Undefined, surface material not provided in source
      Hard,       ///< Hard Surface, for example, asphalt or concrete
      Soft,       ///< Soft Surface, for example, gravel, grass or soil
      Water       ///< Water Runway
    };

    /// The field has multiple definitions.
    /// For Airport and Heliport Primary Records, it is used to indicate that all bearing and course detail for that airport are included in the data base with a reference to either Magnetic North or to True North.
    /// The field is blank in Airport Record when the data base contains a mix of magnetic and true bearing or course information for the airport.
    /// The Magnetic/True Indicator field is also used to indicate if the Course From and Course To fields of the Cruise Table record and the Sector Bearing fields of the MSA and TAA record are in magnetic or true degrees.
    enum class MagneticTrueIndicator
    {
      Both,    ///< The field will be blank if details and procedures are provided in both magnetic and true for the airport. In such cases the individual detail or procedure records will contain the magnetic or true information.
      True,    ///< if all detail and procedure for the airport are reported in true bearing
      Magnetic ///< if all detail and procedure for the airport are reported in magnetic bearing
    };

    /// The Magnetic Variation field specifies the angular difference between True North and Magnetic North at the location defined in the record.
    /// Dynamic Magnetic Variation is a computer model derived value and takes location and date into consideration.
    /// For the Station Declination used in some record types, refer to Section 5.66.
    enum class MagneticVariationEWT
    {
      East, ///< Magnetic variation is East of TRUE North
      West, ///< Magnetic variation is West of TRUE North
      True  ///< The element defined in the current record is provided TRUE.
    };

    /// The “Marker Type” field defines the type of marker.
    enum class MarkerType
    {
      IM, ///< Inner Marker
      MM, ///< Middle Marker
      OM, ///< Outer Marker
      BM, ///< Back Marker
      L   ///< Locator at Marker
    };

    ///
    enum class MLSApproachAzimuthScanRate
    {
      /// Where a high-rate approach azimuth guidance is not available, enter blank.
      AzimuthNotAvailable,

      /// Where a high-rate approach azimuth guidance is available, enter “H”.
      AzimuthAvailable
    };

    /// The Facility Characteristics field identifies the characteristics of the NAVAID facility.
    enum class MLSDMELocation
    {
      CollocatedAzimuth,    ///< Collocated with Azimuth
      CollocatedElevation,  ///< Collocated with Elevation
      NotCollocated         ///< Not Collocated with Azimuth or Elevation
    };

    /// The Modulation field will design the type of modulation for the frequency in the Communication Frequency (5.103) field.
    enum class Modulation
    {
      AmFreq, ///< Amplitude Modulated Frequency
      FmFreq  ///< Frequency Modulated Frequency
    };

    /// The Multi-Sector Indicator field is used to indicate that the communication service and frequency are used in more than one defined sector.
    /// The actual sector data will be contained in the primary and continuation records of the affected airport or heliport communication record set.
    enum class MultiSectorIndicator
    {
      MultiSector,      ///< Multi-sector data is published in official government source for the service and frequency
      NotDefined,       ///< There is no defined sector data published for the service and frequency.
      OnlyOneFromSource ///< The official government source has provided only a single defined sector for the service and frequency
    };

    /// The NavaidNDBEmissionType field identifies the characteristics of the NAVAID facility.
    enum class NavaidNDBEmissionType
    {
      UnmodulatedCarrier,
      CarrierKeyed, ///< Carrier keyed, bandwidth less than .1 kHz and/or carrier keyed, bandwidth greater than .1 kHz
      ToneKeyModulation
    };

    /// This data type provides information on weather information that is broadcast from this navaid.
    enum class NavaidWeatherInfo
    {
      AUTOMATED, ///< Automatic Transcribed Weather. The frequency of this Navaid is used for the continuous broadcast of some sort of automated weather system such as AWOS, ASOS, TWEB, AWIB, AWIS.
      SCHEDULED  ///< Broadcast Scheduled Weather. The frequency of this Navaid is used for the scheduled, noncontinuous broadcast of some sort of automated weather system such as VOLMET.
    };

    /// The field NDBNavaidCoverage is the first character of the 5 character Navaid class, when used in NDB Navaid Record – NDBs and Terminal NDBs.
    enum class NdbNavaidCoverage
    {
      HighPowerNdb, ///< High-powered NDB. Generally usable within 75NM of the facility at all altitudes.
      LowPowerNdb,  ///< Low-powered NDB. Generally usable within 25NM of the facility at all altitude.
      Locator,      ///< Locator. Generally usable within 15NM of the facility at all altitudes.
      NDB           ///< NDB. Generally usable within 50NM of the facility at all altitude.
    };

    /// The field NDBNavaidFacility2 is the second character of the 5 character Navaid class, when used in NDB Navaid Record – NDBs and Terminal NDBs.
    enum class NdbNavaidIfMarkerInfo
    {
      InnerMarker,  ///< Inner Marker. There is an Inner Marker beacon at this location.
      MiddleMarker, ///< Middle Marker. There is a Middle Marker beacon at this location.
      OuterMarker,  ///< Outer Marker. There is an Outer Marker beacon at this location.
      BackMarker    ///< Back Marker. There is a Backcourse Marker at this location.
    };

    /// The field NDBNavaidFacility1 is the first character of the 5 character Navaid class, when used in NDB Navaid Record – NDBs and Terminal NDBs.
    /// It indicates the type of navaid represented by the NDB.
    enum class NdbNavaidType
    {
      Ndb,
      Sabh,
      MarineBeacon
    };

    /// This data type indicates if the latitude is north or south.
    enum class NorthSouth
    {
      North,
      South
    };

    /// The Path and Termination defines the path geometry for a single record of an ATC terminal procedure.
    enum class PathAndTermination
    {
      AF, ///< Arc to a Fix
      CA, ///< Course to an Altitude
      CD, ///< Course to a DME Distance
      CF, ///< Course to a Fix
      CI, ///< Course to an Intercept
      CR, ///< Course to a Radial Termination
      FA, ///< Fix to an Altitude
      DF, ///< Distance to a Fix
      FC, ///< Track from a Fix for a Distance
      FD, ///< Track from a Fix to a DME Distance
      FM, ///< From a Fix to a Manual Termination
      HA, ///< Holding with Altitude Termination
      HF, ///< Holding with single circuit terminating at the fix
      HM, ///< Holding with Manual Termination
      IF, ///< Initial Fix
      PI, ///< 045/180 Procedure Turn
      RF, ///< Constant Radius Arc
      TF, ///< Track to a Fix
      VA, ///< Heading to an Altitude Termination
      VD, ///< Heading to a DME Distance Termination
      VI, ///< Heading to an Intercept
      VM, ///< Heading to a Manual Termination
      VR, ///< Heading to a Radial Termination
    };

    /// The Localizer/MLS/GLS Performance Categories have established operating minimums and are listed as Category I, II, and III.
    /// The level of Performance Category does not imply that permission exists to use the facility for landing guidance to that level and does not limit minimal using designated classification.
    /// This field is also used to define the classification, non- ILS/MLS/GLS, and localizer installation such as IGS, LDA, or SDF.
    /// As used in the runway record, there are two fields, one labeled Localizer/MLS/GLS Category/Classification and the other labeled Second Localizer/MLS/GLS Category/Classification.
    enum class PrecisionApproachCategory
    {
      IlsLocOnly,       ///< ILS Localizer Only, No Glideslope
      IlsMlsGlsCat1,    ///< ILS Localizer/MLS/GLS Category I
      IlsMlsGlsCat2,    ///< ILS Localizer/MLS/GLS Category II
      IlsMlsGlsCat3,    ///< ILS Localizer/MLS/GLS Category III
      Igs,              ///< IGS Facility
      LdaGlideslope,    ///< LDA Facility with Glideslope
      LdaNoGlideslope,  ///< LDA Facility, no Glideslope
      SdfGlideslope,    ///< SDF Facility with Glideslope
      SdfNoGlideSlope   ///< SDF Facility, no Glideslope
    };

    /// The Procedure Type field used on Flight Planning Arrival/Departure Data Record is a single character code indication the type of procedure in the record, such as Arrival, Standard Instrument Arrival Route, Approach.
    enum class ProcedureType
    {
      ArrivalInDb,      ///< Arrival Procedure, Available in Database
      ArrivalNotInDb,   ///< Arrival Procedure, Not Available in Database
      DepartureInDb,    ///< Departure Procedure, Available in Database
      DepartureNotInDb, ///< Departure Procedure, Not Available in Database
      StarInDb,         ///< Standard Terminal Arrival Route (STAR), Available in Database
      StarNotInDb,      ///< Standard Terminal Arrival Route (STAR), Not Available in Database
      SidInDb,          ///< Standard Instrument Departure (SID), Available in Database
      SidNotInDb,       ///< Standard Instrument Departure (SID), Not Available in Database
      VectorSidInDb,    ///< Vector SID, Available in Database
      VectorSidNotInDB, ///< Vector SID, Not Available in Database
      ApproachInDb,     ///< Approach Procedure, Available in Database
      ApproachNotInDb   ///< Approach Procedure, Not Available in Database
    };

    /// Airports can be classified into four categories, airports open to the general public, military airports, joint use civil and military, and airports closed to the public.
    /// This field permits these airports to be categorized by their use.
    enum class PublicMilitaryIndicator
    {
      Private,  ///< Airport/Heliport is not open to the public
      Civil,    ///< Airport/Heliport is open to the public
      Military, ///< Airport/Heliport is military airport
      Joint     ///< Airport/Heliport is joint Civil and Military
    };

    /// The Radar field indicates whether or not the communication unit identified in the record has access to and uses information derived from primary or secondary radars while performing the communication service indicated by the Communication Type.
    /// It is not an indication of an operational radar frequency.
    enum class Radar
    {
      PrimaryOrSecondary, ///< Primary or secondary Radar information is available to the service
      No,                 ///< If the Service documentation specifically states that the service does not have access to primary or secondary radar information
      Unknown             ///< If the Source documentation does not provide details on the radar information access for the services
    };

    /// The “Record Type” field content indicates whether the record data are “standard,” i.e., suitable for universal application, or “tailored,” i.e. included on the master file for a single user’s specific purpose.
    /// Record type is set to tailored if any extension points are included in the record or if any ARINC 424 XML schemas are modified.
    enum class RecordType
    {
      Standard,
      Tailored
    };

    /// Indicates that the start or end time is relative to sunset or sunrise.
    enum class RelativeTimeIndicator
    {
      BeforeSunrise,
      AfterSunrise,
      BeforeSunset,
      AfterSunset
    };

    /// The Reporting Code field used on Flight Planning Arrival/Departure Data Records is a simplification of the Waypoint Description concept.
    /// It will provide the information on intermediate waypoints as either Position Report Required (Compulsory Report) or Position Report Not Required (On-Request Report).
    enum class ReportingCode
    {
      Required,   ///< Position Report Required
      NotRequired ///< Position Report Not Required
    };

    /// The RNAV Flag field used on Flight Planning Arrival/Departure Data Records is derived from government source and is included whenever a given procedure included in the record is restricted to, or designed for, aircraft capable of flying RNAV Procedures.
    enum class RNAVFlag
    {
      Yes,  ///< The field will indicate Yes, the procedure is an RNAV procedure.
      No    ///< The field will indicate No, the procedure is NOT an RNAV procedure.
    };

    /// This field provides information on the ICAO PBN Navigation Specification applicable to this procedure.
    enum class RnavPbnNavSpec
    {
      Rnav5,
      Rnav2,
      Rnav1,
      BRnav,
      PRnav,
      PbnUnspecified
    };

    /// 
    enum class RnpLOSAuthorized
    {
      Authorized,
      NotAuthorized
    };

    /// This field provides information on the ICAO PBN Navigation Specification applicable to this procedure.
    enum class RnpPbnNavSpec
    {
      Rnp2,
      Rnp1,
      RnpAr,
      AdvRnp,
      Rnp0_3,
      PbnUnspecified
    };

    /// Accuracy of Runway Length (A424 PG 5.57) is 5 meters (compared to measured length of runway surface - stopways, aligned taxiways and starter extensions excluded, as per A424 runway length definition).
    /// Accuracy of Runway Threshold Position (A424 PG 5.36 and 5.37) is 5 meters (compared to measured runway landing threshold location).
    /// Accuracy of Runway Threshold Displacement Distance (A424 PG 5.69) is 5 meters (compared to measured length of displaced area).
    /// Accuracy of Runway Magnetic Bearing (A424 PG 5.58) and Airport Magnetic Variation (A424 PA 5.39) is such that the runway true bearing accuracy is 0.5 degree (NDB Magnetic Runway Bearing will be converted in runway true bearing using NDB Airport Magnetic Variation, then will be validated by comparison with measured True Bearing of runway).
    enum class RunwayAccuracyCompliance
    {
      Compliant,
      NotCompliant,
      NotEvaluated
    };

    /// Runway Left/Right/Centre Indicator
    enum class RunwayLeftRightCenterType
    {
      Left,
      Right,
      Center
    };

    /// The Runway Usage Indicator field specifies if a Runway is usable for take-off, landing, or both operations.
    /// A value of LandingOnly will require the TORA, TODA, and ASDA to be 0 and the LDA either blank or non-0.
    /// A field content of TakeoffOnly will require the TORA, TODA, and ASDA to be blank or non-0 and the LDA to be 0.
    enum class RunwayUsageIndicator
    {
      LandingOnly,
      TakeoffOnly,
      TakeoffAndLanding
    };

    /// The “Operation Type” field indicates whether the operation is an approach procedure, an advanced operation or other operational to be defined later.
    enum class SBASOperationType
    {
      Zero,     ///< Straight-in or point-in-space approach procedure
      One,      ///< Reserved for future definition
      Two,      ///< Reserved for future definition
      Three,    ///< Spare
      Four,     ///< Spare
      Five,     ///< Spare
      Six,      ///< Spare
      Seven,    ///< Spare
      Eight,    ///< Spare
      Nine,     ///< Spare
      Ten,      ///< Spare
      Eleven,   ///< Spare
      Twelve,   ///< Spare
      Thirteen, ///< Spare
      Fourteen, ///< Spare
      Fifteen   ///< Spare
    };

    /// The “SBAS Service Provider Identifier” field is used to associate the approach procedure to a particular satellite based approach system service provider.
    enum class SBASServiceProviderIdentifier
    {
      Zero,
      One,
      Two,
      Fourteen,
      Fifteen
    };

    /// The Service Indicator field is used to further define the use of the frequency for the specified Communication Type.
    enum class ServiceIndicatorAirportHeliportFrequency
    {
      ATF,  ///< Aerodrome Traffic Frequency (ATF)
      CTAF, ///< Common Traffic Advisory Frequency (CTAF)
      MF,   ///< Mandatory Frequency (MF)
      SF,   ///< Secondary Frequency
    };

    /// The Service Indicator field is used to further define the use of the frequency for the specified Communication Type.
    enum class ServiceIndicatorAirportHeliportInformation
    {
      VDF,              ///< VHF Direction Finding Service (VDF)
      NotEnglish,       ///< Language other than English
      MilitaryUseFreq,  ///< Military Use Frequency
      PCL,              ///< Pilot Controlled Light (PCL)
    };

    /// The Service Indicator field is used to further define the use of the frequency for the specified Communication Type.
    enum class ServiceIndicatorAirportHeliportService
    {
      AAS,                ///< Airport Advisory Service (AAS)
      CARC,               ///< Community Aerodrome Radio Station (CARS)
      DepartureService,   ///< Departure Service (Other than Departure Control Unit)
      FIS,                ///< Flight Information Service (FIS)
      IC,                 ///< Initial Contact (IC)
      ArrivalService,     ///< Arrival Service (Other than Arrival Control Unit)
      AFIS,               ///< Aerodrome Flight Information Service(AFIS)
      TerminalAreaControl ///< Terminal Area Control (Other than dedicated Terminal Control Unit)
    };

    /// High Frequency (HF) signals used in aeronautical communications can be the complete signal or a portion of the signal, called a sideband.
    /// The Signal Emission field will designate for each HF Frequency what emission is used.
    enum class SignalEmission
    {
      A3,             ///< Double Sideband (A3)
      A3a,            ///< Single sideband, reduced carrier (A3A)
      A3b,            ///< Two Independent sidebands (A3B)
      A3h,            ///< Single sideband, full carrier (A3H)
      A3j,            ///< Single sideband, suppressed carrier (A3J)
      LsbCarrierUnk,  ///< Lower (single) sideband, carrier unknown
      UsbCarrierUnk   ///< Upper (single) sideband, carrier unknown
    };

    /// The "Speed Limit Description" field will designate whether the speed limit coded at a fix in a terminal procedure description is a mandatory, minimum or maximum speed.
    /// For Maximum speeds: The SID Procedure Records and Missed Approach Procedures speed limit will apply to all legs up to and including the termination of the leg on which the speed is coded from the beginning of the procedure or a previous speed limit.
    /// If a different speed is coded on a subsequent leg, the limit will be applied for that leg and from that leg backwards to the previous terminator which contained a speed limit.
    /// The STAR and Approach Procedure Record speed limit will be applied forward to the end of the arrival (excluding the missed approach procedure) or until superseded by another speed limit.
    /// For Minimum speeds: The SID Procedure Records and Missed Approach Procedures speed limit will be applied forward to the end of the SID or Missed Approach Procedure or until superseded by another speed limit.
    /// The STAR and Approach Procedure Record speed limit will apply to all legs up to and including the termination of the leg on which the speed is coded from the beginning of the procedure or a previous speed limit.
    /// If a different speed is coded on a subsequent leg, the limit will be applied for that leg and from that leg backwards to the previous terminator which contained a speed limit.
    /// For Mandatory speeds: The speed requirement shall be met at the fix. The speed will not be applied to previous legs or applied forward to the next legs of the procedure record.
    enum class SpeedLimitDescription
    {
      Mandatory, ///< Mandatory Speed, Cross Fix AT speed specified in Speed Limit
      Minimum,
      Maximum
    };

    /// For VHF NAVAIDS, the Station Declination field contains the angular difference between true north and the zero degree radial of the NAVAID at the time the NAVAID was last site checked.
    /// For ILS localizers, the field contains the angular difference between true north and magnetic north at the localizer antenna site at the time the magnetic bearing of the localizer course was established.
    enum class StationDeclinationEWT
    {
      East,
      West,
      True,
      Grid
    };

    /// The Surface Type field defines the predominant surface type of the runway/helipad described in the record
    enum class SurfaceType
    {
      Asphalt,
      AsphaltAndGrass,
      BituminousTarOrAsphalt, ///< Bituminous tar or asphalt and/or oil or bitumen bound, mix-in-place surfaces (often refered to as “earth cement”)
      BrickisLaidOrMortared,
      Clay,
      Concrete,
      ConcreteAndAsphalt,
      ConcreteAndGrass,
      Coral,
      Dirt,
      Grass,
      Gravel,
      Ice,
      Laterite,
      Macadam,
      LandingMat,             ///< Usually made of aluminium
      ProtectiveLaminate,     ///< Usually made of rubber
      Metal,                  ///< Steel or Aluminium
      Mix,                    ///< Non bituminous mix
      Other,
      Paved,                  ///< Generic hard surface
      PiercedSteelPlanking,
      Sand,
      Sealed,
      Silt,
      Snow,
      Soil,
      Stone,
      Tarmac,
      Treated,
      Turf,
      Unknown,
      Unpaved,
      Water
    };

    /// The Fix Position Indicator field contains an indication as to which TAA Initial Approach Fix (IAF) the data in the record applies.
    enum class TAASectorIdentifier
    {
      StraightInOrCenterFix,
      LeftBase,
      RightBase
    };

    /// The TCH Units Indicator field is used in Path Point Records to define the units, Feet or Meters for the Path Point TCH.
    enum class TCHUnitsIndicator
    {
      Feet,
      Meters
    };

    /// The “TCH Value Indicator” field will define which TCH value is provided in the runway record.
    enum class TCHValueIndicator
    {
      TchOfElectronicGlideSlope,  ///< TCH provided in Runway Record is that of the electronic Glide Slope.
      TchRnavToRunway,            ///< TCH provided in Runway Record is that of an RNAV procedure to the runway.
      TchVgsi,                    ///< TCH provided in the Runway Record is that of the VGSI for the runway.
      TchDefaulted                ///< TCH provided in the Runway Record is the default value of 40 or 50 feet (See Section 5.67).
    };

    /// The content of the “TDZE Location” field indicates whether the TDZ elevation was obtained from official government sources or from other sources.
    enum class TDZELocation
    {
      Official,
      LandingThreshold,
      AirportElevation
    };

    /// “Time Code” is used in a Time of Operations Record to indicate how to interpret the other fields in Time of Operations records.
    enum class TimeCode
    {
      ContinuousIncludingHolidays,
      ContinuousExcludingHolidays,
      SpecifiedExcludingHolidays,
      SpecifiedIncludingHolidays,
      Complex,
      ByNotam,
      Unspecified
    };

    /// The content of the source field indicates whether the “True Bearing” is derived from official government sources or from other sources.
    enum class TrueBearingSource
    {
      Official,
      Other
    };

    /// The “Turboprop/Jet Indicator” field used on Flight Planning Arrival/Departure Data Records is included whenever a given procedure, normally a departure, is restricted to, or designed for, aircraft with a specific kind of engines.
    enum class TurbopropJetIndicator
    {
      All,
      JetsAndTurboProps,
      AllCruise250OrLess,
      NonJetAndTurboProp,
      MultiEngineProps,
      Jets,
      NonJetNonTurboprop,
      TurboProp
    };

    /// The “Turn Direction” field specifies the direction in which Terminal Procedure turns are to be made.
    /// It is also used to indication direction on course reversals, see Attachment 5 Path and Termination.
    enum class TurnDirection
    {
      Left,
      Right,
      Either
    };

    /// The Facility Characteristics field identifies the characteristics of the NAVAID facility.
    enum class TypeOfEmission
    {
      type400,
      type1020
    };

  } // namespace Enum
} // namespace Arinc424
