// Tests for the Reader class

#include <Reader.h>
using namespace Arinc424;

#include <gtest/gtest.h>

#include <sstream>
using std::istringstream;

namespace Arinc424TestSuite
{
  TEST(Reader, CreateOnStack)
  {
    Reader reader;
  }

  TEST(Reader, CreateOnHeap)
  {
    Reader *reader = new Reader;
    EXPECT_NE(nullptr, reader);
    delete reader;
  }

  TEST(Reader, LoadFromNullPtr)
  {
    Reader reader;
    ASSERT_FALSE(reader.load(nullptr));
  }

  TEST(Reader, LoadFromFile)
  {
    Reader reader;
    ASSERT_FALSE(reader.load("A file that does not exist"));
  }

  TEST(Reader, LoadFromEmptytream)
  {
    Reader reader;
    istringstream is;
    ASSERT_TRUE(reader.load(is));
  }

  TEST(Reader, InitialState)
  {
    Reader reader;
    File &file = reader.getFile();
    ASSERT_TRUE(file.empty());
    ASSERT_FALSE(file.ok());
  }
}
