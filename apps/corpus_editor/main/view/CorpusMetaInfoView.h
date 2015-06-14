/**
 * Created by Hal@shurabaP on 2015/06/14.
 * This code is under The BSD 3-Clause License.
 * See more Licence.txt.
 * Copyright (c) 2015 Hal@shurabaP. All rights reserved.
 */
#ifndef VSAMPLER_METAINFOVIEW_H
#define VSAMPLER_METAINFOVIEW_H

#include <QWidget>

#include "value/CorpusMetaInfo.h"

namespace vsampler {
namespace corpus_editor {

    class CorpusMetaInfoView final : public QWidget {
        Q_OBJECT
    public:
        CorpusMetaInfoView(QWidget *parent = 0);
        void set(const vsampler::corpus::CorpusMetaInfo &corpusMetaInfo);
        vsampler::corpus::CorpusMetaInfo get() const;
    public slots:
        void receiveChange(const vsampler::corpus::CorpusMetaInfo corpusMetaInfo);
    signals:
        void notifyChange(const vsampler::corpus::CorpusMetaInfo);
    private slots:
        void onDataChanged();
    };
}
}


#endif //VSAMPLER_METAINFOVIEW_H
