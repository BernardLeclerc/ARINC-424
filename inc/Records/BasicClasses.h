#pragma once

#include "Types/DataTypes.h"
#include "xs.h"
#include <list>

namespace Arinc424
{
  namespace Record
  {
    class SupplementalData;

    class A424Base
    {
      public:
        A424Base();
        virtual ~A424Base();

        SupplementalData *getSupplementalData();
        void setSupplementalData(SupplementalData *pSupplementalData);

      private:
        SupplementalData *pSupplementalData;
    };

    class A424ObjectWithId : public A424Base
    {
      public:
        A424ObjectWithId();
        virtual ~A424ObjectWithId();

      private:
        Type::CoreIdentifier identifier;
    };

    class A424Record : public A424Base
    {
      public:
        A424Record();
        virtual ~A424Record();

      public:
        Type::CustAreaCode custAreaCode;
        Type::CycleDate cycleDate;
        std::list<Type::NotesText> notes;
        Enum::RecordType recordType;
    };

    class A424Point : public A424Record
    {
      public:
        A424Point();
        virtual ~A424Point();

      public:
        Enum::DatumCode datumCode;
        Type::IcaoCode icaoCode;
        Type::CoreIdentifier identifier;
        Type::Location location;
        Type::MagneticVariation magneticVariation;
        Type::Name name;
        xs::IDREF uirRef;
        xs::IDREF firRef;
        xs::ID referenceID;
    };
  }
}
