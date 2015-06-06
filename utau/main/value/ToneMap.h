/**
 * Created by Hal@shurabaP on 2015/04/27.
 * This code is under The BSD 3-Clause License.
 * See more Licence.txt.
 * Copyright (c) 2015 Hal@shurabaP. All rights reserved.
 */
#ifndef UTAU_TONEMAP_H
#define UTAU_TONEMAP_H

#include <QDir>
#include <QHash>
#include <QSharedData>
#include <QString>

namespace vsampler {
namespace utau {

    class ToneMapElement final {
        class ToneMapElementData : public QSharedData {
        public:
            ToneMapElementData(int noteNumber, const QDir &path, const QString &postfix) : noteNumber(noteNumber), path(path), postfix(postfix) { }
            const int noteNumber;
            const QDir path;
            const QString postfix;
        };
        QSharedDataPointer<ToneMapElementData> d;
        ToneMapElement() : d() { }

    public:
        ToneMapElement(int noteNumber, const QDir &path, const QString &postfix) : d(new ToneMapElementData(noteNumber, path, postfix)) { }
        ToneMapElement(const ToneMapElement &other) : ToneMapElement(other.noteNumber(), other.path(), other.postfix()) { }

        int noteNumber() const { return d->noteNumber; }
        const QDir &path() const { return d->path; }
        const QString &postfix() const { return d->postfix; }
        bool operator == (const ToneMapElement &other) const {
            return noteNumber() == other.noteNumber() && path() == other.path() && postfix() == other.postfix();
        }
    };

    /**
     * ToneMap class is a value object that contains tone map.
     * Utau resolves which directory to use by a note number and tone map.
     */
    class ToneMap final {
        ToneMap() : value() { }
    public:
        ToneMap(const QHash<int, ToneMapElement> &value) : value(value) { }
        ToneMap(const ToneMap &other) : value(other.value) { }
        const QHash<int, ToneMapElement> value;
    };
}
}


#endif //UTAU_TONEMAP_H
