#pragma once

#include "BasicClasses.h"

namespace Arinc424
{
  namespace Record
  {
    class Waypoint : public A424Point
    {
      public:
        Waypoint();
        virtual ~Waypoint();

      private:
        Type::NameFormatIndicator nameFormatIndicator;
        Type::WaypointType waypointType;
        Type::WaypointUsage waypointUsage;
    };

    /// This following record contains the fields used in Waypoint Record
    class TerminalWaypoint : public Waypoint
    {
      public:
        TerminalWaypoint();
        virtual ~TerminalWaypoint();

      private:
    };
  }
}
