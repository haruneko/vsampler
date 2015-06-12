# Created by Hal@shurabaP
# This code is under The BSD 3-Caluse License.
# See more Licence.txt.
cmake_minimum_required(VERSION 3.1)
project(vsampler_util)

# configuration for Qt
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)

# cmake options
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++11")

# dependency
find_package(Qt5Core)
get_target_property(QtCore_location Qt5::Core LOCATION)

# sources
add_library(vsampler_util json/Json.h json/QHashJson.h json/QSetJson.h io/DeviceFactory.cpp io/DeviceFactory.h json/QStringJson.h io/DeviceTextReader.cpp io/DeviceTextReader.h io/DeviceReader.h io/DeviceJsonReader.h io/DeviceWriter.h io/DeviceJsonWriter.h util/Try.h util/Execption.h util/Entity.cpp util/Entity.h io/DirectoryEnumerator.cpp io/DirectoryEnumerator.h)

target_link_libraries(vsampler_util Qt5::Core)

target_include_directories(vsampler_util PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
