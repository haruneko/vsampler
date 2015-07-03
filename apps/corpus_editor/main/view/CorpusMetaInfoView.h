/**
 * Created by Hal@shurabaP on 2015/06/14.
 * This code is under The BSD 3-Clause License.
 * See more Licence.txt.
 * Copyright (c) 2015 Hal@shurabaP. All rights reserved.
 */
#ifndef VSAMPLER_METAINFOVIEW_H
#define VSAMPLER_METAINFOVIEW_H

#include <QMainWindow>

#include "value/CorpusMetaInfo.h"

namespace Ui {
    class CorpusMetaInfoView;
}

namespace vsampler {
namespace corpus_editor {

    class CorpusMetaInfoView final : public QMainWindow {
        Q_OBJECT
    public:
        CorpusMetaInfoView(QWidget *parent = 0);
        ~CorpusMetaInfoView();
        void set(const vsampler::corpus::CorpusMetaInfo &corpusMetaInfo);
        vsampler::corpus::CorpusMetaInfo get() const;
    public slots:
        void receiveChange(const vsampler::corpus::CorpusMetaInfo corpusMetaInfo);
    signals:
        void notifyChange(const vsampler::corpus::CorpusMetaInfo);
    private slots:
        void onDataChanged();
    private:
        Ui::CorpusMetaInfoView *ui;
    };
}
}


#endif //VSAMPLER_METAINFOVIEW_H
