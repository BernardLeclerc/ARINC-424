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
  inc/Types/Enumerations.h                      src/Types/Enumerations.cpp

  inc/Records/AeroPublication.h                 src/Records/AeroPublication.cpp
  inc/Records/AirportGate.h                     src/Records/AirportGate.cpp
  inc/Records/AirportHeliportLocalizerMarker.h  src/Records/AirportHeliportLocalizerMarker.cpp
  inc/Records/BasicClasses.h                    src/Records/BasicClasses.cpp
  inc/Records/Communication.h                   src/Records/Communication.cpp
  inc/Records/FlightPlanning.h                  src/Records/FlightPlanning.cpp
  inc/Records/Legs.h                            src/Records/Legs.cpp
  inc/Records/MetaData.h                        src/Records/MetaData.cpp
  inc/Records/MSA.h                             src/Records/MSA.cpp
  inc/Records/Navaids.h                         src/Records/Navaids.cpp
  inc/Records/PathPoint.h                       src/Records/PathPoint.cpp
  inc/Records/Ports.h                           src/Records/Ports.cpp
  inc/Records/Route.h                           src/Records/Route.cpp
  inc/Records/SIDSTARApproach.h                 src/Records/SIDSTARApproach.cpp
  inc/Records/TAA.h                             src/Records/TAA.cpp
  inc/Records/Waypoint.h                        src/Records/Waypoint.cpp
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
