/**
 * Created by Hal@shurabaP on 2015/04/27.
 * This code is under The BSD 3-Clause License.
 * See more Licence.txt.
 * Copyright (c) 2015 Hal@shurabaP. All rights reserved.
 */
#ifndef UTAU_CHARACTER_H
#define UTAU_CHARACTER_H

#include <QFileInfo>
#include <QHash>
#include <QUrl>
#include <QSharedData>
#include <QSharedDataPointer>
#include <QString>

namespace vsampler {
namespace utau {

    /**
     * MetaInfo class is a value object
     * that contains a meta data of the voicebank.
     */
    class MetaInfo final {
        class MetaInfoData : public QSharedData {
        public:
            MetaInfoData(
                    const QString &name,
                    const QFileInfo &imagePath,
                    const QFileInfo &sampleVoicePath,
                    const QString &author,
                    const QUrl &webUrl)
             : name(name), imagePath(imagePath), sampleVoicePath(sampleVoicePath), author(author), webUrl(webUrl) {}

            const QString name;
            const QFileInfo imagePath;
            const QFileInfo sampleVoicePath;
            const QString author;
            const QUrl webUrl;
        };
    public:
        /**
         * @param name represents a name of a voicebank.
         * @param imagePath represents a path to the voicebank's icon.
         * @param sampleVoicePath represents a path to an example of voice.
         * @param author is an author of the voicebank.
         * @param webUrl is a url of the voicebank.
         */
        MetaInfo(
                const QString &name,
                const QFileInfo &imagePath,
                const QFileInfo &sampleVoicePath,
                const QString &author,
                const QUrl &webUrl) : d(new MetaInfoData(name, imagePath, sampleVoicePath, author, webUrl)) { }
        MetaInfo(const MetaInfo &other) : d(other.d) { }

        QString name() const { return d->name; }
        QFileInfo imagePath() const { return d->imagePath; }
        QFileInfo sampleVoicePath() const { return d->sampleVoicePath; }
        QString author() const {return d->author; };
        QUrl webUrl() const { return d->webUrl; };
        bool operator == (const MetaInfo &other) const {
            return name() == other.name() &&
                    imagePath() == other.imagePath() &&
                    sampleVoicePath() == other.sampleVoicePath() &&
                    author() == other.author() &&
                    webUrl() == other.webUrl();
        }

    private:
        MetaInfo() : d() { }
        QSharedDataPointer<MetaInfoData> d;
    };

}
}

#endif //UTAU_CHARACTER_H
