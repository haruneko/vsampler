/**
 * Created by Hal@shurabaP on 2015/07/07.
 * This code is under The BSD 3-Clause License.
 * See more Licence.txt.
 * Copyright (c) 2015 Hal@shurabaP. All rights reserved.
 */
#include "CorpusInfoStringChangeCommand.h"

vsampler::corpus_editor::CorpusInfoStringChangeCommand::CorpusInfoStringChangeCommand(
        domain::Corpus &corpus,
        const QString &before,
        const QString &after,
        void (domain::EditsCorpusInfo::*func)(const QString &),
        QUndoCommand *parent)
        : QUndoCommand(parent), corpus(corpus), before(before), after(after), func(func){
}

void vsampler::corpus_editor::CorpusInfoStringChangeCommand::redo() {
    (corpus.*func)(after);
}

void vsampler::corpus_editor::CorpusInfoStringChangeCommand::undo() {
    (corpus.*func)(before);
}