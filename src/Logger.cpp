#include "Logger.h"
using namespace Arinc424;

#include <iostream>
using namespace std;

Logger &Logger::instance()
{
  static Logger logger;
  return logger;
}

Logger::Logger()
:
  logStream(&clog)
{}

Logger::~Logger()
{}

ostream &Logger::log(Logger::Level level)
{
  return *logStream << level << " - ";
}

ostream& Arinc424::operator << (ostream & os, Logger::Level level)
{
  switch (level)
  {
    case Logger::Level::Error:   return os << "Error";
    case Logger::Level::Warning: return os << "Warning";
    case Logger::Level::Info:    return os << "Info";
    default:                     return os << "Level " << int(level);
  }
}
