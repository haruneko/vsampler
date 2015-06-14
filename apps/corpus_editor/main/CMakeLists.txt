# Created by Hal@shurabaP
# This code is under The BSD 3-Caluse License.
# See more Licence.txt.
cmake_minimum_required(VERSION 3.1)
project(vsampler_corpus_editor)

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
find_package(Qt5Widgets)
get_target_property(QtCore_location Qt5::Widgets LOCATION)

# sources
add_library(vsampler_corpus_editor main.cpp view/CorpusMetaInfoView.cpp view/CorpusMetaInfoView.h)

target_link_libraries(vsampler_corpus_editor LINK_PUBLIC Qt5::Core Qt5::Gui Qt5::Widgets vsampler_corpus vsampler_util)
