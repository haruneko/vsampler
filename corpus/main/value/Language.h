/**
 * Created by Hal@shurabaP on 2015/05/29.
 * This code is under The BSD 3-Clause License.
 * See more Licence.txt.
 * Copyright (c) 2015 Hal@shurabaP. All rights reserved.
 */
#ifndef vsampler_LANGUAGE_H
#define vsampler_LANGUAGE_H

#include <QHash>
#include <QSharedData>
#include <QSharedDataPointer>
#include <QString>
#include <QtCore/qmetatype.h>

namespace vsampler {
namespace corpus {
    class Language final {
        class LanguageData : public QSharedData {
        public:
            LanguageData(const QString &iso) : iso(iso) { }
            QString iso;
        };
        QSharedDataPointer<LanguageData> d;
    public:
        Language() : d() { }
        explicit Language(const QString &iso) : d(new LanguageData(iso)) { }
        Language(const Language &other) : d(other.d) { }
        Language &operator = (const Language& right) { this->d = right.d; return (*this); }
        QString iso() const { return d->iso; }
        bool operator == (const Language &right) const { return this->iso() == right.iso(); }
    };

    // qHash should be inside namespace
    // see more: https://bugreports.qt.io/browse/QTBUG-34912
    inline uint qHash(const Language &language, uint seed = 0) {
        return qHash(language.iso(), seed);
    }
}
}

Q_DECLARE_METATYPE(vsampler::corpus::Language)

#endif //vsampler_LANGUAGE_H
