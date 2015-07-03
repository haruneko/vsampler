/**
 * Created by Hal@shurabaP on 2015/06/14.
 * This code is under The BSD 3-Clause License.
 * See more Licence.txt.
 * Copyright (c) 2015 Hal@shurabaP. All rights reserved.
 */
#include "ui_CorpusMetaInfoView.h"
#include "CorpusMetaInfoView.h"

using namespace vsampler::corpus;
using namespace vsampler::corpus_editor;

vsampler::corpus_editor::CorpusMetaInfoView::CorpusMetaInfoView(QWidget *parent)
        : QMainWindow(parent), ui(new Ui::CorpusMetaInfoView) {
    ui->setupUi(this);
}

vsampler::corpus_editor::CorpusMetaInfoView::~CorpusMetaInfoView() {
    delete ui;
}

void vsampler::corpus_editor::CorpusMetaInfoView::set(const vsampler::corpus::CorpusMetaInfo &corpusMetaInfo) {
}

vsampler::corpus::CorpusMetaInfo vsampler::corpus_editor::CorpusMetaInfoView::get() const {
}

void vsampler::corpus_editor::CorpusMetaInfoView::receiveChange(
        const vsampler::corpus::CorpusMetaInfo corpusMetaInfo) {
    set(corpusMetaInfo);
}

void vsampler::corpus_editor::CorpusMetaInfoView::onDataChanged() {
    emit(notifyChange(this->get()));
}
