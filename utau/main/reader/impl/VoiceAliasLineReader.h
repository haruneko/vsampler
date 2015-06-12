/**
 * Created by Hal@shurabaP on 2015/04/27.
 * This code is under The BSD 3-Clause License.
 * See more Licence.txt.
 * Copyright (c) 2015 Hal@shurabaP. All rights reserved.
 */
#ifndef UTAU_LINEREADER_H
#define UTAU_LINEREADER_H

#include <QSharedPointer>
#include <QString>
#include "value/VoiceAlias.h"

namespace vsampler {
namespace utau {
namespace impl {

    typedef QPair<QString, const VoiceAlias> VoiceAliasLineElement;

    /**
     * VoiceAliasLineReader reads and parses one line from oto.ini then convert to VoiceAlias.
     */
    typedef std::function<VoiceAliasLineElement(const QString&)> VoiceAliasLineReader;

    extern const VoiceAliasLineReader FileVoiceAliasLineReader;
}
}
}


#endif //UTAU_LINEREADER_H
