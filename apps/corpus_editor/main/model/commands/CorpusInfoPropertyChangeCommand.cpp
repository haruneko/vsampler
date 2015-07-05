/**
 * Created by Hal@shurabaP on 2015/06/22.
 * This code is under The BSD 3-Clause License.
 * See more Licence.txt.
 * Copyright (c) 2015 Hal@shurabaP. All rights reserved.
 */
#include "CorpusInfoPropertyChangeCommand.h"

void vsampler::corpus_editor::CorpusInfoPropertyChangeCommand::redo() {
    corpus->setCorpusInfoProperty(newInfo);
}

void vsampler::corpus_editor::CorpusInfoPropertyChangeCommand::undo() {
    corpus->setCorpusInfoProperty(previousInfo);
}
