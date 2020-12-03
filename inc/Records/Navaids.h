#pragma once

#include "BasicClasses.h"

#include "../Types/DataTypes.h"
#include "../Types/Enumerations.h"

namespace Arinc424
{
  namespace Record
  {
    ///
    class Navaid : public A424Point
    {
      public:
        Navaid();
        virtual ~Navaid();

      private:
        Type::PointReference portRef; ///< Defines the location of a designated point using a combination of angles and distances based on the guidance service. The set of angles and distances must not under specify the location.
        Type::Elevation elevation;    ///< Elevation of the navaid location in feet.
    };

    ///
    class PrecisionApproachNavaid : public Navaid
    {
      public:
        PrecisionApproachNavaid();
        virtual ~PrecisionApproachNavaid();

      private:
        Type::PrecisionApproachAngle approachAngle;
        Type::Bearing approachCourseBearing;
        Enum::PrecisionApproachCategory category;
        Type::RunwayIdentifier runwayIdentifier;
        Type::PointReference runwayReference;
    };

    /// This record contains a sequential listing of all GNSS Landing Systems (GLS) approaches, including the slope, course and reference path idents of the GLS approach.
    /// A GLS approach is identified by its ident and channel.
    /// Note that several GLS approaches can be supported by a single differential GLS ground station.
    class GLS : PrecisionApproachNavaid
    {
      public:
        GLS();
        virtual ~GLS();

      private:
      /// The service volume radius identifies the radius of the service volume around the transmitter in Nautical miles.
        Type::ServiceVolumeRadius serviceVolumeRadius;

        /// This field identifies the WGS84 elevation of the GLS ground station described in the record.
        Type::StationElevationWGS84 stationElevationWGS84;

        /// The station type identifies the type of the differential ground station.
        /// The first character will be L for LAAS/GLS ground station, C for SCAT-1 station.
        /// The second and third character will be blank for the moment.
        /// They will indicate the interoperability standard to which the station conforms.
        Type::StationType stationType;

        /// The TDMA identifies the time slot(s) in which the ground station transmits the related approach.
        /// The high precision time source available through GPS permits utilization of Time division multiplexing or TDMA (Time Division Multiple Access), allowing multiple ground stations to share a common frequency by dividing it into eight time slots.
        /// An individual station may broadcast in one or more of eight slots.
        Type::TDMASlots tdmsSlots;

        Type::Channel glsChannel;
        Type::ThresholdCrossingHeight thresholdCrossingHeight;
    };

    /// This following record contains the fields used in MLS Back Azimuth Details.
    class MLSBackAzimuthDetails : public A424Point
    {
      public:
        MLSBackAzimuthDetails();
        virtual ~MLSBackAzimuthDetails();

      private:
        Type::TrueBearing azimuthTrueBearing;
        Enum::TrueBearingSource azimuthTrueBearingSource;
        Type::Bearing backAzimuthBearing;
        Type::AzimuthCoverageSectorRightLeft backAzimuthCoverageLeft;
        Type::AzimuthCoverageSectorRightLeft backAzimuthCoverageRight;
        Type::BeamPosition backAzimuthPosition;
        Enum::LocalizerAzimuthPositionReference backAzimuthPositionReference;
        Type::AzimuthProportionalAngleRightLeft backAzimuthProportionalSectorLeft;
        Type::AzimuthProportionalAngleRightLeft backAzimuthProportionalSectorRight;
        Type::TrueBearing backAzimuthTrueBearing;
        Enum::TrueBearingSource backAzimuthTrueBearingSource;
        Type::ThresholdCrossingHeight glidePathHeightAtLandingThreshold;
    };

    /// This record represents a Microwave Landing System, including the Azimuth station, the Elevation station and the Back Azimuth station if installed.
    class MLS : public PrecisionApproachNavaid
    {
      public:
        MLS();
        virtual ~MLS();

      private:
        Type::AzimuthCoverageSectorRightLeft azimuthCoverageLeft;
        Type::AzimuthCoverageSectorRightLeft azimuthCoverageRight;
        Type::BeamPosition azimuthPosition;
        Enum::LocalizerAzimuthPositionReference azimuthPositionReference;
        Type::AzimuthProportionalAngleRightLeft azimuthProportionalAngleLeft;
        Type::AzimuthProportionalAngleRightLeft azimuthProportionalAngleRight;
        Type::ElevationAngleSpan elevationAngleSpan;
        Type::Location elevationLocation;
        Type::BeamPosition elevationPosition;
        MLSBackAzimuthDetails mlsBackAzimuthDetails;
        Type::NominalElevationAngle nominalElevationAngle;
        Type::PointReference supportingFacilityReference;
        Type::Channel mlsChannel;
        Enum::MLSDMELocation mlsDmeLocation;
        Enum::MLSApproachAzimuthScanRate mlsApproachAzimuthScanRate;
    };

    /// This following record contains the fields used in Localizer and Glideslope Records.
    class LocalizerGlideslope : public PrecisionApproachNavaid
    {
      public:
        LocalizerGlideslope();
        virtual ~LocalizerGlideslope();

      private:
        Type::CoreIdentifier approachRouteIdent;
        Type::GlideslopeBeamWidth glideslopeBeamWidth;
        Type::ThresholdCrossingHeight glideslopeHeightAtLandingThreshold;
        Type::Location glideslopeLocation;
        Type::BeamPosition glideslopePosition;
        Type::BeamPosition localizerPosition;
        Enum::LocalizerAzimuthPositionReference localizerPositionReference;
        Type::TrueBearing localizerTrueBearing;
        Enum::TrueBearingSource localizerTrueBearingSource;
        xs::decimal localizerWidth;
        Type::StationDeclination stationDeclination;
        Type::PointReference supportingFacilityReference;
        Type::Frequency localizerGlideslopeFrequency;
        Enum::ILSBackCourse ilsBackCourse;
        Enum::ILSDMELocation ilsDmeLocation;
    };

    ///
    class NDB : public Navaid
    {
      public:
        NDB();
        virtual ~NDB();

      private:
        Type::NdbNavaidClass ndbClass;
        Type::Frequency ndbFrequency;
        Enum::TypeOfEmission typeOfEmission;
        Type::RepetitionRate repetitionRate;
        Enum::NavaidNDBEmissionType navaidNdbEmissionType;
        Type::PointReference dmeRef; ///< This field identifies a reference to a DME navaid which originated in the same source data record as the NDB (i.e. is paired with the NDB)
    };

    /// This following record contains the fields used in NDB NAVAID Primary Records Record
    class TerminalNDB : public NDB
    {
      public:
        TerminalNDB();
        virtual ~TerminalNDB();

      private:
        
    };
  }
}
