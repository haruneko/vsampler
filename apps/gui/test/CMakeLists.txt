# Created by Hal@shurabaP
# This code is under The BSD 3-Caluse License.
# See more Licence.txt.
cmake_minimum_required(VERSION 3.1)
project(vsampler_gui_test)

# configuration for Qt
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)

# cmake options
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++11")

# dependency
include_directories("." "../main")
link_directories("../main")
find_package(Qt5Test)
get_target_property(QtTest_location Qt5::Test LOCATION)

# include main sources.
add_executable(vsampler_gui_test test_main.cpp MultipleTest.cpp MultipleTest.h)

target_link_libraries(vsampler_gui_test
    vsampler_gui
    Qt5::Test
    gmock
)
