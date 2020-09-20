// A templated class based on std::string to limit the size of the string to a fixed value.

#pragma once

#include <string>

namespace Arinc424
{
  namespace Type
  {
    template <size_t stringSize>
    class String : public std::string
    {
      public:
        // Default constructor
        String()
        : 
          std::string(stringSize, ' '),
          mStringSize(stringSize)
        {
        }
      private:
        size_t mStringSize;
    };
  }
}