// Tests for the File class

#include <File.h>
using namespace Arinc424;

#include <gtest/gtest.h>

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
    ASSERT_FALSE(file.ok());
    ASSERT_TRUE(file.empty());
    ASSERT_EQ(0, file.getNumRecords());
    ASSERT_EQ(0, file.getNumIncorrectRecords());
    ASSERT_EQ(File::Format::UnknownFormat, file.getInputFormat());
  }
} // namespace Arinc424TestSuite
