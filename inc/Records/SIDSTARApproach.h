#pragma once

#include "BasicClasses.h"
#include "Route.h"
#include "Legs.h"
#include "PathPoint.h"

#include "../xs.h"

#include <list>

namespace Arinc424
{
  namespace Record
  {
    /// This abstract element is used to represent elements common to different types of terminal procedures.
    class Procedure : public A424ObjectWithId
    {
      public:
        Procedure();
        virtual ~Procedure();

      private:
        xs::boolean isRnav;
        xs::boolean isHelicopterOnlyProcedure;
        Type::ProcedureDesignAircraftCategories procedureDesignAircraftCategories;
        Type::ProcedureDesignAircraftTypes procedureDesignAircraftTypes;
        xs::boolean isSpecial;
        Type::MagneticVariation procedureDesignMagVar;
        xs::ID referenceID;
    };

    /// This class represents a Transition.
    /// This is the base class for other Transitions for inheriting the attributes of this class.
    class ProcedureRoute : public Route
    {
      public:
        ProcedureRoute();
        virtual ~ProcedureRoute();

      private:
        Type::Altitude transitionAltitudeOrLevel;
        xs::IDREF msaRef;
        std::list<ProcedureLeg> procedureLeg;
    };

    /// This abstract element represents of shared information between SID and STAR Enroute Transitions.
    class ApproachRoute : public ProcedureRoute
    {
      public:
        ApproachRoute();
        virtual ~ApproachRoute();

      private:
        Enum::ApproachQualifier1 qualifier1;
        Enum::ApproachQualifier2 qualifier2;
    };

    /// This class is an abstraction of Approach Transition.
    class ApproachTransition : public ApproachRoute
    {
      public:
        ApproachTransition();
        virtual ~ApproachTransition();

      private:
        Type::MultipleIndicator multipleIndicator;
        xs::IDREF taaReference;
    };

    /// This class is an abstraction of Final Transition.
    class FinalApproach : public ApproachRoute
    {
      public:
        FinalApproach();
        virtual ~FinalApproach();

      private:
        Enum::LevelOfServiceAuthorised fasBlockProvided;
        Enum::LevelOfServiceName fasBlockProvidedLevelOfServiceName;
        xs::boolean isRemoteAltimeterRestricted;
        Enum::LevelOfServiceAuthorised lnavAuthorisedForSBAS;
        Enum::LevelOfServiceName lnavLevelOfServiceName;
        Enum::LevelOfServiceAuthorised lnavVNAVAuthorisedForSBAS;
        Enum::LevelOfServiceName lnavVNAVLevelOfServiceName;
        Type::ThresholdCrossingHeight procedureTCH;
        std::list<Type::RNPLOS> rnpLOS;
    };

    /// This class is an abstraction of Missed Approach Transition.
    class MissedApproach : public ApproachRoute
    {
      public:
        MissedApproach();
        virtual ~MissedApproach();

      private:
        
    };

    /// This class is an abstraction of Approach.
    /// Approach records are represented by this class.
    class Approach : Procedure
    {
      public:
        Approach();
        virtual ~Approach();

      private:
        Enum::ApproachRouteType approachRouteType;
        Enum::GNSSFMSIndicator gnssFMSIndicator;
        GBASPathPoint gbasPathPoint;
        SBASPathPoint sbasPathPoint;
        std::list<ApproachTransition> approachTransition;
        FinalApproach finalApproach;
        std::list<MissedApproach> missedApproach;
        Type::PointReference approachPointRef;
        xs::boolean isRnavVisual;
        xs::boolean isPinsProceedVisually;
        xs::boolean isPinsProceddVfr;
        xs::boolean isLocalizerBackcource;
        Enum::ApproachPbnNavSpec approachPbnNavSpec;
        xs::boolean isPreferredProcedure;
    };

    /// This class is the base class for SID and STAR records.
    /// It contains all the fields that are common to both SID and STAR.
    class SIDSTAR : public Procedure
    {
      public:
        SIDSTAR();
        virtual ~SIDSTAR();

