# Created by Hal@shurabaP
# This code is under The BSD 3-Caluse License.
# See more Licence.txt.
cmake_minimum_required(VERSION 3.1)
project(vsampler_dsp)

# configuration for Qt
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)

# cmake options
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++11")

# dependency
find_package(Qt5Core)
get_target_property(QtCore_location Qt5::Core LOCATION)
find_package(Qt5Multimedia)
get_target_property(QtCore_location Qt5::Multimedia LOCATION)

# sub directory
add_subdirectory(world)

# sources
add_library(vsampler_dsp main.cpp value/Contour.cpp value/Contour.h value/SignalBuffer.cpp value/SignalBuffer.h value/Signal.cpp value/Signal.h value/SpectrumBuffer.cpp value/SpectrumBuffer.h value/Spectrum.cpp value/Spectrum.h value/Specgram.cpp value/Specgram.h model/InstantSignalModel.cpp model/InstantSignalModel.h model/WorldSignalModel.cpp model/WorldSignalModel.h model/WorldInstantSignalModel.cpp model/WorldInstantSignalModel.h)

target_link_libraries(vsampler_dsp Qt5::Core Qt5::Multimedia world)

target_include_directories(vsampler_dsp PUBLIC ${CMAKE_CURRENT_SOURCE_DIR} world)
