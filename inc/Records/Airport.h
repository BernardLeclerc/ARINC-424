// The Airport class corresponds to the Airport (PA) record defined in section 4.1.7 of the Specification.

#pragma once

#include "Types/String.h"
#include "Types/Altitude.h"
#include <string>

namespace Arinc424
{
  class Airport
  {
    public:
      // Default Constructor - Constructs an empty airport
      Airport();
      
      // Copy constructor - Makes a copy of the specified airport
      Airport(const Airport &airport);

      // Destructor
      ~Airport();

    private:
      // Assignment operator - Not allowed
      Airport &operator=(const Airport&);

    private:
      std::string name;           //
      std::string areaCode;       // Ref 5.3
      std::string icaoId;         // Ref 5.6
      std::string icaoCode;       // Ref 5.14
      std::string iataId;         // Ref 5.107
      Type::Altitude speedLimitAltitude;  // Ref 5.73
      unsigned int  longestRunway;  // Ref 5.54
      bool          ifrCapability;  // Ref 5.108
  };
}
