/**
 * Created by Hal@shurabaP on 2015/06/12.
 * This code is under The BSD 3-Clause License.
 * See more Licence.txt.
 * Copyright (c) 2015 Hal@shurabaP. All rights reserved.
 */
#include "reader/VoicebankReader.h"
#include "UtauFileUtauVoicebankRepository.h"

using namespace vsampler::utau;
using namespace vsampler::util;
using namespace vsampler::domain;

vsampler::util::Try<vsampler::domain::UtauVoicebank> vsampler::domain::impl::UtauFileUtauVoicebankRepository::fetchBy(
        const vsampler::domain::UtauVoicebankId &id, QTextCodec *codec) {
    return reader(QDir(id), codec).map<vsampler::domain::UtauVoicebank>(
            [id](const Voicebank &vb) -> UtauVoicebank {
                return UtauVoicebank(id, vb);
            }
    );
}
