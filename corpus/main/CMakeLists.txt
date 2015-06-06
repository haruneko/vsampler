# Created by Hal@shurabaP
# This code is under The BSD 3-Caluse License.
# See more Licence.txt.
cmake_minimum_required(VERSION 3.1)
project(vsampler_corpus)

# configuration for Qt
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)

# cmake options
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++11")

# dependency
find_package(Qt5Core)
get_target_property(QtCore_location Qt5::Core LOCATION)

# sources
add_library(vsampler_corpus main.cpp value/PhonemeMetaInfo.h value/MusicalContext.h value/CorpusMetaInfo.h value/Pronounce.h value/CorpusProperty.h value/PhonemeSet.h value/Language.h value/json/PhonemeMetaInfoJson.cpp value/json/PhonemeMetaInfoJson.h value/json/MusicalContextJson.cpp value/json/MusicalContextJson.h value/json/CorpusMetaInfoJson.cpp value/json/CorpusMetaInfoJson.h value/json/LanguageJson.cpp value/json/LanguageJson.h value/json/PronounceJson.cpp value/json/PronounceJson.h value/json/CorpusPropertyJson.cpp value/json/CorpusPropertyJson.h)

target_link_libraries(vsampler_corpus LINK_PUBLIC Qt5::Core vsampler_util)

target_include_directories(vsampler_corpus PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
