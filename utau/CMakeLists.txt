# Created by Hal@shurabaP
# This code is under The BSD 3-Caluse License.
# See more Licence.txt.
cmake_minimum_required(VERSION 3.1)
project(vsampler_utau_root)

enable_testing()

add_subdirectory(main)

add_subdirectory(test)

add_test(vsampler_utau_test vsampler_utau_test)
