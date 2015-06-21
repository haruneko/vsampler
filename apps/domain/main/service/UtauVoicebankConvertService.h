/**
 * Created by Hal@shurabaP on 2015/06/07.
 * This code is under The BSD 3-Clause License.
 * See more Licence.txt.
 * Copyright (c) 2015 Hal@shurabaP. All rights reserved.
 */
#ifndef VSAMPLER_UTAUVOICEBANKCONVERTER_H
#define VSAMPLER_UTAUVOICEBANKCONVERTER_H

#include <QSharedPointer>

#include "entity/UtauVoicebank.h"
#include "value/CorpusProperty.h"

#include "util/Try.h"
#include "value/CorpusProperty.h"
#include "entity/UtauVoicebank.h"
#include "repsoitory/UtauVoicebankRepository.h"

namespace vsampler {
namespace domain {
    extern const QSharedPointer<UtauVoicebankRepository> DefaultUtauVoicebankRepository;
    class UtauVoicebankConvertService final {
        const QSharedPointer<UtauVoicebankRepository> repository;
    public:
        class ConvertOption {
        public:
            ConvertOption() : ConvertOption(corpus::PhonemeType::Unknown, QHash<QString, corpus::MusicalContext>(), QString()) { }
            ConvertOption(
                    const corpus::PhonemeType &type,
                    const QHash<QString, corpus::MusicalContext> &postfixToMusicalContextMap,
                    const QString &languageString
            ) : type(type), postfixToMusicalContextMap(postfixToMusicalContextMap), languageString(languageString) { }

            corpus::PhonemeType type;
            QHash <QString, corpus::MusicalContext> postfixToMusicalContextMap;
            QString languageString;
        };

        UtauVoicebankConvertService(
                const QSharedPointer<UtauVoicebankRepository> repository = DefaultUtauVoicebankRepository) : repository(repository) { }
        util::Try<corpus::CorpusProperty> convert(const UtauVoicebankId &id, const ConvertOption &option = ConvertOption()) const;
    };
}
}


#endif //VSAMPLER_UTAUVOICEBANKCONVERTER_H
