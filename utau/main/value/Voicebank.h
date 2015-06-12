/**
 * Created by Hal@shurabaP on 2015/04/27.
 * This code is under The BSD 3-Clause License.
 * See more Licence.txt.
 * Copyright (c) 2015 Hal@shurabaP. All rights reserved.
 */
#ifndef UTAU_VOICEBANK_H
#define UTAU_VOICEBANK_H

#include <QDir>
#include <QHash>
#include <QSharedDataPointer>
#include "MetaInfo.h"
#include "VoiceAlias.h"

namespace vsampler {
namespace utau {

    class Voicebank final {
        class VoiceBankData : public QSharedData {
        public:
            VoiceBankData(const MetaInfo &metaInfo,
                          const QHash<QString, VoiceAlias> &voiceAliases,
                          const QDir &directory) :
                    metaInfo(metaInfo), voiceAliases(voiceAliases), directory(directory) { }
            const MetaInfo metaInfo;
            const QHash<QString, VoiceAlias> voiceAliases;
            const QDir directory;
        };
        QSharedDataPointer<VoiceBankData> d;
        Voicebank() : d () { }
    public:
        Voicebank(const MetaInfo &metaInfo,
                  const QHash<QString, VoiceAlias> &voiceAliases,
                  const QDir &directory) : d(new VoiceBankData(metaInfo, voiceAliases, directory)) { }
        Voicebank(const Voicebank &other) : d(other.d) { }
        const MetaInfo &metaInfo() const { return d->metaInfo; }
        const QHash<QString, VoiceAlias> &voiceAliases() const { return d->voiceAliases; }
        const QDir &directory() const { return d->directory; }
    };
}
}


#endif //UTAU_VOICEBANK_H
