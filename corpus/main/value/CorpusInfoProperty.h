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

    /**
     * CorpusInfoProperty represents a meta info of Corpus.
     * Meta info contains name, version, icon, sample, author name, web url, license and description in each supported language.
     */
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
            QHash<Language, QString> name;
            QString version;
            QFileInfo iconPath;
            QFileInfo samplePath;
            QHash<Language, QString> author;
            QUrl web;
            QHash<Language, QString> license;
            QHash<Language, QString> description;
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

        const QHash<Language, QString> &name() const { return d->name; }
        QHash<Language, QString> &name() { return d->name; }

        QString version() const { return d->version; }
        void setVersion(const QString &version) { d->version = version; }

        QFileInfo iconPath() const { return d->iconPath; }
        void setIconPath(const QFileInfo &iconPath) { d->iconPath = iconPath; }

        QFileInfo samplePath() const { return d->samplePath; }
        void setSamplePath(const QFileInfo &samplePath) { d->samplePath = samplePath; }

        const QHash<Language, QString> &author() const { return d->author; }
        QHash<Language, QString> &author() { return d->author; }

        QUrl web() const { return d->web; }
        void setWeb(const QUrl &web) { d->web = web; }

        const QHash<Language, QString> &license() const { return d->license; }
        QHash<Language, QString> &license() { return d->license; }

        const QHash<Language, QString> &description() const { return d->description; }
        QHash<Language, QString> &description() { return d->description; }
    };

}
}


#endif //CORPUS_ROOT_CORPSINFOPROPERTY_H
