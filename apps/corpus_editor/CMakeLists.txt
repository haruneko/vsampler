# Created by Hal@shurabaP
# This code is under The BSD 3-Caluse License.
# See more Licence.txt.
cmake_minimum_required(VERSION 3.1)
project(vsampler_corpus_editor_root)

enable_testing()

add_subdirectory(main)

add_subdirectory(test)

# configuration for Qt
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)

# cmake options
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++11")

# dependency
find_package(Qt5Core)
get_target_property(QtCore_location Qt5::Core LOCATION)
find_package(Qt5Gui)
get_target_property(QtCore_location Qt5::Gui LOCATION)
find_package(Qt5Multimedia)
get_target_property(QtCore_location Qt5::Multimedia LOCATION)
find_package(Qt5Widgets)
get_target_property(QtCore_location Qt5::Widgets LOCATION)

# sources
add_executable(corpus_editor main.cpp)

target_link_libraries(corpus_editor LINK_PUBLIC Qt5::Core Qt5::Gui Qt5::Multimedia Qt5::Widgets vsampler_util vsampler_corpus vsampler_utau vsampler_apps_domain vsampler_corpus_editor)

target_include_directories(corpus_editor PUBLIC ${CMAKE_CURRENT_SOURCE_DIR} vsampler_util vsampler_corpus vsampler_utau vsampler_apps_domain vsampler_corpus_editor)

add_test(vsampler_corpus_editor_test vsampler_corpus_editor_test)
