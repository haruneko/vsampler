/**
 * Created by Hal@shurabaP on 2015/06/14.
 * This code is under The BSD 3-Clause License.
 * See more Licence.txt.
 * Copyright (c) 2015 Hal@shurabaP. All rights reserved.
 */
#ifndef VSAMPLER_METAINFOVIEW_H
#define VSAMPLER_METAINFOVIEW_H

#include <QWidget>

#include "value/CorpusInfoProperty.h"

namespace Ui {
    class CorpusInfoPropertyView;
}

namespace vsampler {
namespace corpus_editor {

    class CorpusInfoEditorController final : public QWidget {
        Q_OBJECT
    public:
        CorpusInfoEditorController(QWidget *parent = 0);
        ~CorpusInfoEditorController();
        void set(const vsampler::corpus::CorpusInfoProperty &corpus);
    public slots:
        void receiveChange(const vsampler::corpus::CorpusInfoProperty corpusInfoProperty);
    private:
        Ui::CorpusInfoPropertyView *ui;
    };
}
}


#endif //VSAMPLER_METAINFOVIEW_H
