/**
 * Created by Hal@shurabaP on 2015/06/14.
 * This code is under The BSD 3-Clause License.
 * See more Licence.txt.
 * Copyright (c) 2015 Hal@shurabaP. All rights reserved.
 */
#include "ui_CorpusInfoPropertyView.h"

#include "CorpusInfoEditorController.h"

using namespace vsampler::corpus;
using namespace vsampler::corpus_editor;

vsampler::corpus_editor::CorpusInfoEditorController::CorpusInfoEditorController(QWidget *parent)
        : QWidget(parent), ui(new Ui::CorpusInfoPropertyView) {
    ui->setupUi(this);
}

vsampler::corpus_editor::CorpusInfoEditorController::~CorpusInfoEditorController() {
    delete ui;
}

void vsampler::corpus_editor::CorpusInfoEditorController::set(const vsampler::corpus::CorpusInfoProperty &corpus) {
}

void vsampler::corpus_editor::CorpusInfoEditorController::receiveChange(
        const vsampler::corpus::CorpusInfoProperty corpusInfoProperty) {
    set(corpusInfoProperty);
}
