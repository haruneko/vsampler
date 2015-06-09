# Created by Hal@shurabaP
# This code is under The BSD 3-Caluse License.
# See more Licence.txt.
cmake_minimum_required(VERSION 3.1)
project(vsampler_apps_domain)

# configuration for Qt
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)

# cmake options
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++11")

# dependency
include_directories(".")
find_package(Qt5Core)
get_target_property(QtCore_location Qt5::Core LOCATION)
find_package(Qt5Multimedia)
get_target_property(QtCore_location Qt5::Multimedia LOCATION)

# sources
add_library(vsampler_apps_domain main.cpp entity/Corpus.cpp entity/Corpus.h repsoitory/CorpusRepository.h entity/UtauVoicebank.cpp entity/UtauVoicebank.h repsoitory/UtauVoicebankRepository.h service/UtauVoicebankConvertService.cpp service/UtauVoicebankConvertService.h)

target_link_libraries(vsampler_apps_domain LINK_PUBLIC Qt5::Core Qt5::Multimedia vsampler_util vsampler_corpus vsampler_utau)

target_include_directories(vsampler_apps_domain PUBLIC ${CMAKE_CURRENT_SOURCE_DIR} vsampler_util vsampler_corpus vsampler_utau)
