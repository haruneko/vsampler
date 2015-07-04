/**
 * Created by Hal@shurabaP on 2015/07/04.
 * This code is under The BSD 3-Clause License.
 * See more Licence.txt.
 * Copyright (c) 2015 Hal@shurabaP. All rights reserved.
 */
#ifndef VSAMPLER_CORPUSEDITOVIEW_H
#define VSAMPLER_CORPUSEDITOVIEW_H

#include <QMainWindow>

namespace Ui {
    class CorpusEditorView;
}

namespace vsampler {
    namespace corpus_editor {

        class CorpusEditorView final : public QMainWindow {
        Q_OBJECT
        public:
            CorpusEditorView(QWidget *parent = 0);
            ~CorpusEditorView();
        private:
            Ui::CorpusEditorView *ui;
        };
    }
}

#endif //VSAMPLER_CORPUSEDITOVIEW_H
