/**
 * Created by Hal@shurabaP on 2015/06/12.
 * This code is under The BSD 3-Clause License.
 * See more Licence.txt.
 * Copyright (c) 2015 Hal@shurabaP. All rights reserved.
 */
#ifndef VSAMPLER_UTAUFILEUTAUVOICEBANKREPOSITORY_H
#define VSAMPLER_UTAUFILEUTAUVOICEBANKREPOSITORY_H

#include "repsoitory/UtauVoicebankRepository.h"
#include "reader/VoicebankReader.h"

namespace vsampler {
namespace domain {
namespace impl {

    class UtauFileUtauVoicebankRepository final : public UtauVoicebankRepository {
        vsampler::utau::VoicebankReader reader;
    public:
        UtauFileUtauVoicebankRepository(const vsampler::utau::VoicebankReader reader) : reader(reader) { }

        util::Try<UtauVoicebank> fetchBy(const UtauVoicebankId &id, QTextCodec *codec = QTextCodec::codecForName("utf-8")) override;
    };

}
}
}

#endif //VSAMPLER_UTAUFILEUTAUVOICEBANKREPOSITORY_H
