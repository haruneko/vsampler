/**
 * Created by Hal@shurabaP on 2015/05/05.
 * This code is under The BSD 3-Clause License.
 * See more Licence.txt.
 * Copyright (c) 2015 Hal@shurabaP. All rights reserved.
 */
#ifndef CORPUS_ROOT_CORPSINFOPROPERTY_H
#define CORPUS_ROOT_CORPSINFOPROPERTY_H

#include "Language.h"

#include <QFileInfo>
#include <QHash>
#include <QSharedData>
#include <QSharedDataPointer>
#include <QString>
#include <QUrl>

namespace vsampler {
namespace corpus {

    class CorpusInfoProperty final {
        class CorpusInfoPropertyData : public QSharedData {
        public:
            CorpusInfoPropertyData() : CorpusInfoPropertyData(
                    QHash<Language, QString>(),
                    "",
                    QFileInfo(),
                    QFileInfo(),
                    QHash<Language, QString>(),
                    QUrl(),
                    QHash<Language, QString>(),
                    QHash<Language, QString>()) { }
            CorpusInfoPropertyData(
                    const QHash<Language, QString> &name,
                    const QString &version,
                    const QFileInfo &iconPath,
                    const QFileInfo &samplePath,
                    const QHash<Language, QString> &author,
                    const QUrl &web,
                    const QHash<Language, QString> &license,
                    const QHash<Language, QString> &description)
                    : name(name),
                      version(version),
                      iconPath(iconPath),
                      samplePath(samplePath),
                      author(author),
                      web(web),
                      license(license),
                      description(description) { }
            const QHash<Language, QString> name;
            const QString version;
            const QFileInfo iconPath;
            const QFileInfo samplePath;
            const QHash<Language, QString> author;
            const QUrl web;
            const QHash<Language, QString> license;
            const QHash<Language, QString> description;
        };
        QSharedDataPointer<CorpusInfoPropertyData> d;
    public:
        CorpusInfoProperty() : d() { }
        CorpusInfoProperty(
            const QHash<Language, QString> &name,
            const QString &version,
            const QFileInfo &iconPath,
            const QFileInfo &samplePath,
            const QHash<Language, QString> &author,
            const QUrl &web,
            const QHash<Language, QString> &license,
            const QHash<Language, QString> &description)
                : d(new CorpusInfoPropertyData(name, version, iconPath, samplePath, author, web, license, description)) { }
        CorpusInfoProperty(const CorpusInfoProperty &other) : d(other.d) { }
        CorpusInfoProperty & operator =(const CorpusInfoProperty &right) { this->d = right.d; return (*this); }
        QHash<Language, QString> name() const { return d->name; }
        QString version() const { return d->version; }
        QFileInfo iconPath() const { return d->iconPath; }
        QFileInfo samplePath() const { return d->samplePath; }
        QHash<Language, QString> author() const { return d->author; }
        QUrl web() const { return d->web; }
        QHash<Language, QString> license() const { return d->license; }
        QHash<Language, QString> description() const { return d->description; }
    };

}
}


#endif //CORPUS_ROOT_CORPSINFOPROPERTY_H
