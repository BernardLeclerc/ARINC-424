#pragma once

#include <ostream>

namespace Arinc424
{
  /// The logger is a singleton
  class Logger
  {
    public:
      /// To obtain a reference to the logger
      static Logger &instance();

      /// To specify the nature of the message
      enum class Level
      {
        Error,
        Warning,
        Info
      };

      /// To log a new message at the selected level
      std::ostream &log(Level level);

    private:
      Logger();
      ~Logger();

      /// The output stream used to log messages; defaults to std::clog
      std::ostream *logStream;
  };

  /// Helper function to shorten
  ///   Arinc424::Logger::instance().log()
  /// into
  ///   Arinc424::log()
  inline std::ostream &log(Logger::Level level)
  {
    return Logger::instance().log(level);
  }

  /// Converts the selected Level enumeration into its corresponding character string
  std::ostream& operator<<(std::ostream& os, Logger::Level level);
}
