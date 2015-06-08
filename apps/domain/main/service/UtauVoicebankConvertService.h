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
    class UtauVoicebankConvertService final {
        const QSharedPointer<UtauVoicebankRepository> repository;
    public:
        UtauVoicebankConvertService(const QSharedPointer<UtauVoicebankRepository> &repository) : repository(repository) { }
        util::Try<corpus::CorpusProperty> convert(const UtauVoicebankId &id, const QString &languageString) const;
    };
}
}


#endif //VSAMPLER_UTAUVOICEBANKCONVERTER_H
