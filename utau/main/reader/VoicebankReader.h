/**
 * Created by Hal@shurabaP on 2015/04/27.
 * This code is under The BSD 3-Clause License.
 * See more Licence.txt.
 * Copyright (c) 2015 Hal@shurabaP. All rights reserved.
 */
#ifndef UTAU_VOICEBANKREADER_H
#define UTAU_VOICEBANKREADER_H

#include <QDir>
#include <QSharedPointer>
#include <QTextCodec>
#include "value/Voicebank.h"
#include "util/Try.h"

namespace vsampler {
namespace utau {

    /**
     * VoicebankReader reads UtauVoicebank on the given directory.
     * codec specifies which codec to use, such as utf-8, shift-jis, and so on.
     */
    typedef std::function<vsampler::util::Try<Voicebank>(const QDir &directory, QTextCodec *codec)> VoicebankReader;

}
}

#endif //UTAU_VOICEBANKREADER_H
