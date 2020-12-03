#pragma once

#include "BasicClasses.h"
#include "../Types/DataTypes.h"
#include "../Types/Enumerations.h"
#include "../xs.h"

namespace Arinc424
{
  namespace Record
  {
    /// 
    class LocatorClass
    {
      public:
        LocatorClass();
        ~LocatorClass();

      private:
        Enum::AhLocalizerMarkerLocatorFacility1 ahLocalizerMarkerLocatorFacility1;
        Enum::AhLocalizerMarkerLocatorAddInfo ahLocalizerMarkerLocatorAddInfo;
        Enum::AhLocalizerMarkerLocatorCollocation ahLocalizerMarkerLocatorCollocation;
        Enum::AhLocalizerMarkerLocatorCoverage ahLocalizerMarkerLocatorCoverage;
        Enum::AhLocalizerMarkerLocatorFacility2 ahLocalizerMarkerLocatorFacility2;
        Enum::NavaidWeatherInfo ahLocalizerMarkerWeatherInfo;
    };

    /// The Airport and Heliport Localizer Marker File (PM) contains details of all markers and locators associated with all types of localizers.
    class AirportHeliportLocalizerMarker : A424Point
    {
      public:
        AirportHeliportLocalizerMarker();
        virtual ~AirportHeliportLocalizerMarker();

      private:
        Type::Elevation elevation;
        Type::PointReference localizerReference;
        LocatorClass locatorClass;
        xs::string locatorFacilityCharacteristics;
        Type::Frequency locatorFrequency;
        Enum::MarkerType markerType;
        Type::MinorAxisBearing minorAxisBearing;
        Type::RunwayIdentifier runwayIdentifier;
    };
  }
}