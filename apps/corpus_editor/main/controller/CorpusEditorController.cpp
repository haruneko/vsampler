/**
 * Created by Hal@shurabaP on 2015/07/04.
 * This code is under The BSD 3-Clause License.
 * See more Licence.txt.
 * Copyright (c) 2015 Hal@shurabaP. All rights reserved.
 */
#include "ui_CorpusEditorView.h"
#include "CorpusEditorController.h"

vsampler::corpus_editor::CorpusEditorController::CorpusEditorController(QWidget *parent)
        : QMainWindow(parent), ui(new Ui::CorpusEditorView) {
    ui->setupUi(this);
}

vsampler::corpus_editor::CorpusEditorController::~CorpusEditorController() {
    delete ui;
}
