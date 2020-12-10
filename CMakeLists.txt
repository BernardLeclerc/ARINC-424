cmake_minimum_required(VERSION 3.16)

project(
  ARINC-424
  VERSION 0.0.1
  DESCRIPTION "ARINC-424 C++ SDK: Decoders, Librairies, and Utilities"
  HOMEPAGE_URL https://github.com/BernardLeclerc/ARINC-424
  LANGUAGES CXX
  )

add_library(
  Arinc424 SHARED

  inc/Arinc424.h

  inc/File.h                                    src/File.cpp
  inc/Header.h                                  src/Header.cpp
  inc/Reader.h                                  src/Reader.cpp

  inc/Types/DataTypes.h                         src/Types/DataTypes.cpp
  inc/Types/Enumerations.h

  inc/Records/AeroPublication.h                 src/Records/AeroPublication.cpp
  inc/Records/AirportGate.h
  inc/Records/AirportHeliportLocalizerMarker.h
  inc/Records/BasicClasses.h
  inc/Records/Communication.h
  inc/Records/FlightPlanning.h
  inc/Records/Legs.h
  inc/Records/MetaData.h                        src/Records/MetaData.cpp
  inc/Records/MSA.h
  inc/Records/Navaids.h
  inc/Records/PathPoint.h
  inc/Records/Ports.h
  inc/Records/Route.h
  inc/Records/SIDSTARApproach.h
  inc/Records/TAA.h
  inc/Records/Waypoint.h
)

target_include_directories(
  Arinc424 PUBLIC inc
)

target_include_directories(
  Arinc424 PRIVATE inc
)

add_executable(HelloWorld samples/HelloWorld.cpp)
target_link_libraries(HelloWorld Arinc424)

add_executable(Example_01 samples/Example_01.cpp)
target_link_libraries(Example_01 Arinc424)

add_executable(
  TestSuite
  test/TestFile.cpp
  test/TestReader.cpp
  test/TestSuite.cpp
  )
target_link_libraries(
  TestSuite
  Arinc424
  gtest
  pthread
  )

# The documentation is built with Doxygen
find_package(Doxygen)
set(DOXYGEN_OUTPUT_DIRECTORY ../doc)
doxygen_add_docs(
  Documentation
  inc;src
  COMMENT "Running Doxygen to produce the documentation"
  )
