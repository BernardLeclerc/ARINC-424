#pragma once

#include "BasicClasses.h"
#include "../Types/DataTypes.h"
#include "../Types/Enumerations.h"
#include "../xs.h"

#include <list>

namespace Arinc424
{
  namespace Record
  {
    /// The Communication Details record contains the fields used in Communication Continuation Records.
    class CommunicationDetails
    {
      public:
        CommunicationDetails();
        ~CommunicationDetails();

      private:
        Type::PointReference remoteFacility;
        Type::TimesOfOperation timesOfOperation;
        Type::FacilityElevation transmitterSiteElevation;
        Type::MagneticVariation transmitterSiteMagVar;
    };
    
    class Communication : public A424Record
    {
      public:
        Communication();
        virtual ~Communication();

      private:
        Type::Location location;
        Enum::AltitudeDescription altitudeDescription;
        Type::Altitude communicationAltitude1;
        Type::Altitude communicationAltitude2;
        Type::CallSign callSign;
        Enum::CommunicationClass communicationClass;
        Enum::CommunicationType communicationType;
        Enum::FrequencyUnits frequencyUnits;
        Enum::Radar radarService;
        Enum::H24Indicator h24Indicator;
        Enum::Modulation modulation;
        Type::SequenceNumber sequenceNumber;
        Enum::SignalEmission signalEmission;
        Type::Frequency transmitFrequency;
        Type::Frequency receiveFrequency;
        CommunicationDetails communicationDetails;
        xs::string guardTransmit;
    };

    /// This following record contains the fields used in Communication records.
    class PortCommunication : public Communication
    {
      public:
        PortCommunication();
        virtual ~PortCommunication();

      private:
        Type::CommunicationDistance communicationDistance;
        Enum::DistanceDescription distanceDescription;
        Enum::MultiSectorIndicator multiSectorIndicator;
        std::list<Type::SectorizationNarrative> portCommunicationSectorizationNarrative;
        Type::PointReference sectorFacility;
        Type::Sectorization sectorization;
        Type::AirportHeliportCOmmunicationServiceIndicator serviceIndicator;
        std::list<Type::AdditionalSectorization> additionalSectorization;
    };
  }
}
