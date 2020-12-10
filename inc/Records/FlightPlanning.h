#pragma once

#include "BasicClasses.h"
#include <list>

namespace Arinc424
{
  namespace Record
  {
    /// The Flight Planning Arrival/Departure Data Record (424 PR record) is used to provide the sub-set of data defining SIDs (PD), STARs (PE) and Approach Procedures (PF) from Section 4.1.9 required for the computer generation of Flight Plans which include Terminal Procedures.
    /// The file contains a sequential listing of published Arrival Procedures, Approach Procedures and Departure Procedures, the available Enroute and Runway Transitions for those procedures, the Transition waypoints, the appropriate along track distance fields and the intermediate fixes along those routes.
    class FlightPlanningRecord : public A424Record
    {
      public:
        FlightPlanningRecord();
        virtual ~FlightPlanningRecord();

      private:
        Type::FlightPlanningAltitude altitude;
        Enum::AltitudeDescription altitudeDescription;
        Type::ATCIdentifier atcIdentifier;
        Enum::ATCWeightCategory atcWeightCategory;
        Type::CommonSegmentDetails commonSegmentDetails;
        Type::SegmentDetails enrouteDetails;
        std::list<Type::IntermediateFixDetails> intermediateFixDetails;
        Type::TimesOfOperation timesOfOperation;
        Type::CruiseTableIdentifier initialCruiseTable;
        Type::Course initialDepartureMagneticCourse;
        Type::LegTypeCode legTypeCode;
        Type::NumberOfEnginesRestriction numberOfEngines;
        Type::PointReference port;
        Type::ProcedureDescription procedureDescription;
        Enum::ProcedureType procedureType;
        Enum::ReportingCode reportingCode;
        Enum::RNAVFlag rnavFlags;
        Type::SegmentDetails runwaySegmentDetails;
        Type::SequenceNumber sequenceNumber;
        Type::CoreIdentifier sidSTARApproachIdentifier;
        Type::SpeedLimit speedLimit;
        Enum::SpeedLimitDescription speedLimitDescription;
        Enum::TurbopropJetIndicator turbopropJetIndicator;
    };

    class FlightPlanningRecords
    {
      public:
        FlightPlanningRecords();
        ~FlightPlanningRecords();

      private:
      std::list<FlightPlanningRecord> flightPlanningRecord;
    };
  }
}
