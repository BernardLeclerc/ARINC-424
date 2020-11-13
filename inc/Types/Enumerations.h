#pragma once

namespace Arinc424
{
  namespace Enum
  {
    class AreaCode
    {
      public:
    };

    class RecordType
    {
      public:
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

    enum class LongestRunwaySurfaceCode
    {
      Undefined,
      Hard,
      Soft,
      Water
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

    ///
    enum class FreqUnitOfMeasure
    {
      megaHertz,
      kiloHertz
    };

    /// This data type indicates if the latitude is north or south.
    enum class NorthSouth
    {
      North,
      South
    };

    /// This data type indicates if the longitude is east or west.
    enum class EastWest
    {
      East,
      West
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

    /// Airports can be classified into four categories, airports open to the general public, military airports, joint use civil and military, and airports closed to the public.
    /// This field permits these airports to be categorized by their use.
    enum class PublicMilitaryIndicator
    {
      Private,  ///< Airport/Heliport is not open to the public
      Civil,    ///< Airport/Heliport is open to the public
      Military, ///< Airport/Heliport is military airport
      Joint     ///< Airport/Heliport is joint Civil and Military
    };

    /// The Facility Characteristics field identifies the characteristics of the NAVAID facility.
    enum class TypeOfEmission
    {
      type400,
      type1020
    };

  } // namespace Enum
} // namespace Arinc424
