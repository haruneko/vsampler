/**
 * Created by Hal@shurabaP on 2015/04/27.
 * This code is under The BSD 3-Clause License.
 * See more Licence.txt.
 * Copyright (c) 2015 Hal@shurabaP. All rights reserved.
 */
#include <QStringList>

#include "VoiceAliasLineReader.h"

using namespace vsampler::utau;
using namespace vsampler::utau::impl;

namespace {
    double parseDouble(const QString &string) {
        bool ok;
        double result = string.toDouble(&ok);
        if(!ok) {
            qWarning(("`" + string + "` is not numeric.").toUtf8().data());
        }
        return result;
    }
}

const vsampler::utau::impl::VoiceAliasLineReader vsampler::utau::impl::FileVoiceAliasLineReader =
    [](const QString &line) -> VoiceAliasLineElement {
        QStringList elements(line.split(","));
        if(elements.size() != 6) {
            return VoiceAliasLineElement();
        }
        QStringList fileAndLabel = elements[0].split("=");
        if(fileAndLabel.size() != 2) {
            return VoiceAliasLineElement();
        }

        double offset = parseDouble(elements[1]);
        double fixed = parseDouble(elements[2]);
        double rightBlank = parseDouble(elements[3]);
        double preUtterance = parseDouble(elements[4]);
        double overlap = parseDouble(elements[5]);

        return VoiceAliasLineElement(fileAndLabel[1], VoiceAlias(fileAndLabel[0], offset, fixed, rightBlank, preUtterance, overlap));
    };
