// Tests for the FixedLengthParser class

#include <FixedLengthParser.h>
using namespace Arinc424;

#include <gtest/gtest.h>

#include <iostream>
using std::endl;

#include <sstream>
using std::istringstream;
using std::stringstream;

namespace Arinc424TestSuite
{
  TEST(FixedLengthParser, CreateOnStack)
  {
    istringstream is;
    Record::AeroPublication aeroPublication;
    FixedLengthParser fixedLengthParser(is, aeroPublication);
  }

  TEST(FixedLengthParser, CreateOnHeap)
  {
    istringstream is;
    Record::AeroPublication aeroPublication;
    FixedLengthParser *fixedLengthParser = new FixedLengthParser(is, aeroPublication);
    EXPECT_NE(nullptr, fixedLengthParser);
    delete fixedLengthParser;
  }

  TEST(FixedLengthParser, InitialState)
  {
    istringstream is;
    Record::AeroPublication aeroPublication;
    FixedLengthParser fixedLengthParser(is, aeroPublication);
    EXPECT_EQ(0, fixedLengthParser.getNumRecords());
    EXPECT_EQ(0, fixedLengthParser.getNumHeaderRecords());
    EXPECT_EQ(0, fixedLengthParser.getNumIncorrectRecords());
    EXPECT_EQ(0, fixedLengthParser.getNumUnknownRecords());
  }

  TEST(FixedLengthParser, ParseFromEmptyStream)
  {
    istringstream is;
    Record::AeroPublication aeroPublication;
    FixedLengthParser fixedLengthParser(is, aeroPublication);
    EXPECT_TRUE(fixedLengthParser.parse());
  }

  TEST(FixedLengthParser, ParseHeaderRecords)
  {
    stringstream ss;
    ss << "HDR01FAACIFP18      001P013203765622010  20-AUG-202011:12:17  U.S.A. DOT FAA                                                61829262" << endl;
    ss << "HDR02                                 FEDERAL AVIATION ADMINISTRATION                                                               " << endl;
    ss << "HDR03                                 AERONAUTICAL INFORMATION SERVICES                                                             " << endl;
    ss << "HDR04                                 CODED INSTRUMENT FLIGHT PROCEDURES VOLUME 2010  EFFECTIVE 10 SEP 2020                         " << endl;
    ss << "HDR05                                 REPORT DATA ERRORS TO FAA                 TEL 800 638 8972                                    " << endl;
    Record::AeroPublication aeroPublication;
    FixedLengthParser fixedLengthParser(ss, aeroPublication);
    EXPECT_TRUE(fixedLengthParser.parse());
    EXPECT_EQ(5, fixedLengthParser.getNumRecords());
    EXPECT_EQ(5, fixedLengthParser.getNumHeaderRecords());
    EXPECT_EQ(0, fixedLengthParser.getNumIncorrectRecords());
    EXPECT_EQ(0, fixedLengthParser.getNumUnknownRecords());
  }

  TEST(FixedLengthParser, DetectIncorrectHeaderDate)
  {
    stringstream ss;
    ss << "HDR01FAACIFP18      001P013203765622010  20-ABC-202011:12:17  U.S.A. DOT FAA                                                61829262" << endl;
    Record::AeroPublication aeroPublication;
    FixedLengthParser fixedLengthParser(ss, aeroPublication);
    EXPECT_TRUE(fixedLengthParser.parse());
    EXPECT_EQ(1, fixedLengthParser.getNumRecords());
    EXPECT_EQ(1, fixedLengthParser.getNumHeaderRecords());
    EXPECT_EQ(1, fixedLengthParser.getNumIncorrectRecords());
    EXPECT_EQ(0, fixedLengthParser.getNumUnknownRecords());
  }

  TEST(FixedLengthParser, ParseUnknownRecords)
  {
    stringstream ss;
    ss << "UCANP CYULCYAYUL     010000110Y N45281367W073442736W015000118250      1800018000     MNAR    PIERRE ELLIOTT TRUDEAU INTL   294371507" << endl;
    ss << " CANP CYULCYAYUL     010000110Y N45281367W073442736W015000118250      1800018000     MNAR    PIERRE ELLIOTT TRUDEAU INTL   294371507" << endl;
    Record::AeroPublication aeroPublication;
    FixedLengthParser fixedLengthParser(ss, aeroPublication);
    EXPECT_TRUE(fixedLengthParser.parse());
    EXPECT_EQ(2, fixedLengthParser.getNumRecords());
    EXPECT_EQ(0, fixedLengthParser.getNumHeaderRecords());
    EXPECT_EQ(2, fixedLengthParser.getNumIncorrectRecords());
    EXPECT_EQ(2, fixedLengthParser.getNumUnknownRecords());
  }
}
