#pragma once

namespace Arinc424
{
  namespace Enum
  {
    class AreaCode
    {
      public:
    };

    class RecordType
    {
      public:
    };

    enum ControlledASIndicator
    {
      Undefined,
      WithinOrBelowClassC,
      WithinOrBelowCta,
      WithinOrBelowTmsTca,
      WithinOrBelowRadarZone,
      WithinOrBelowClassB
    };

    enum LongestRunwaySurfaceCode
    {
      Undefined,
      Hard,
      Soft,
      Water
    }
  }
} // namespace Arinc424
