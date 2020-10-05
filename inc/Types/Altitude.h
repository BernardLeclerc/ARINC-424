// Defines various Altitude types found in Types/DataTypes.xsd
// URL: https://www.aviation-ia.com/support-files/424-22
// Zip: ARINC424_22_XmlSchemas.zip
// Reference: ARINC-424 Supplement 22 XML Schemas

#pragma once

namespace Arinc424
{
  namespace Type
  {
    class Altitude
    {
      public:
        // Default constructor
        Altitude();

        // Destructor
        ~Altitude();

        // 
      private:
        int altitude;
        bool isNotDefined;
        bool isUnknown;
        bool isFlightLevel;
    };
  }
}