# Created by Hal@shurabaP
# This code is under The BSD 3-Caluse License.
# See more Licence.txt.
cmake_minimum_required(VERSION 3.1)
project(vsampler_scores)

# configuration for Qt
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)

# cmake options
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++11")

# dependency
find_package(Qt5Core)
get_target_property(QtCore_location Qt5::Core LOCATION)

# sources
add_library(vsampler_scores value/Event.h value/NoteEvent.h value/ControlChangeEvent.h value/ControlTrack.cpp value/ControlTrack.h value/Track.cpp value/Track.h)

target_link_libraries(vsampler_scores Qt5::Core)
