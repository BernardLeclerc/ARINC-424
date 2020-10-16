cmake_minimum_required(VERSION 3.16)

project(
  ARINC-424
  VERSION 0.0.0
  DESCRIPTION "ARINC-424 C++ SDK: Decoders, Librairies, and Utilities"
  HOMEPAGE_URL https://github.com/BernardLeclerc/ARINC-424
  LANGUAGES CXX
  )

add_library(
  Arinc424 SHARED

  inc/Arinc424.h

  inc/File.h src/File.cpp
  inc/Reader.h src/Reader.cpp
  inc/Header.h src/Header.cpp

  inc/Records/Airport.h src/Records/Airport.cpp
  inc/Records/Base.h src/Records/Base.cpp

  inc/Types/DataTypes.h src/Types/DataTypes.cpp
)

target_include_directories(
  Arinc424 PUBLIC inc
)

add_executable(HelloWorld samples/HelloWorld.cpp)
target_link_libraries(HelloWorld Arinc424)

add_executable(Example_01 samples/Example_01.cpp)
target_link_libraries(Example_01 Arinc424)

add_executable(
  TestSuite
  test/TestSuite.cpp
  test/TestReader.cpp
  )
target_link_libraries(
  TestSuite
  Arinc424
  gtest
  pthread
  )
