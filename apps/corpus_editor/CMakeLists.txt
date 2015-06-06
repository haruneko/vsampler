# Created by Hal@shurabaP
# This code is under The BSD 3-Caluse License.
# See more Licence.txt.
cmake_minimum_required(VERSION 3.1)
project(vsampler_corpus_editor_root)

enable_testing()

add_subdirectory(domain)

add_subdirectory(test)

add_subdirectory(gui)

add_test(vsampler_corpus_editor_test vsampler_corpus_editor_test)
