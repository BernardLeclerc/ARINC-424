#pragma once

#include "AirportHeliportLocalizerMarker.h"
#include "BasicClasses.h"
#include "Communication.h"
#include "FlightPlanning.h"
#include "MSA.h"
#include "Navaids.h"
#include "SIDSTARApproach.h"
#include "TAA.h"
#include "Waypoint.h"

#include "../Types/DataTypes.h"
#include "../Types/Enumerations.h"

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

      private:
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
    };

    class AirportGate;

    class Airport : public Port
    {
      public:
        Airport();
        virtual ~Airport();

      private:
        Type::PointReference           controlledASArptIndicator;
        Enum::ControlledASIndicator    controlledASIndicator;
        Type::LongestRunway            longestRunway;
        Enum::LongestRunwaySurfaceCode longestRunwaySurfaceCode;
        std::list<Runway>              runways;
        std::list<AirportGate>         airportGates;
    };
  } // namespace Record
} // namespace Arinc424
