/**
 * Created by Hal@shurabaP on 2015/06/07.
 * This code is under The BSD 3-Clause License.
 * See more Licence.txt.
 * Copyright (c) 2015 Hal@shurabaP. All rights reserved.
 */
#include "UtauVoicebankConvertService.h"

using namespace vsampler::corpus;
using namespace vsampler::domain;
using namespace vsampler::util;

namespace {
    QHash<Language, QString> getLanguageHash(const QString &languageString, const QString &value) {
        QHash<Language, QString> result;
        result[Language(languageString)] = value;
        return result;
    }

    CorpusMetaInfo metaInfoFrom(vsampler::utau::MetaInfo &utau, const QString &languageString) {
        return CorpusMetaInfo(
            getLanguageHash(languageString, utau.name()),
            QString(),
            utau.imagePath(),
            utau.sampleVoicePath(),
            getLanguageHash(languageString, utau.author()),
            utau.webUrl(),
            QHash<Language, QString>(),
            QHash<Language, QString>()
        );
    }

    QHash<Pronounce, PhonemeSet> phonemeSet(vsampler::utau::Voicebank &oto) {
        return QHash<Pronounce, PhonemeSet>();
    }
}

vsampler::util::Try<CorpusProperty> vsampler::domain::UtauVoicebankConvertService::convert(
        const UtauVoicebankId &utauVoicebankId, const QString &languageString) const {
    return repository->fetchBy(utauVoicebankId).map<CorpusProperty>([](UtauVoicebank voicebank) -> CorpusProperty {
        return CorpusProperty();
    });
}
