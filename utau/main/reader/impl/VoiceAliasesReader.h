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

    class VoiceAliasLineReaderSpec {
    public:
        /**
         * The function `read` reads oto.ini of an UTAU voicebank.
         * @param fileInfo contains a file path to oto.ini.
         * @param codec is a text encode type.
         * @param lineReader is a function to read one line. This value is for convenience for tests.
         * @param deviceFactory is a function to open a device. This value is for convenience for tests.
         */
        static QHash<QString, vsampler::utau::VoiceAlias> read(
                const QFileInfo &fileInfo,
                QTextCodec* codec = QTextCodec::codecForName("utf-8"),
                const std::function<QSharedPointer<VoiceAliasLineElement>(const QString &)> &lineReader = VoiceAliasLineReader::read,
                const vsampler::util::DeviceFactory &deviceFactory = vsampler::util::FileDeviceFactory
        );
    };

}
}
}


#endif //UTAU_VOICEALIASESREADER_H
