/**
 * Created by Hal@shurabaP on 2015/06/22.
 * This code is under The BSD 3-Clause License.
 * See more Licence.txt.
 * Copyright (c) 2015 Hal@shurabaP. All rights reserved.
 */
#include "CorpusEditor.h"

vsampler::corpus_editor::CorpusEditor::CorpusEditor() {
    corpus = new domain::Corpus();
    undoStack = new QUndoStack();

    corpus->connect(corpus, SIGNAL(corpus->corpusLoaded()), undoStack, SLOT(undoStack->clear()));
}

vsampler::corpus_editor::CorpusEditor::~CorpusEditor() {
    delete corpus;
    delete undoStack;
}

QWidget* vsampler::corpus_editor::CorpusEditor::mainWidget() {
    return widget;
}
