/**
 * Created by Hal@shurabaP on 2015/04/27.
 * This code is under The BSD 3-Clause License.
 * See more Licence.txt.
 * Copyright (c) 2015 Hal@shurabaP. All rights reserved.
 */
#ifndef UTAU_METAINFOREADER_H
#define UTAU_METAINFOREADER_H

#include <functional>
#include <QFileInfo>
#include <QIODevice>
#include <QTextCodec>
#include <QSharedPointer>
#include "value/MetaInfo.h"
#include "io/DeviceFactory.h"

namespace vsampler {
namespace utau {
namespace impl {

    typedef std::function<MetaInfo(const QFileInfo&, QTextCodec*, const vsampler::util::DeviceFactory)> MetaInfoReader;
    extern const MetaInfoReader FileMetaInfoReader;

}
}
}

#endif //UTAU_METAINFOREADER_H
