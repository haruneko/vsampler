# Created by Hal@shurabaP
# This code is under The BSD 3-Caluse License.
# See more Licence.txt.
cmake_minimum_required(VERSION 3.1)
project(vsampler_utau)

# configuration for Qt
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)

# cmake options
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++11")

# dependency
find_package(Qt5Core)
get_target_property(QtCore_location Qt5::Core LOCATION)

# sources
add_library(vsampler_utau main.cpp value/Voicebank.h value/MetaInfo.h value/VoiceAlias.h reader/VoicebankReader.h reader/impl/VoiceAliasLineReader.cpp reader/impl/VoiceAliasLineReader.h reader/impl/MetaInfoReader.cpp reader/impl/MetaInfoReader.h reader/impl/VoiceAliasesReader.cpp reader/impl/VoiceAliasesReader.h reader/impl/FileUtauVoicebankReader.cpp reader/impl/FileUtauVoicebankReader.h)

target_link_libraries(vsampler_utau LINK_PUBLIC Qt5::Core vsampler_util)

target_include_directories(vsampler_utau PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
