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

    enum class ControlledASIndicator
    {
      Undefined,
      WithinOrBelowClassC,
      WithinOrBelowCta,
      WithinOrBelowTmsTca,
      WithinOrBelowRadarZone,
      WithinOrBelowClassB
    };

    enum class LongestRunwaySurfaceCode
    {
      Undefined,
      Hard,
      Soft,
      Water
    };
  }
} // namespace Arinc424
