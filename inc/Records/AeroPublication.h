#pragma once

#include "MetaData.h"
#include "Navaids.h"
#include "Ports.h"
#include <list>

namespace Arinc424
{
  namespace Record
  {
    class AeroPublication
    {
      public:
        AeroPublication();
        ~AeroPublication();

        /// True when all lists are empty.
        bool empty() const;

      public:
        std::list<Airport> airports;
        // std::list<Heliport>               heliports;
        // std::list<Airway>                 airways;
        // std::list<EnrouteWaypoint>        enrouteWaypoints;
        std::list<Navaid> vhfNavaids;
        std::list<NDB> ndbs;
        // std::list<CompanyRoute>           companyRoutes;
        // std::list<Airspace>               airspaces;
        // std::list<Alternate>              alternates;
        // std::list<CruisingTable>          crusingTables;
        // std::list<PreferedRoute>          preferedRoutes;
        // std::list<EnrouteCommunication>   enrouteCommunications;
        // std::list<GeographicalReference>  geographicalReferences;
        // std::list<GridMora>               gridMoras;
        // std::list<SupplementalData>       supplementalData;
        // std::list<HoldingPattern>         holdingPatterns;

        MetaData metaData;
    };
  }
}
