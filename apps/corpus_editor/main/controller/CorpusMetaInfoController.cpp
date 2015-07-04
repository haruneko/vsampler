/**
 * Created by Hal@shurabaP on 2015/06/14.
 * This code is under The BSD 3-Clause License.
 * See more Licence.txt.
 * Copyright (c) 2015 Hal@shurabaP. All rights reserved.
 */
#include "ui_CorpusMetaInfoView.h"

#include "CorpusMetaInfoController.h"

using namespace vsampler::corpus;
using namespace vsampler::corpus_editor;

vsampler::corpus_editor::CorpusMetaInfoController::CorpusMetaInfoController(QWidget *parent)
        : QWidget(parent), ui(new Ui::CorpusMetaInfoView) {
    ui->setupUi(this);
}

vsampler::corpus_editor::CorpusMetaInfoController::~CorpusMetaInfoController() {
    delete ui;
}

void vsampler::corpus_editor::CorpusMetaInfoController::set(const vsampler::corpus::CorpusMetaInfo &corpusMetaInfo) {
}

vsampler::corpus::CorpusMetaInfo vsampler::corpus_editor::CorpusMetaInfoController::get() const {
}

void vsampler::corpus_editor::CorpusMetaInfoController::receiveChange(
        const vsampler::corpus::CorpusMetaInfo corpusMetaInfo) {
    set(corpusMetaInfo);
}

void vsampler::corpus_editor::CorpusMetaInfoController::onDataChanged() {
    emit(notifyChange(this->get()));
}
