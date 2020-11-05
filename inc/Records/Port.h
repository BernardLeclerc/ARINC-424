#pragma once

#include "BasicClasses.h"
#include "../Types/DataTypes.h"
#include "../Types/Enumerations.h"

#include <list>

namespace Arinc424
{
  namespace Record
  {
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
        TerminalNDB terminalNDB;
        TerminalProcedures terminalProcedures;
        TerminalWaypoint terminalWaypoint;
        TAA taa;
        PortCommunication portCommunication;
        Helipad helipad;
        AirportHeliportLocalizerMarker localizerMarker;
        LocalizerGlideslope localizerGlideslope;
        GLS gls;
        MLS mls;
        MSA msa;
        FlightPlanningRecords flightPlanningArrivalDepartureRecords;
        Type::CategoryDistance categoryDistance;
        Type::MaxHelicopterWeight maxHelicopterWeight;
    };

    class Runway;
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
