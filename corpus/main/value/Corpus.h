/**
 * Created by Hal@shurabaP on 2015/05/17.
 * This code is under The BSD 3-Clause License.
 * See more Licence.txt.
 * Copyright (c) 2015 Hal@shurabaP. All rights reserved.
 */
#ifndef CORPUS_ROOT_CORPUS_H
#define CORPUS_ROOT_CORPUS_H

#include "Pronounce.h"
#include "CorpusMetaInfo.h"
#include "PhonemeMetaInfo.h"
#include "PhonemeSet.h"

#include <QHash>
#include <QSharedData>
#include <QSharedDataPointer>
#include <QString>

namespace vsampler {
namespace corpus {
    class Corpus {
        class CorpusData : public QSharedData {
        public:
            CorpusData(const CorpusMetaInfo &metaInfo, const QHash<Pronounce, PhonemeSet> &phonemeSet)
                    : metaInfo(metaInfo), phonemeSet(phonemeSet) { }
            CorpusMetaInfo metaInfo;
            QHash<Pronounce, PhonemeSet> phonemeSet;
        };
    QSharedDataPointer<CorpusData> d;
    public:
        Corpus() : d() { }
        Corpus(const CorpusMetaInfo &metaInfo, const QHash<Pronounce, PhonemeSet> &phonemeSet)
                : d(new CorpusData(metaInfo, phonemeSet)) { }
        Corpus(const Corpus &other) : d(other.d) { }
        Corpus &operator = (const Corpus &right) { this->d = right.d; return (*this); }
        const QHash<Pronounce, PhonemeSet> &phonemeSet() const { return d->phonemeSet; }
        QHash<Pronounce, PhonemeSet> phonemeSet() { return d->phonemeSet; }
        const CorpusMetaInfo &metaInfo() const { return d->metaInfo; }
        CorpusMetaInfo metaInfo() { return d->metaInfo; }
    };

}
}

#endif //CORPUS_ROOT_CORPUS_H
