#pragma once

#include "BasicClasses.h"
#include "Types/DataTypes.h"
#include "Types/Enumerations.h"

namespace Arinc424
{
  namespace Record
  {
    /// Path Point Primary Record Description
    class PathPoint : public A424Record
    {
      public:
        PathPoint();
        virtual ~PathPoint();

      private:
        Enum::ApproachPerformanceDesignator approachPerformanceDesignator;
        Type::CoreIdentifier approachRouteIdentifier;
        Type::ApproachTypeIdentifier approachTypeIdentifier;
        Type::CourseWidthAtThreshold courseWidthAtThreshold;
        Type::FinalApproachSegmentDataCRCRemainder FASDataCRCRemainder;
        Type::HighPrecisionLocation flightPathAlignmentPoint;
        Type::EllipsoidHeight fpapEllipsoidHeight;
        Type::OrthometricHeight fpapOrthometricHeight;
        Type::GlidePathAngle glidePathAngle;
        Type::Channel gnssChannelNumber;
        Type::CourseValue helicopterProcedureCourse;
        Type::HighPrecisionLocation landingThresholdPoint;
        Type::LengthOffset lengthOffset;
        Type::EllipsoidHeight ltpEllipsoidHeight;
        Type::OrthometricHeight ltpOrthometricHeight;
        Type::PathPointTCH pathPointTCH;
        Type::ReferencePathDataSelector referencePathDataSelector;
        Type::ReferencePathIdentifier referencePathIdentifier;
        Type::RouteIndicator routeIndicator;
        Type::RunwayOrPadIdentifier runwayOrPadIdentifier;
        Enum::TCHUnitsIndicator tchUnitsIndicator;
    };

    class GBASPathPoint : public PathPoint
    {
      public:
        GBASPathPoint();
        virtual ~GBASPathPoint();

      private:
        /// The “Operation Type” field indicates whether the operation is an approach procedure, an advanced operation or other operational to be defined later.
        Enum::GBASOperationType operationType;
    };

    class SBASPathPoint : public PathPoint
    {
      public:
        SBASPathPoint();
        virtual ~SBASPathPoint();

      private:
        Type::HorizontalAlertLimit hal;
        Enum::SBASOperationType operationType;
        Enum::SBASServiceProviderIdentifier sbasServiceProviderIdentifier;
        Type::VerticalAlertLimit val;
        Type::Course finalApproachCourse;
    };
  }
}
