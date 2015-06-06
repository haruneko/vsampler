/**
 * Created by Hal@shurabaP on 2015/06/05.
 * This code is under The BSD 3-Clause License.
 * See more Licence.txt.
 * Copyright (c) 2015 Hal@shurabaP. All rights reserved.
 */
#ifndef vsampler_CORPUSJSON_H
#define vsampler_CORPUSJSON_H

class QJsonValue;

namespace vsampler {
namespace corpus {
    class Corpus;
}
}

QJsonValue &operator << (QJsonValue &left, const vsampler::corpus::Corpus &right);
const QJsonValue &operator >> (const QJsonValue &left, vsampler::corpus::Corpus &right);


#endif //vsampler_CORPUSJSON_H
