/**
 * Created by Hal@shurabaP on 2015/06/07.
 * This code is under The BSD 3-Clause License.
 * See more Licence.txt.
 * Copyright (c) 2015 Hal@shurabaP. All rights reserved.
 */
#ifndef VSAMPLER_UTAUVOICEBANK_H
#define VSAMPLER_UTAUVOICEBANK_H

#include <QString>
#include "value/Voicebank.h"
#include "Entity.h"

namespace vsampler {
namespace domain {

    typedef QString UtauVoicebankId;
    typedef vsampler::Entity<UtauVoicebankId, utau::Voicebank> UtauVoicebank;

}
}


#endif //VSAMPLER_UTAUVOICEBANK_H
