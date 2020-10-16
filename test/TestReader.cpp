// Tests for the Reader class

#include <Reader.h>

#include <gtest/gtest.h>

namespace Arinc424TestSuite
{
  // Make sure that a Reader object can be instantiated on the stack
  TEST(Reader, CreateOnStack)
  {
    Arinc424::Reader reader;
  }

  TEST(Reader, CreateOnHeap)
  {
    Arinc424::Reader *reader = new Arinc424::Reader;
    EXPECT_NE(nullptr, reader);
    delete reader;
  }
} // namespace Arinc424TestSuite
