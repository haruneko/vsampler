/**
 * Created by Hal@shurabaP on 2015/04/27.
 * This code is under The BSD 3-Clause License.
 * See more Licence.txt.
 * Copyright (c) 2015 Hal@shurabaP. All rights reserved.
 */
#ifndef UTAU_VOICEBANKREPOSITORY_H
#define UTAU_VOICEBANKREPOSITORY_H

#include <QDir>
#include <QSharedPointer>
#include "value/Voicebank.h"

namespace vsampler {
namespace utau {

    class VoicebankReader {
    public:
        virtual ~VoicebankReader() { }

        /**
         * Find Voicebank in the specified directory.
         * @returns a pointer to Voicebank.
         *         NULL means failed finding a voicebank.
         */
        virtual Voicebank read(const QDir &directory) = 0;
    };

}
}

#endif //UTAU_VOICEBANKREPOSITORY_H
