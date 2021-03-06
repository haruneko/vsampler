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
find_package(Qt5Multimedia)
get_target_property(QtCore_location Qt5::Multimedia LOCATION)
find_package(Qt5Widgets)
get_target_property(QtCore_location Qt5::Widgets LOCATION)

# sources
qt5_wrap_ui(QT_CORPUS_EDITOR_UI_HEADERS view/CorpusInfoPropertyView.ui view/CorpusEditorView.ui)
add_library(vsampler_corpus_editor ${QT_CORPUS_EDITOR_UI_HEADERS} main.cpp controller/CorpusInfoEditorController.cpp controller/CorpusInfoEditorController.h model/commands/corpus/phoneme/PhonemeInsertionCommand.cpp model/commands/corpus/phoneme/PhonemeInsertionCommand.h model/commands/corpus/phoneme/PhonemeDeletionCommand.cpp model/commands/corpus/phoneme/PhonemeDeletionCommand.h model/CorpusEditor.cpp model/CorpusEditor.h controller/CorpusEditorController.cpp controller/CorpusEditorController.h model/commands/corpus/info/CorpusInfoLanguageAdditionCommand.cpp model/commands/corpus/info/CorpusInfoLanguageAdditionCommand.h model/commands/corpus/info/CorpusInfoLanguageRemovalCommand.cpp model/commands/corpus/info/CorpusInfoLanguageRemovalCommand.h model/commands/corpus/info/CorpusInfoTranslatableChangeCommand.cpp model/commands/corpus/info/CorpusInfoTranslatableChangeCommand.h model/commands/corpus/info/CorpusInfoStringChangeCommand.cpp model/commands/corpus/info/CorpusInfoStringChangeCommand.h model/CorpusInfoEditor.cpp model/CorpusInfoEditor.h)

target_link_libraries(vsampler_corpus_editor LINK_PUBLIC Qt5::Core Qt5::Gui Qt5::Multimedia Qt5::Widgets vsampler_util vsampler_corpus vsampler_utau vsampler_apps_domain)

target_include_directories(vsampler_corpus_editor PUBLIC ${CMAKE_CURRENT_SOURCE_DIR} vsampler_util vsampler_corpus vsampler_utau vsampler_apps_domain)
