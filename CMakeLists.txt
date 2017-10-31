cmake_minimum_required (VERSION 2.6)
project (Neuron)

set(CMAKE_CXX_FLAGS " -W -Wall -pedantic -std=c++11")

enable_testing()
add_subdirectory(googletest)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable (Neuron neuron.cpp mainneuron.cpp network.cpp)
add_executable (Neuron_unittest neuron.cpp  unittestneuron.cpp)

target_link_libraries(Neuron_unittest gtest gtest_main)
add_test(Neuron_unittest Neuron_unittest)
