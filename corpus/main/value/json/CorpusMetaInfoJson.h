/**
 * Created by Hal@shurabaP on 2015/06/03.
 * This code is under The BSD 3-Clause License.
 * See more Licence.txt.
 * Copyright (c) 2015 Hal@shurabaP. All rights reserved.
 */
#ifndef vsampler_CORPUSMETAINFOJSON_H
#define vsampler_CORPUSMETAINFOJSON_H

class QJsonValue;

namespace vsampler {
namespace corpus {
    class CorpusMetaInfo;
}
}

QJsonValue &operator << (QJsonValue &left, const vsampler::corpus::CorpusMetaInfo &right);
const QJsonValue &operator >> (const QJsonValue &left, vsampler::corpus::CorpusMetaInfo &right);

#endif //vsampler_CORPUSMETAINFOJSON_H
