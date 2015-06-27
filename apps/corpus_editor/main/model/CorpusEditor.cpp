/**
 * Created by Hal@shurabaP on 2015/06/22.
 * This code is under The BSD 3-Clause License.
 * See more Licence.txt.
 * Copyright (c) 2015 Hal@shurabaP. All rights reserved.
 */
#include <functional>
#include <QFileDialog>

#include "CorpusEditor.h"

using namespace vsampler::util;

namespace {
    const std::function<Unit(const Exception *, vsampler::corpus_editor::CorpusEditor *)> notifyError =
            [](const Exception *e, vsampler::corpus_editor::CorpusEditor *editor) -> Unit {
                emit(editor->onError(e));
                return Unit();
            };
}

vsampler::corpus_editor::CorpusEditor::CorpusEditor(QObject *parent) : QObject(parent) {
    corpus = new domain::Corpus();
    undos = new QUndoStack();

    widget = new QWidget();
}

vsampler::corpus_editor::CorpusEditor::~CorpusEditor() {
    delete corpus;
    delete undos;
    delete widget;
}

QWidget* vsampler::corpus_editor::CorpusEditor::mainWidget() {
    return widget;
}

QUndoStack* vsampler::corpus_editor::CorpusEditor::undoStack() {
    return undos;
}

void vsampler::corpus_editor::CorpusEditor::open(const QString &filePath) {
    corpus->load(vsampler::domain::CorpusId(filePath)).map<Unit>([this](const Unit &u) -> Unit {
       this->undos->clear();
    }).recover(notifyError);
}

void vsampler::corpus_editor::CorpusEditor::save() {
    corpus->save().recover(notifyError);
}

void vsampler::corpus_editor::CorpusEditor::saveAs(const QString &filePath) {
    corpus->saveAs(vsampler::domain::CorpusId(filePath)).recover(notifyError);
}
