/**
 * Created by Hal@shurabaP on 2015/07/07.
 * This code is under The BSD 3-Clause License.
 * See more Licence.txt.
 * Copyright (c) 2015 Hal@shurabaP. All rights reserved.
 */
#include "CorpusInfoTranslatableChangeCommand.h"

vsampler::corpus_editor::CorpusInfoTranslatableChangeCommand::CorpusInfoTranslatableChangeCommand(
        domain::Corpus &corpus,
        const corpus::Language &language,
        const QString &before,
        const QString &after,
        void (domain::EditsCorpusInfo::*func)(const corpus::Language&, const QString &),
        QUndoCommand *parent)
        : QUndoCommand(parent), corpus(corpus), language(language), before(before), after(after), func(func){
}

void vsampler::corpus_editor::CorpusInfoTranslatableChangeCommand::redo() {
    (corpus.*func)(language, after);
}

void vsampler::corpus_editor::CorpusInfoTranslatableChangeCommand::undo() {
    (corpus.*func)(language, before);
}
