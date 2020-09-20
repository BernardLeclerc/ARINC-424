// The Arinc424::Reader is the main class to access an ARINC-424 file in either the
// fixed length or XML format.

namespace Arinc424
{
  class Reader
  {
    public:
      Reader();
      ~Reader();

      bool load(const char *file);
  };
} // namespace Arinc424
