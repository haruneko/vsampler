/**
 * Created by Hal@shurabaP on 2015/06/07.
 * This code is under The BSD 3-Clause License.
 * See more Licence.txt.
 * Copyright (c) 2015 Hal@shurabaP. All rights reserved.
 */
#include <QAudioBuffer>
#include <QAudioDecoder>
#include "UtauVoicebankConvertService.h"

using namespace vsampler::corpus;
using namespace vsampler::domain;
using namespace vsampler::utau;
using namespace vsampler::util;

namespace {
    QHash<Language, QString> getLanguageHash(const QString &languageString, const QString &value) {
        QHash<Language, QString> result;
        result[Language(languageString)] = value;
        return result;
    }

    CorpusMetaInfo metaInfoFrom(const vsampler::utau::MetaInfo &utau, const QString &languageString) {
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

    double lengthFrom(const VoiceAlias &alias) {
        if(alias.rightBlankMillis() < 0) {
            return fabs(alias.rightBlankMillis());
        } else {
            // Positive right blank specifies the end time from the whole wave length.
            // Thus whole length can not be determined unless wave file length is known.
            // But this feature is complicated, so vsampler strongly deprecated positive right blank.
            QAudioDecoder decoder;
            decoder.setSourceFilename(alias.filePath().fileName());
            QAudioBuffer buffer(decoder.read());
            if(buffer.isValid()) {
                return (double)(buffer.duration()) / 1000.0;
            } else {
                return 0.0;
            }
        }
    }

    QPair<Pronounce, PhonemeMetaInfo> phonemeFrom(
            const QString &aliasKey,
            const VoiceAlias &alias,
            const UtauVoicebankConvertService::ConvertOption &option) {
        QString pronounceString = aliasKey;
        MusicalContext musicalContext;
        foreach(const QString &key, option.postfixToMusicalContextMap.keys()) {
            if(aliasKey.contains(key, Qt::CaseSensitive)) {
                pronounceString = aliasKey;
                pronounceString.replace(key, "", Qt::CaseSensitive);
                musicalContext = option.postfixToMusicalContextMap.value(key);
                break;
            }
        }
        double length = lengthFrom(alias);
        PhonemeMetaInfo metaInfo(
                aliasKey,
                alias.filePath(),
                option.type,
                (int)alias.offsetMillis(),
                (int)length,
                (int)alias.preUtteranceMillis(),
                (int)alias.fixedLengthMillis(),
                (int)length,
                musicalContext);
        return QPair<Pronounce, PhonemeMetaInfo>(Pronounce(pronounceString), metaInfo);
    }

    QHash<Pronounce, PhonemeSet> phonemeSetFrom(
            const vsampler::utau::Voicebank &oto,
            const UtauVoicebankConvertService::ConvertOption &option) {
        QHash<Pronounce, PhonemeSet> result;
        foreach(const QString &key, oto.voiceAliases().keys()) {
            auto p(phonemeFrom(key, oto.voiceAliases().value(key), option));
            result[p.first].insert(p.second);
        }
        return result;
    }
}

vsampler::util::Try<CorpusProperty> vsampler::domain::UtauVoicebankConvertService::convert(
        const UtauVoicebankId &utauVoicebankId, const ConvertOption &option) const {
    return repository->fetchBy(utauVoicebankId).map<CorpusProperty>([option](UtauVoicebank voicebank) -> CorpusProperty {
        return CorpusProperty(
                metaInfoFrom(voicebank.value().metaInfo(), option.languageString),
                phonemeSetFrom(voicebank.value(), option));
    });
}
