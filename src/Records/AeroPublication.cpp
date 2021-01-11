#include "Records/AeroPublication.h"
using namespace Arinc424::Record;

AeroPublication::AeroPublication()
{}

AeroPublication::~AeroPublication()
{}

bool AeroPublication::empty() const
{
  return
    airports.empty() &&
    // heliports.empty() &&
    // airways.empty()&&
    // enrouteWaypoints.empty() &&
    vhfNavaids.empty() &&
    ndbs.empty();
    // companyRoutes.empty() &&
    // airspaces.empty() &&
    // alternates.empty() &&
    // crusingTables.empty() &&
    // preferedRoutes.empty() &&
    // enrouteCommunications.empty() &&
    // geographicalReferences.empty() &&
    // gridMoras.empty() &&
    // supplementalData.empty() &&
    // holdingPatterns.empty();
}
