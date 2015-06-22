/**
 * Created by Hal@shurabaP on 2015/06/05.
 * This code is under The BSD 3-Clause License.
 * See more Licence.txt.
 * Copyright (c) 2015 Hal@shurabaP. All rights reserved.
 */
#ifndef vsampler_PRONOUNCEJSON_H
#define vsampler_PRONOUNCEJSON_H

class QJsonValue;

namespace vsampler {
namespace corpus {
    class Pronounce;
}
}

QJsonValue &operator << (QJsonValue &left, const vsampler::corpus::Pronounce &right);
const QJsonValue &operator >> (const QJsonValue &left, vsampler::corpus::Pronounce &right);
QString stringify(vsampler::corpus::Pronounce &p);

#endif //vsampler_PRONOUNCEJSON_H
