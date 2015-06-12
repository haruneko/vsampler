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
#include <QTextCodec>
#include "value/Voicebank.h"
#include "util/Try.h"

namespace vsampler {
namespace utau {

    typedef std::function<vsampler::util::Try<Voicebank>(const QDir &directory, QTextCodec *codec)> VoicebankReader;

}
}

#endif //UTAU_VOICEBANKREPOSITORY_H
