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
    class CorpusProperty;
}
}

QJsonValue &operator << (QJsonValue &left, const vsampler::corpus::CorpusProperty &right);
const QJsonValue &operator >> (const QJsonValue &left, vsampler::corpus::CorpusProperty &right);


#endif //vsampler_CORPUSJSON_H
