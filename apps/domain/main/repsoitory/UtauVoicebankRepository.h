/**
 * Created by Hal@shurabaP on 2015/06/07.
 * This code is under The BSD 3-Clause License.
 * See more Licence.txt.
 * Copyright (c) 2015 Hal@shurabaP. All rights reserved.
 */
#ifndef VSAMPLER_UTAUVOICEBANKREPOSITORY_H
#define VSAMPLER_UTAUVOICEBANKREPOSITORY_H

#include "entity/UtauVoicebank.h"
#include "util/Try.h"

namespace vsampler {
namespace domain {

    class UtauVoicebankRepository {
    public:
        virtual ~UtauVoicebankRepository() { }
        virtual util::Try<UtauVoicebank> fetchBy(const UtauVoicebankId &id) = 0;
    };

}
}

#endif //VSAMPLER_UTAUVOICEBANKREPOSITORY_H
