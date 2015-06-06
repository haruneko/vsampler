/**
 * Created by Hal@shurabaP on 2015/06/05.
 * This code is under The BSD 3-Clause License.
 * See more Licence.txt.
 * Copyright (c) 2015 Hal@shurabaP. All rights reserved.
 */
#include <QJsonObject>

#include "value/Pronounce.h"
#include "PronounceJson.h"
#include "util/Execption.h"

QJsonValue &operator << (QJsonValue &left, const vsampler::corpus::Pronounce &right) {
    return (left = right.value());
}

const QJsonValue &operator >> (const QJsonValue &left, vsampler::corpus::Pronounce &right) {
    if(!left.isString()) {
        throw new vsampler::util::Exception("PronounceJson can parse only JSON object.");
    }
    right = vsampler::corpus::Pronounce(left.toString());
    return left;
}
