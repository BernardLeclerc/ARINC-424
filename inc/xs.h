#pragma once

/// This is a helper file with the definitions of XML Schema Types.

#include <string>

namespace xs
{
  typedef double decimal;

  typedef std::string duration;

  typedef std::string ID;

  typedef std::string IDREF;

  typedef int integer;
  
  typedef std::string string;

  typedef unsigned int unsignedInt;

  typedef bool boolean;

  /// Format: hh:mm:ss
  /// Examples:
  ///   09:00:00
  ///   09:30:10.5
  ///   09:45:00Z
  ///   09:45:00-06:00
  ///   09:45:00+04:00
  typedef std::string time;

  /// Format: YYYY-MM-DDThh:mm:ss
  /// Examples:
  ///   2002-05-30T09:00:00
  ///   2002-05-30T09:30:10.5
  ///   2002-05-30T09:30:10Z
  ///   2002-05-30T09:30:10-06:00
  ///   2002-05-30T09:30:10+06:00
  typedef std::string dateTime;

  ///
  typedef string token;

  ///
  typedef token language;

}
