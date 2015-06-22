/**
 * Created by Hal@shurabaP on 2015/06/22.
 * This code is under The BSD 3-Clause License.
 * See more Licence.txt.
 * Copyright (c) 2015 Hal@shurabaP. All rights reserved.
 */
#include "PhonemeDeletionCommand.h"

void vsampler::corpus_editor::PhonemeDeletionCommand::redo() {
    corpus->insertPhoneme(pronounce, phonemeMetaInfo);
}

void vsampler::corpus_editor::PhonemeDeletionCommand::undo() {
    corpus->deletePhoneme(pronounce, phonemeMetaInfo);
}
