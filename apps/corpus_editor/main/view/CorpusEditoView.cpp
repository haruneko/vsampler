/**
 * Created by Hal@shurabaP on 2015/07/04.
 * This code is under The BSD 3-Clause License.
 * See more Licence.txt.
 * Copyright (c) 2015 Hal@shurabaP. All rights reserved.
 */
#include "ui_CorpusEditorView.h"
#include "CorpusEditoView.h"

vsampler::corpus_editor::CorpusEditorView::CorpusEditorView(QWidget *parent)
        : QMainWindow(parent), ui(new Ui::CorpusEditorView) {
    ui->setupUi(this);
}

vsampler::corpus_editor::CorpusEditorView::~CorpusEditorView() {
    delete ui;
}
