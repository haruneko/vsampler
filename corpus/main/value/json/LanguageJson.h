/**
 * Created by Hal@shurabaP on 2015/06/05.
 * This code is under The BSD 3-Clause License.
 * See more Licence.txt.
 * Copyright (c) 2015 Hal@shurabaP. All rights reserved.
 */
#ifndef vsampler_LANGUAGEJSON_H
#define vsampler_LANGUAGEJSON_H

class QJsonValue;

namespace vsampler {
namespace corpus {
    class Language;
}
}

QJsonValue &operator << (QJsonValue &left, const vsampler::corpus::Language &right);
const QJsonValue &operator >> (const QJsonValue &left, vsampler::corpus::Language &right);

#endif //vsampler_LANGUAGEJSON_H
