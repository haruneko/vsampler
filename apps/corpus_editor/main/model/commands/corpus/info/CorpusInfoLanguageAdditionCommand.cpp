/**
 * Created by Hal@shurabaP on 2015/07/07.
 * This code is under The BSD 3-Clause License.
 * See more Licence.txt.
 * Copyright (c) 2015 Hal@shurabaP. All rights reserved.
 */
#include "CorpusInfoLanguageAdditionCommand.h"

vsampler::corpus_editor::CorpusInfoLanguageAdditionCommand::CorpusInfoLanguageAdditionCommand(domain::Corpus &corpus, const QString &languageString, QUndoCommand *parent)
        : corpus(corpus), language(languageString), QUndoCommand(parent) {
}

void vsampler::corpus_editor::CorpusInfoLanguageAdditionCommand::redo() {
    corpus.add(language);
}
void vsampler::corpus_editor::CorpusInfoLanguageAdditionCommand::undo() {
    corpus.remove(language);
}
