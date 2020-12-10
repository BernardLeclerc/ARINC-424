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
    EXPECT_FALSE(file.ok());
    EXPECT_TRUE(file.empty());
    EXPECT_EQ(0, file.getNumRecords());
    EXPECT_EQ(0, file.getNumIncorrectRecords());
    EXPECT_EQ(File::Format::UnknownFormat, file.getInputFormat());
    EXPECT_EQ(File::Format::UnknownFormat, file.getOutputFormat());
  }

  TEST(File, ExtractFromEmptyStream)
  {
    istringstream is;
    File file;
    is >> file;
    EXPECT_TRUE(file.ok());
    EXPECT_FALSE(file.empty());
    EXPECT_EQ(0, file.getNumRecords());
    EXPECT_EQ(0, file.getNumIncorrectRecords());
    EXPECT_EQ(File::Format::FixedLengthFormat, file.getInputFormat()) << "An empty stream is considered as having a Fixed Length format.";
    EXPECT_EQ(File::Format::FixedLengthFormat, file.getOutputFormat()) << "By default, the output format is the same as the input format.";
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
    EXPECT_EQ(File::Format::FixedLengthFormat, file.getInputFormat());
  }
}