      private:
        xs::boolean isVorDmeRnav; ///< If this element exists and is true then the procedure is VOR/DME RNAV.
        Enum::RnavPbnNavSpec rnavPbnNavSpec; ///< This element indicates that an RNAV PBN navigation specification applies to this procedure
        Enum::RnpPbnNavSpec rnpPbnNavSpec; ///< This element indicates that an RNP PBN navigation specification applies to this procedure
    };

    /// This abstract element represents shared information between SID and STAR Runway Transitions.
    class RunwayTransition : public ProcedureRoute
    {
      public:
        RunwayTransition();
        virtual ~RunwayTransition();

      private:
        Type::Vectoring vectoring; ///< This element provides vectoring information on the route.
        Type::RouteQualifications routeQualifications; ///< This element provides information on qualifications or details on the parent route element.
    };

    /// This element represents a SID runway transition.
    class SIDRunwayTransition : public RunwayTransition
    {
      public:
        SIDRunwayTransition();
        virtual ~SIDRunwayTransition();

      private:
        xs::boolean isFromRunway; ///< True if the SID Runway Transition is from a runway.
    };

    /// This atstract element represents shared information between SID and STAR common routes.
    class CommonRoute : public ProcedureRoute
    {
      public:
        CommonRoute();
        virtual ~CommonRoute();

      private:
        Type::RouteQualifications routeQualifications; ///< This element provides information on qualifications or details on the parent route element.
    };

    /// This element represents a SID common route.
    class SIDCommonRoute : public CommonRoute
    {
      public:
        SIDCommonRoute();
        virtual ~SIDCommonRoute();

      private:
        xs::boolean isFromRunway; ///< If this element exists and is true then the SID Common Route was from a runway.
    };

    /// This abstract element represents shared information between SID and STAR Enroute Transitions.
    class EnrouteTransition : public ProcedureRoute
    {
      public:
        EnrouteTransition();
        virtual ~EnrouteTransition();

      private:
        Type::Vectoring vectoring; ///< This element provides vectoring invormaiton on the route
        Type::RouteQualifications routeQualifications; ///< This element provides information on qualifications or details on the parent route element.
    };

    /// This element represents a SID Enroute Transition.
    class SIDEnrouteTransition : public EnrouteTransition
    {
      public:
        SIDEnrouteTransition();
        virtual ~SIDEnrouteTransition();

      private:
    };

    /// This element represents a standard instrument departure.
    class SID : public SIDSTAR
    {
      public:
        SID();
        virtual ~SID();

      private:
        std::list<SIDRunwayTransition> sidRunwayTransition;
        SIDCommonRoute sidCommonRoute;
        std::list<SIDEnrouteTransition> sidEnrouteTransition;
        xs::boolean isEngineOut;
        xs::boolean IsVector;
        xs::boolean isPInS;
        xs::boolean isPInSProceedVisually;
        xs::boolean isPInSProceedVfr;
    };

    /// This element represents a STAR Runway Transition.
    class STARRunwayTransition : public RunwayTransition
    {
      public:
        STARRunwayTransition();
        virtual ~STARRunwayTransition();

      private:
        /// If this element exists and is true then the STAR Common Route was to a runway.
        xs::boolean isToRunway;
    };

    /// This element represents a STAR enroute transition.
    class STAREnrouteTransition : public EnrouteTransition
    {
      public:
        STAREnrouteTransition();
        virtual ~STAREnrouteTransition();

      private:
        
    };

    /// The element represents a STAR Common Route.
    class STARCommonRoute : public CommonRoute
    {
      public:
        STARCommonRoute();
        virtual ~STARCommonRoute();

      private:
        /// If this element exists and is true then the STAR Common Route was to a runway.
        xs::boolean isToRunway;
    };

    /// This class is an abstraction of STAR.
    /// STAR records are represented by this class.
    class STAR : public SIDSTAR
    {
      public:
        STAR();
        virtual ~STAR();

      private:
        std::list<STARRunwayTransition> starRunwayTransition;
        std::list<STAREnrouteTransition> starEnrouteTransition;
        STARCommonRoute starCommonRoute;
        xs::boolean isContinuousDescent;
    };
  }
}
