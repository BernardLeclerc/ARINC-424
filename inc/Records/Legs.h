#pragma once

#include "../Types/DataTypes.h"
#include "../Types/Enumerations.h"

#include "../xs.h"

namespace Arinc424
{
  namespace Record
  {
    class Leg : public A424Record
    {
      public:
        Leg();
        virtual ~Leg();

      private:
        /// For Route Type Records - A route of flight is defined by a series of legs taken in order.
        /// The “Sequence Number” field defines the position of the leg in the sequence defining the route of flight identified in the route identifier field.
        Type::SequenceNumber sequenceNumber;

        Type::PointReference fixRef;
        Type::CoreIdentifier fixIdent;
        Type::CoreIdentifier recNavaidIdent;
        Type::PointReference recNavaidRef;
    };

    /// This class is an abstraction of Procedure Leg.
    /// All the details pertaining to a Procedure leg are captured here.
    class ProcedureLeg : public Leg
    {
      public:
        ProcedureLeg();
        virtual ~ProcedureLeg();

      private:
        /// The "Altitude Description" field will designate whether a waypoint should be crossed "at," "at or above," "at or below" or "at or above to at or below" specified altitudes.
        /// The field is also used to designate recommended altitudes and cases where two distinct altitudes are provided at a single fix.
        Enum::AltitudeDescription altitudeDescription;

        /// The “ARC Radius” field is used to define the radius of a precision turn.
        /// In Terminal Procedures, this is the “Constant Radius To A Fix” Path and Termination, for “RF” Leg.
        /// In Holding Patterns, this is the turning radius, inbound to outbound leg, for RNP Holding.
        /// The ARC Radius field is also used to specify the turn radius of RNP holding patterns included in SID, STAR, and Approach Records as HA, HF, and HM legs.
        Type::ARCRadius arcRadius;

        /// The “ATC Indicator” field will be used to indicate that the altitudes shown in the altitude fields can be modified by ATC or the altitude will be assigned by ATC.
        Enum::ATCIndicator atcIndicator;

        /// In SID, STAR and Approach Procedure records, this field may contain segment distances, along track distances, excursion distances, or DME distances.
        /// The actual content is dependent on the Path and Termination.
        /// For more information on the content, refer to Table Three, Leg Data Fields, in Attachment 5 of the 424 specification.
        Type::LegDistance distance;

        /// In SID, STAR and Approach Procedure records, the field may contain segment distances/along track distances/excursion distances/DME distances or holding pattern timing.
        xs::duration holdTime;

        Type::ProcedureWaypointDescription waypointDescription;

        /// The Terminal Procedure Flight Planning Leg distance is the along track distance required to complete any given leg.
        /// It is used to determine a cumulative track distance for a given terminal procedure for flight planning purposes, from the beginning of the take-off or arrival point to the termination point of the procedure.
        Type::LegDistance legDistance;

        Type::LegInboundIndicator legInboundIndicator;
        Enum::LegInboundOutboundIndicator legInboundOutboundIndicator;

        /// The Path and Termination defines the path geometry for a single record of an ATC terminal procedure.
        Enum::PathAndTermination pathAndTermination;

        /// The “Procedure Design Mag Var Indicator” field is an indication of how procedure design magnetic variation was provided in official source data for the procedure defined in the record/record set.
        Type::MagneticVariation procedureDesignMagVar;

        /// “RHO” is defined as the geodesic distance in nautical miles to the waypoint identified in the record’s “Fix Ident” field from the NAVAID in the “Recommended NAVAID” field.
        Type::Rho rho;

        /// Required Navigation Performance (RNP) is a statement of the Navigation Performance necessary for operation within a defined airspace in accordance with ICAO Annex 15 and/or State published rules.
        Type::RequiredNavigationPerformance rnp;

        /// The “Speed Limit” field defines a speed, expressed in Knots, Indicated (K.I.A.S.), for a fix in a terminal procedure or for an airport or heliport terminal environment.
        Type::SpeedLimit speedLimit;

        /// The "Speed Limit Description" field will designate whether the speed limit coded at a fix in a terminal procedure description is a mandatory, minimum or maximum speed.
        /// For Maximum speeds : The SID Procedure Recordsand Missed Approach Procedures speed limit will apply to all legs up toand including the termination of the leg on which the speed is coded from the beginning of the procedure or a previous speed limit.
        /// If a different speed is coded on a subsequent leg, the limit will be applied for that legand from that leg backwards to the previous terminator which contained a speed limit.
        /// The STAR and Approach Procedure Record speed limit will be applied forward to the end of the arrival(excluding the missed approach procedure) or until superseded by another speed limit.
        /// For Minimum speeds : The SID Procedure Records and Missed Approach Procedures speed limit will be applied forward to the end of the SID or Missed Approach Procedure or until superseded by another speed limit.
        /// The STAR and Approach Procedure Record speed limit will apply to all legs up to and including the termination of the leg on which the speed is coded from the beginning of the procedure or a previous speed limit.
        /// If a different speed is coded on a subsequent leg, the limit will be applied for that legand from that leg backwards to the previous terminator which contained a speed limit.
        /// For Mandatory speeds : The speed requirement shall be met at the fix.
        /// The speed will not be applied to previous legs or applied forward to the next legs of the procedure record.
        Enum::SpeedLimitDescription speedLimitDescription;

        Type::Theta theta;

        /// The “Transition Altitude” field defines the altitude in the vicinity of an airport or heliport at or below which the vertical position of an aircraft is controlled by reference to altitudes (MSL).
        /// The “Transition Level” field defines the lowest flight level available for use above the transition altitude.
        /// Aircraft descending through the transition layer will use altimeters set to local station pressure, while departing aircraft climbing through the layer will be using standard altimeter setting (QNE) of 29.92 inches of mercury, 1013.2 millibars or 1013.2 hectopascals.
        Type::TransitionAltitude transitionAltitudeLevel;

        /// The “Turn Direction” field specifies the direction in which Terminal Procedure turns are to be made.
        /// It is also used to indication direction on course reversals, see Attachment 5 Path and Termination.
        Enum::TurnDirection turnDirection;

        /// This field is used in conjunction with Turn direction to indicate that a turn is required prior to capturing the path defined in a terminal procedure.
        xs::boolean turnDirectionValid;

        Type::VerticalScaleFactor verticalScaleFactor;
        Type::Altitude alt1;
        Type::Altitude alt2;
        Type::Course course;
        Type::CoreIdentifier centerFix;
        Type::PointReference centerFixRef;
    };
  }
}
