/**
 * Created by Hal@shurabaP on 2015/04/27.
 * This code is under The BSD 3-Clause License.
 * See more Licence.txt.
 * Copyright (c) 2015 Hal@shurabaP. All rights reserved.
 */
#ifndef UTAU_VOICEALIASESREADER_H
#define UTAU_VOICEALIASESREADER_H

#include <functional>
#include <QHash>
#include <QIODevice>
#include <QSharedPointer>
#include <QString>
#include <QTextCodec>
#include "value/VoiceAlias.h"
#include "VoiceAliasLineReader.h"
#include "io/DeviceFactory.h"

namespace vsampler {
namespace utau {
namespace impl {

    /**
     * VoiceAliasesReader represents a function `read` reads oto.ini of an UTAU voicebank.
     * @param QFileInfo contains a file path to oto.ini.
     * @param QTextCodec is a text encode type.
     * @param VoiceAliasLineReader is a function to read one line. This value is for convenience for tests.
     * @param DeviceFactory is a function to open a device. This value is for convenience for tests.
     */
    typedef std::function<QHash<QString, vsampler::utau::VoiceAlias>(
            const QFileInfo&, QTextCodec*, const VoiceAliasLineReader, const vsampler::util::DeviceFactory)> VoiceAliasesReader;

    extern const VoiceAliasesReader FileVoiceAliasesReader;
}
}
}


#endif //UTAU_VOICEALIASESREADER_H
