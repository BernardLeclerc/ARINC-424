#include "Types/Enumerations.h"
using namespace Arinc424::Enum;
using namespace std;

AreaCode Arinc424::Enum::getAreaCode(const string& areaCode)
{
  if (areaCode == "AFR")
    return AreaCode::AFR;
  else if (areaCode == "CAN")
    return AreaCode::CAN;
  else if (areaCode == "EEU")
    return AreaCode::EEU;
  else if (areaCode == "EUR")
    return AreaCode::EUR;
  else if (areaCode == "LAM")
    return AreaCode::LAM;
  else if (areaCode == "MES")
    return AreaCode::MES;
  else if (areaCode == "PAC")
    return AreaCode::PAC;
  else if (areaCode == "SAM")
    return AreaCode::SAM;
  else if (areaCode == "SPA")
    return AreaCode::SPA;
  else if (areaCode == "USA")
    return AreaCode::USA;
  else
    return AreaCode::Undefined;
}

ostream& Arinc424::Enum::operator<<(ostream& os, AreaCode areaCode)
{
  switch (areaCode)
  {
    case AreaCode::AFR: return os << "AFR";
    case AreaCode::CAN: return os << "CAN";
    case AreaCode::EEU: return os << "EEU";
    case AreaCode::EUR: return os << "EUR";
    case AreaCode::LAM: return os << "LAM";
    case AreaCode::MES: return os << "MES";
    case AreaCode::PAC: return os << "PAC";
    case AreaCode::SAM: return os << "SAM";
    case AreaCode::SPA: return os << "SPA";
    case AreaCode::USA: return os << "USA";
    default:            return os << "   ";
  }
}

RecordType Arinc424::Enum::getRecordType(const char c)
{
  switch (c)
  {
    case 'S': return RecordType::Standard;
    case 'T': return RecordType::Tailored;
    default:  return RecordType::Unknown;
  }
}

ostream& Arinc424::Enum::operator<<(ostream &os, const RecordType &recordType)
{
  switch (recordType)
  {
    case RecordType::Standard: return os << 'S';
    case RecordType::Tailored: return os << 'T';
    default:                   return os << ' ';
  }
}
