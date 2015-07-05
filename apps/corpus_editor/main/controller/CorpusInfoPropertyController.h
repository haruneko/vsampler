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

    class CorpusInfoPropertyController final : public QWidget {
        Q_OBJECT
    public:
        CorpusInfoPropertyController(QWidget *parent = 0);
        ~CorpusInfoPropertyController();
        void set(const vsampler::corpus::CorpusInfoProperty &corpus);
        vsampler::corpus::CorpusInfoProperty get() const;
    public slots:
        void receiveChange(const vsampler::corpus::CorpusInfoProperty corpusInfoProperty);
    signals:
        void notifyChange(const vsampler::corpus::CorpusInfoProperty);
    private slots:
        void onDataChanged();
    private:
        Ui::CorpusInfoPropertyView *ui;
    };
}
}


#endif //VSAMPLER_METAINFOVIEW_H
