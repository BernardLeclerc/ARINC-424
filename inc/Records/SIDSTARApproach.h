#pragma once

#include "BasicClasses.h"
#include "Route.h"
#include "Legs.h"

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
  }
}
