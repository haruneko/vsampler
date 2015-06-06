/**
 * Created by Hal@shurabaP on 2015/06/02.
 * This code is under The BSD 3-Clause License.
 * See more Licence.txt.
 * Copyright (c) 2015 Hal@shurabaP. All rights reserved.
 */
#ifndef vsampler_MUSICALCONTEXTJSON_H
#define vsampler_MUSICALCONTEXTJSON_H

class QJsonValue;

namespace vsampler {
namespace corpus {
    class MusicalContext;
}
}

QJsonValue &operator << (QJsonValue &left, const vsampler::corpus::MusicalContext &right);
const QJsonValue &operator >> (const QJsonValue &left, vsampler::corpus::MusicalContext &right);

#endif //vsampler_MUSICALCONTEXTJSON_H
