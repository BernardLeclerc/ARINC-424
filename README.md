# Work In Progress (WIP)
My intents are documented below. The repo is not complete yet. And I have no date to provide as to when it will be complete ;-)

# ARINC-424 C++ Decoders, Librairies, and Utilities
The repo contains C++ code to read and write ARINC-424 files in both fixed-size and XML formats.

Up to Supplement 21, the ARINC-424 file format is a pure ASCII text file of exactly 132 characters. Starting with Supplement 22, ARINC-424 files are available in XML format. The code in this repo is able to read and write files in both formats.

# References
ARINC-424 Specification - Available on the ARINC Store

# How to Build
On Linux Ubuntu with Visual Studio Code and CMake.

## Dependencies
GoogleTest:
* In /usr/include: `gtest/gtest.h`
* In /usr/lib: `libgtest.a`

# C++ Namespaces
`Arinc424` is the main namespace; it contains functions and classes that are of general use.

`Arinc424::Record` contains one class per ARINC-424 record defined in chapter 4 of the Specification.

`Arinc424::Type` contains the ARINC-424 data types of chapter 5.

`Arinc424::Enum` contains all ARINC-424 enumerations found in chapter 5.

# Design Principles
Supplement 22 to ARINC-424 introduces an XML format formalized by several XSD schemas; the files and types defining these schemas form the basis of this C++ library. Each `.xsd` file correspond to a pair of `.h/.cpp` files. And most - if not all - complex types defined in these schemas have a matching C++ class.

The _C++ Data Model_ of this SDK closely matches the data model that is proposed by the Specification. `CodeSynthesis XSD` compiler is used to compile the XSDs into C++ Parser Skeletons. See the [Getting Started Guide](https://www.codesynthesis.com/projects/xsd/documentation/cxx/parser/guide/) for an excellent introduction to this open-source XSD/C++ Compiler.

## Folder Structure
The library is organised in the following sets of folders.

* `bin` contains the SDK executables built by the sources, samples, and tests
* `data` contains the data files used by the samples and tests
* `doc` contains the SDK documentation (produced by Doxygen)
* `inc` contains the SDK public headers
* `lib` contains the SDK static libraries
* `samples` contains code to illustrate how to use the SDK
* `src` contains the source files to build the SDK static libraries and executables
* `test` contains the SDK Test Suite (based on the Google Test Framework)