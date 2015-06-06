/**
 * Created by Hal@shurabaP on 2015/05/05.
 * This code is under The BSD 3-Clause License.
 * See more Licence.txt.
 * Copyright (c) 2015 Hal@shurabaP. All rights reserved.
 */
#ifndef CORPUS_ROOT_PRONOUNCE_H
#define CORPUS_ROOT_PRONOUNCE_H

#include <QHash>
#include <QSharedData>
#include <QSharedDataPointer>
#include <QString>
#include <QtCore/qmetatype.h>

namespace vsampler {
namespace corpus {

    class Pronounce final {
        class PronounceData : public QSharedData {
        public:
            PronounceData() : PronounceData(QString()) { }
            PronounceData(const QString &value) : value(value) { }
            QString value;
        };
        QSharedDataPointer<PronounceData> d;
    public:
        Pronounce() : d() { }
        explicit Pronounce(const QString &value) : d(new PronounceData(value)) { }
        Pronounce(const Pronounce &other) : d(other.d) { }
        Pronounce &operator = (const Pronounce &right) { this->d = right.d; return (*this); }
        QString value() const { return d->value; }
        bool operator ==(const Pronounce &other) const {
            return value() == other.value();
        }
    };

    // qHash should be inside namespace
    // see more: https://bugreports.qt.io/browse/QTBUG-34912
    inline uint qHash(const Pronounce &pronounce, uint seed = 0) {
        return qHash(pronounce.value(), seed);
    }

}
}

Q_DECLARE_METATYPE(vsampler::corpus::Pronounce)

#endif //CORPUS_ROOT_PRONOUNCE_H
