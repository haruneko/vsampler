/**
 * Created by Hal@shurabaP on 2015/05/04.
 * This code is under The BSD 3-Clause License.
 * See more Licence.txt.
 * Copyright (c) 2015 Hal@shurabaP. All rights reserved.
 */
#ifndef CORPUS_ROOT_PHONEMEMETAINFO_H
#define CORPUS_ROOT_PHONEMEMETAINFO_H

#include "value/MusicalContext.h"

#include <QFileInfo>
#include <QHash>
#include <QSharedData>
#include <QSharedDataPointer>
#include <QString>

namespace vsampler {
namespace corpus {

    enum PhonemeType {
        Unknown = -1,
        CV = 0,
        VCV,
        VC,
        CVC,
        Size
    };
    class PhonemeMetaInfo final {
        class PhonemeMetaInfoData : public QSharedData {
        public:
            PhonemeMetaInfoData(
                    const QString &label,
                    const QFileInfo &path,
                    PhonemeType type,
                    int offset,
                    int length,
                    int preutterance,
                    int loopBeginMs,
                    int loopEndMs,
                    const MusicalContext &context)
                    : label(label), path(path), type(type), offset(offset), length(length), preutterance(preutterance), loopBeginMs(loopBeginMs), loopEndMs(loopEndMs), context(context) { }
            QString label;
            QFileInfo path;
            PhonemeType type;
            int offset;
            int length;
            int preutterance;
            int loopBeginMs;
            int loopEndMs;
            MusicalContext context;
        };
        QSharedDataPointer<PhonemeMetaInfoData> d;
    public:
        PhonemeMetaInfo(const QString &label, const QFileInfo &path, PhonemeType type, int offset, int length, int preutterance, int loopBeginMs, int loopEndMs, const MusicalContext &context)
                : d(new PhonemeMetaInfoData(label, path, type, offset, length, preutterance, loopBeginMs, loopEndMs, context)) { }
        PhonemeMetaInfo(const PhonemeMetaInfo &other) : d(other.d) { }
        PhonemeMetaInfo() : d() { }
        PhonemeMetaInfo &operator =(const PhonemeMetaInfo &right) { this->d = right.d; return (*this); }
        QString label() const { return d->label; }
        QFileInfo path() const { return d->path; }
        PhonemeType type() const { return d->type; }
        int offset() const { return d->offset; }
        int length() const { return d->length; }
        int preutterance() const { return d->preutterance; }
        int loopBeginMs() const { return d->loopBeginMs; }
        int loopEndMs() const { return d->loopEndMs; }
        MusicalContext context() const { return d->context; }

        bool operator ==(const PhonemeMetaInfo &other) const {
            return label() == other.label() &&
                   path() == other.path() &&
                   type() == other.type() &&
                   offset() == other.offset() &&
                   length() == other.length() &&
                   preutterance() == other.preutterance() &&
                   loopBeginMs() == other.loopBeginMs() &&
                   loopEndMs() == other.loopEndMs() &&
                   context() == other.context();
        }
    };

    uint qHash(int, uint);
    // qHash should be inside namespace
    // see more: https://bugreports.qt.io/browse/QTBUG-34912
    inline uint qHash(const vsampler::corpus::PhonemeMetaInfo &info, uint seed = 0) {
        return qHash(info.label(), seed) ^
               qHash(info.path().filePath(), seed) ^
               qHash(info.loopBeginMs(), seed) ^
               qHash(info.loopEndMs(), seed) ^
               qHash(info.context(), seed);
    }
}
}

#endif //CORPUS_ROOT_PHONEMEMETAINFO_H
