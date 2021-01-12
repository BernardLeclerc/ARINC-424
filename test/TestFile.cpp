// Tests for the File class

#include <File.h>
using namespace Arinc424;

#include <gtest/gtest.h>

#include <iostream>
using std::endl;

#include <sstream>
using std::istringstream;
using std::stringstream;

namespace Arinc424TestSuite
{
  TEST(File, CreateOnStack)
  {
    File file;
  }

  TEST(File, CreateOnHeap)
  {
    File *file = new File;
    EXPECT_NE(nullptr, file);
    delete file;
  }

  TEST(File, InitialState)
  {
    File file;
    EXPECT_TRUE(file.ok());
    EXPECT_TRUE(file.empty());
    EXPECT_EQ(0, file.getNumRecords());
    EXPECT_EQ(0, file.getNumHeaderRecords());
    EXPECT_EQ(0, file.getNumIncorrectRecords());
    EXPECT_EQ(File::Format::Unknown, file.getInputFormat());
    EXPECT_EQ(File::Format::Unknown, file.getOutputFormat());
  }

  TEST(File, ExtractFromEmptyStream)
  {
    istringstream is;
    File file;
    is >> file;
    EXPECT_TRUE(file.ok());
    EXPECT_TRUE(file.empty());
    EXPECT_EQ(0, file.getNumRecords());
    EXPECT_EQ(0, file.getNumHeaderRecords());
    EXPECT_EQ(0, file.getNumIncorrectRecords());
    EXPECT_EQ(File::Format::FixedLength, file.getInputFormat()) << "An empty stream is considered as having a Fixed Length format.";
    EXPECT_EQ(File::Format::FixedLength, file.getOutputFormat()) << "By default, the output format is the same as the input format.";
  }

  TEST(File, ExtractFromEmptyFixedLengthStream)
  {
    istringstream is;
    File file;
    file.setInputFormat(File::Format::FixedLength);
    is >> file;
    EXPECT_TRUE(file.ok());
    EXPECT_TRUE(file.empty());
    EXPECT_EQ(0, file.getNumRecords());
    EXPECT_EQ(0, file.getNumHeaderRecords());
    EXPECT_EQ(0, file.getNumIncorrectRecords());
    EXPECT_EQ(File::Format::FixedLength, file.getInputFormat());
    EXPECT_EQ(File::Format::Unknown, file.getOutputFormat());
  }

  TEST(File, ExtractFromEmptyXmlStream)
  {
    istringstream is;
    File file;
    file.setInputFormat(File::Format::Xml);
    is >> file;
    EXPECT_FALSE(file.ok()); // TODO: Change to TRUE when XML implemented
    EXPECT_TRUE(file.empty());
    EXPECT_EQ(0, file.getNumRecords());
    EXPECT_EQ(0, file.getNumHeaderRecords());
    EXPECT_EQ(0, file.getNumIncorrectRecords());
    EXPECT_EQ(File::Format::Xml, file.getInputFormat());
    EXPECT_EQ(File::Format::Unknown, file.getOutputFormat());
  }

  TEST(File, ExtractHeaderRecords)
  {
    stringstream ss;
    ss << "HDR01FAACIFP18      001P013203765622010  20-AUG-202011:12:17  U.S.A. DOT FAA                                                61829262" << endl;
    ss << "HDR02                                 FEDERAL AVIATION ADMINISTRATION                                                               " << endl;
    ss << "HDR03                                 AERONAUTICAL INFORMATION SERVICES                                                             " << endl;
    ss << "HDR04                                 CODED INSTRUMENT FLIGHT PROCEDURES VOLUME 2010  EFFECTIVE 10 SEP 2020                         " << endl;
    ss << "HDR05                                 REPORT DATA ERRORS TO FAA                 TEL 800 638 8972                                    " << endl;
    File file;
    ss >> file;
    EXPECT_TRUE(file.ok());
    EXPECT_TRUE(file.empty());
    EXPECT_EQ(5, file.getNumRecords());
    EXPECT_EQ(5, file.getNumHeaderRecords());
    EXPECT_EQ(0, file.getNumIncorrectRecords());
    EXPECT_EQ(File::Format::FixedLength, file.getInputFormat());
    EXPECT_EQ(File::Format::FixedLength, file.getOutputFormat()) << "By default, the output format is the same as the input format.";
  }

  TEST(File, IncorrectHeaderDate)
  {
    stringstream ss;
    ss << "HDR01FAACIFP18      001P013203765622010  20-ABC-202011:12:17  U.S.A. DOT FAA                                                61829262" << endl;
    File file;
    ss >> file;
    EXPECT_TRUE(file.ok());
    EXPECT_TRUE(file.empty());
    EXPECT_EQ(1, file.getNumRecords());
    EXPECT_EQ(1, file.getNumHeaderRecords());
    EXPECT_EQ(1, file.getNumIncorrectRecords());
    EXPECT_EQ(File::Format::FixedLength, file.getInputFormat());
    EXPECT_EQ(File::Format::FixedLength, file.getOutputFormat()) << "By default, the output format is the same as the input format.";
  }

  TEST(File, ExtractOneAirportRecord)
  {
    stringstream ss;
    ss << "SCANP CYULCYAYUL     010000110Y N45281367W073442736W015000118250      1800018000     MNAR    PIERRE ELLIOTT TRUDEAU INTL   294371507" << endl;
    File file;
    ss >> file;
    EXPECT_TRUE(file.ok());
    EXPECT_FALSE(file.empty());
    EXPECT_EQ(1, file.getNumRecords());
    EXPECT_EQ(0, file.getNumIncorrectRecords());
    EXPECT_EQ(File::Format::FixedLength, file.getInputFormat());
    EXPECT_EQ(File::Format::FixedLength, file.getOutputFormat()) << "By default, the output format is the same as the input format.";
  }
}
