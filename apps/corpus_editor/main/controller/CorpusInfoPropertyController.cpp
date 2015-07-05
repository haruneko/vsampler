/**
 * Created by Hal@shurabaP on 2015/06/14.
 * This code is under The BSD 3-Clause License.
 * See more Licence.txt.
 * Copyright (c) 2015 Hal@shurabaP. All rights reserved.
 */
#include "ui_CorpusInfoPropertyView.h"

#include "CorpusInfoPropertyController.h"

using namespace vsampler::corpus;
using namespace vsampler::corpus_editor;

vsampler::corpus_editor::CorpusInfoPropertyController::CorpusInfoPropertyController(QWidget *parent)
        : QWidget(parent), ui(new Ui::CorpusInfoPropertyView) {
    ui->setupUi(this);
}

vsampler::corpus_editor::CorpusInfoPropertyController::~CorpusInfoPropertyController() {
    delete ui;
}

void vsampler::corpus_editor::CorpusInfoPropertyController::set(const vsampler::corpus::CorpusInfoProperty &corpus) {
}

vsampler::corpus::CorpusInfoProperty vsampler::corpus_editor::CorpusInfoPropertyController::get() const {
}

void vsampler::corpus_editor::CorpusInfoPropertyController::receiveChange(
        const vsampler::corpus::CorpusInfoProperty corpusInfoProperty) {
    set(corpusInfoProperty);
}

void vsampler::corpus_editor::CorpusInfoPropertyController::onDataChanged() {
    emit(notifyChange(this->get()));
}
