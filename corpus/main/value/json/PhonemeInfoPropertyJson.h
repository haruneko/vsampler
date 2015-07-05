/**
 * Created by Hal@shurabaP on 2015/06/02.
 * This code is under The BSD 3-Clause License.
 * See more Licence.txt.
 * Copyright (c) 2015 Hal@shurabaP. All rights reserved.
 */
#ifndef vsampler_PHONEMEMETAINFOJSON_H
#define vsampler_PHONEMEMETAINFOJSON_H

class QJsonValue;

namespace vsampler {
namespace corpus {
    class PhonemeInfoProperty;
}
}

QJsonValue &operator << (QJsonValue &left, const vsampler::corpus::PhonemeInfoProperty &right);
const QJsonValue &operator >> (const QJsonValue &left, vsampler::corpus::PhonemeInfoProperty &right);

#endif //vsampler_PHONEMEMETAINFOJSON_H
