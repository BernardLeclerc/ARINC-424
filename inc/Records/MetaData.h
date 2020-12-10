#pragma once

#include "Types/DataTypes.h"
#include "xs.h"

namespace Arinc424
{
  namespace Record
  {
    /// Basic Attribute Group which contains the start, end dates of the Cycle and other header Information.
    class MetaData
    {
      public:
        MetaData();
        ~MetaData();

      private:
        xs::dateTime creationDateTime;
        xs::integer cycleDate;
        xs::string databasePartNumber;
        xs::string dataSupplierIdent;
        xs::string desupplierTextField;
        xs::dateTime endOfValidity;
        xs::integer fileCRC;
        xs::string headerIdent;
        xs::language language;
        xs::integer recordCount;
        xs::dateTime startOfValidity;
        xs::string supplierTextField;
        xs::string targetCustomerIdent;
        Type::UUID uuid;
        xs::integer versionNumber;
        Type::UUID codingRuleVersion;
    };
  }
}
