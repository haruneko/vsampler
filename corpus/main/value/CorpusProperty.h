/**
 * Created by Hal@shurabaP on 2015/05/17.
 * This code is under The BSD 3-Clause License.
 * See more Licence.txt.
 * Copyright (c) 2015 Hal@shurabaP. All rights reserved.
 */
#ifndef CORPUS_ROOT_CORPUS_H
#define CORPUS_ROOT_CORPUS_H

#include "Pronounce.h"
#include "CorpusInfoProperty.h"
#include "PhonemeInfoProperty.h"
#include "PhonemeSet.h"

#include <QHash>
#include <QSharedData>
#include <QSharedDataPointer>
#include <QString>

namespace vsampler {
namespace corpus {
    class CorpusProperty {
        class CorpusPropertyData : public QSharedData {
        public:
            CorpusPropertyData(const CorpusInfoProperty &infoProperty, const QHash<Pronounce, PhonemeSet> &phonemeSet)
                    : infoProperty(infoProperty), phonemeSet(phonemeSet) { }
            CorpusInfoProperty infoProperty;
            QHash<Pronounce, PhonemeSet> phonemeSet;
        };
    QSharedDataPointer<CorpusPropertyData> d;
    public:
        CorpusProperty() : d() { }
        CorpusProperty(const CorpusInfoProperty &infoProperty, const QHash<Pronounce, PhonemeSet> &phonemeSet)
                : d(new CorpusPropertyData(infoProperty, phonemeSet)) { }
        CorpusProperty(const CorpusProperty &other) : d(other.d) { }
        CorpusProperty &operator = (const CorpusProperty &right) { this->d = right.d; return (*this); }

        const QHash<Pronounce, PhonemeSet> &phonemeSet() const { return d->phonemeSet; }
        QHash<Pronounce, PhonemeSet> &phonemeSet() { return d->phonemeSet; }

        const CorpusInfoProperty &infoProperty() const { return d->infoProperty; }
        CorpusInfoProperty &infoProperty() { return d->infoProperty; }
    };

}
}

#endif //CORPUS_ROOT_CORPUS_H
