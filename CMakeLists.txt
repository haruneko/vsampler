# Created by Hal@shurabaP
# This code is under The BSD 3-Caluse License.
# See more Licence.txt.
cmake_minimum_required(VERSION 3.1)
project(vsampler)

include(ExternalProject)

add_subdirectory(util)

add_subdirectory(utau)

add_subdirectory(scores)

add_subdirectory(corpus)

add_subdirectory(apps)

enable_testing()

