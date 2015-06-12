/**
 * Created by Hal@shurabaP on 2015/04/27.
 * This code is under The BSD 3-Clause License.
 * See more Licence.txt.
 * Copyright (c) 2015 Hal@shurabaP. All rights reserved.
 */
#include <QFile>
#include <QTextStream>
#include "VoiceAliasesReader.h"

using namespace vsampler::utau;
using namespace vsampler::utau::impl;

const vsampler::utau::impl::VoiceAliasesReader vsampler::utau::impl::FileVoiceAliasesReader =
        []( const QFileInfo &fileInfo,
            QTextCodec* codec,
            const VoiceAliasLineReader &lineReader,
            const vsampler::util::DeviceFactory &deviceFactory) -> QHash<QString, vsampler::utau::VoiceAlias> {
        QSharedPointer<QIODevice> device(deviceFactory(fileInfo));
        if(!device->open(QIODevice::ReadOnly)) {
            return QHash<QString, vsampler::utau::VoiceAlias>();
        }
        QTextStream textStream(device.data());
        textStream.setCodec(codec);
        QHash<QString, vsampler::utau::VoiceAlias> result;
        while(!textStream.atEnd()) {
            auto element = lineReader(textStream.readLine());
            result[element.first] = element.second;
        }
        device->close();
        return result;
    };
