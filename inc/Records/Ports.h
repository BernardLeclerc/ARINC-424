#pragma once

#include "AirportGate.h"
#include "AirportHeliportLocalizerMarker.h"
#include "BasicClasses.h"
#include "Communication.h"
#include "FlightPlanning.h"
#include "MSA.h"
#include "Navaids.h"
#include "SIDSTARApproach.h"
#include "TAA.h"
#include "Waypoint.h"
#include "Types/DataTypes.h"
#include "Types/Enumerations.h"
#include <list>

namespace Arinc424
{
  namespace Record
  {
    class TerminalProcedures
    {
      public:
        TerminalProcedures();
        ~TerminalProcedures();

      private:
        std::list<SID> sid;
        std::list<STAR> star;
        std::list<Approach> approach;
    };

    class Helipad : public A424Point
    {
      public:
        Helipad();
        virtual ~Helipad();

      private:
        xs::integer padDimensionX;
        xs::integer padDimensionY;
        xs::integer padRadius;
        Enum::HelipadShape helipadShape;
        Type::MaxHelicopterWeight maximumHelicopterWeight;
        Enum::HelicopterPerformanceReq helicopterPerformanceReq;
    };

    class Port : public A424Point
    {
      public:
        Port();
        virtual ~Port();

      public:
        Type::Elevation elevation; 
        Type::ATAIATADesignator ataIATADesignator;
        Type::DaylightIndicator daylightIndicator;
        Type::IFRCapability ifrCapability;
        Enum::MagneticTrueIndicator magneticTrueIndicator;
        Enum::PublicMilitaryIndicator publicMilitaryIndicator;
        Type::PointReference recommendedNavaid;
        Type::SpeedLimit speedLimit;
        Type::Altitude speedLimitAltitude;
        Type::TimeZone timeZone;
        Type::TransitionAltitude transitionLevel;
        std::list<TerminalNDB> terminalNDB;
        TerminalProcedures terminalProcedures;
        std::list<TerminalWaypoint> terminalWaypoint;
        std::list<TAA> taa;
        std::list<PortCommunication> portCommunication;
        std::list<Helipad> helipad;
        std::list<AirportHeliportLocalizerMarker> localizerMarker;
        std::list<LocalizerGlideslope> localizerGlideslope;
        std::list<GLS> gls;
        std::list<MLS> mls;
        std::list<MSA> msa;
        std::list<FlightPlanningRecords> flightPlanningArrivalDepartureRecords;
        Type::CategoryDistance categoryDistance;
        Type::MaxHelicopterWeight maxHelicopterWeight;
    };

    /// This following record contains the fields used in Runway Records
    class Runway : public A424Point
    {
      public:
        Runway();
        virtual ~Runway();

      private:
        Type::DisplacedThresholdDistance displacedThresholdDistance;
        Type::Elevation landingThresholdElevation;
        Type::EllipsoidHeight ltpEllipsoidHeight;
        Type::PrecisionApproachNavaidReference primaryApproachNavaidReference;
        Type::Bearing runwayBearing;
        Type::TrueBearing runwayTrueBearing;
        Enum::TrueBearingSource runwayTrueBearingSource;
        Type::RunwayDescription runwayDescription;
        Type::RunwayGradient runwayGradient;
        Type::RunwayIdentifier runwayIdentifier;
        Type::RunwayLength runwayLength;
        Type::RunwayWidth runwayWidth;
        Type::PrecisionApproachNavaidReference secondaryApproachNavaidReference;
        Type::StopWay stopway;
        Enum::TCHValueIndicator tchValueIndicator;
        Enum::TDZELocation tdzeLocation;
        Type::ThresholdCrossingHeight thresholdCrossingHeight;
        Type::TouchDownZoneElevation touchDownZoneElevation;
        Enum::SurfaceType surfaceType;
        Type::MaxHelicopterWeight maximumHelicopterWeight;
        Enum::HelicopterPerformanceReq helicopterPerformanceReq;
        Type::DistanceFeetFiveDigits takeOffRunwayAvailable;
        Type::DistanceFeetFiveDigits takeOffDistanceAvailable;
        Type::DistanceFeetFiveDigits accelerateStopDistanceAvailable;
        Type::DistanceFeetFiveDigits landingDistanceAvailable;
        Enum::RunwayUsageIndicator runwayUsageIndicator;

        /// This element indicates runway data elements meet runway accuracy requirements by confirming they are consistent with a trustworthy independent data source.
        class RunwayAccuracy
        {
          public:
            RunwayAccuracy();
            ~RunwayAccuracy();

          private:
            Enum::RunwayAccuracyCompliance runwayAccuracyCompliance;
            Enum::LandingThresholdElevationAccuracyCompliance landingThresholdElevationAccuracyCompliance;
        };
    };

    class Airport : public Port
    {
      public:
        Airport();
        virtual ~Airport();

      public:
        Type::PointReference           controlledASArptIndicator;
        Enum::ControlledASIndicator    controlledASIndicator;
        Type::LongestRunway            longestRunway;
        Enum::LongestRunwaySurfaceCode longestRunwaySurfaceCode;
        std::list<Runway>              runways;
        std::list<AirportGate>         airportGates;
    };

    /// This following record contains the fields used in Heliport Record
    class Heliport : public Port
    {
      public:
        Heliport();
        virtual ~Heliport();

      public:
        /// This element provides information as to what type of heliport the facility is.
        Enum::HeliportType heliportType;
    };
  }
}
