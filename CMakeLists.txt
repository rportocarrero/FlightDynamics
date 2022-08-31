cmake_minimum_required(VERSION 3.10)
project(FlightDynamics VERSION 0.1)

set(CMAKE_CXX_STANDARD 14)

include_directories(src)

# Set the project name
include_directories(${CMAKE_SOURCE_DIR}/inc)
include_directories(${CMAKE_SOURCE_DIR}/src)
include_directories(${CMAKE_SOURCE_DIR}/test)

# Add gtest
include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG release-1.12.1
)

FetchContent_MakeAvailable(googletest)

enable_testing()
include(CTest)

include(GoogleTest)
gtest_discover_tests(test_Matrix)