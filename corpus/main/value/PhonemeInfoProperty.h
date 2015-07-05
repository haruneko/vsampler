/**
 * Created by Hal@shurabaP on 2015/05/04.
 * This code is under The BSD 3-Clause License.
 * See more Licence.txt.
 * Copyright (c) 2015 Hal@shurabaP. All rights reserved.
 */
#ifndef CORPUS_ROOT_PHONEMEINFOPROPERTY_H
#define CORPUS_ROOT_PHONEMEINFOPROPERTY_H

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
    class PhonemeInfoProperty final {
        class PhonemeInfoPropertyData : public QSharedData {
        public:
            PhonemeInfoPropertyData(
                    const QString &label,
                    const QFileInfo &path,
                    PhonemeType type,
                    int offset,
                    int length,
                    int preutterance,
                    int loopBeginMs,
                    int loopEndMs,
                    const MusicalContext &context)
                    : label(label), path(path), type(type), offsetMillis(offset), lengthMillis(length), preutteranceMillis(preutterance), loopBeginMillis(loopBeginMs), loopEndMillis(loopEndMs), context(context) { }
            QString label;
            QFileInfo path;
            PhonemeType type;
            int offsetMillis;
            int lengthMillis;
            int preutteranceMillis;
            int loopBeginMillis;
            int loopEndMillis;
            MusicalContext context;
        };
        QSharedDataPointer<PhonemeInfoPropertyData> d;
    public:
        PhonemeInfoProperty(const QString &label, const QFileInfo &path, PhonemeType type, int offset, int length, int preutterance, int loopBeginMs, int loopEndMs, const MusicalContext &context)
                : d(new PhonemeInfoPropertyData(label, path, type, offset, length, preutterance, loopBeginMs, loopEndMs, context)) { }
        PhonemeInfoProperty(const PhonemeInfoProperty &other) : d(other.d) { }
        PhonemeInfoProperty() : d() { }
        PhonemeInfoProperty &operator =(const PhonemeInfoProperty &right) { this->d = right.d; return (*this); }
        QString label() const { return d->label; }
        QFileInfo path() const { return d->path; }
        PhonemeType type() const { return d->type; }
        int offsetMillis() const { return d->offsetMillis; }
        int lengthMillis() const { return d->lengthMillis; }
        int preutteranceMillis() const { return d->preutteranceMillis; }
        int loopBeginMillis() const { return d->loopBeginMillis; }
        int loopEndMillis() const { return d->loopEndMillis; }
        MusicalContext context() const { return d->context; }

        bool operator ==(const PhonemeInfoProperty &other) const {
            return label() == other.label() &&
                   path() == other.path() &&
                   type() == other.type() &&
                   offsetMillis() == other.offsetMillis() &&
                   lengthMillis() == other.lengthMillis() &&
                   preutteranceMillis() == other.preutteranceMillis() &&
                   loopBeginMillis() == other.loopBeginMillis() &&
                   loopEndMillis() == other.loopEndMillis() &&
                   context() == other.context();
        }
    };

    uint qHash(int, uint);
    // qHash should be inside namespace
    // see more: https://bugreports.qt.io/browse/QTBUG-34912
    inline uint qHash(const vsampler::corpus::PhonemeInfoProperty &info, uint seed = 0) {
        return ::qHash(info.label(), seed) ^
                ::qHash(info.path().filePath(), seed) ^
                ::qHash(info.loopBeginMillis(), seed) ^
                ::qHash(info.loopEndMillis(), seed) ^
                ::qHash(info.context(), seed);
    }
}
}

#endif //CORPUS_ROOT_PHONEMEINFOPROPERTY_H
