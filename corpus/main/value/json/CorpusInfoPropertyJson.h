/**
 * Created by Hal@shurabaP on 2015/06/03.
 * This code is under The BSD 3-Clause License.
 * See more Licence.txt.
 * Copyright (c) 2015 Hal@shurabaP. All rights reserved.
 */
#ifndef VSAMPLER_CORPUSINFOPROPERTYJSON_H
#define VSAMPLER_CORPUSINFOPROPERTYJSON_H

class QJsonValue;

namespace vsampler {
namespace corpus {
    class CorpusInfoProperty;
}
}

QJsonValue &operator << (QJsonValue &left, const vsampler::corpus::CorpusInfoProperty &right);
const QJsonValue &operator >> (const QJsonValue &left, vsampler::corpus::CorpusInfoProperty &right);

#endif //VSAMPLER_CORPUSINFOPROPERTYJSON_H
