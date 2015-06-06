/**
 * Created by Hal@shurabaP on 2015/06/05.
 * This code is under The BSD 3-Clause License.
 * See more Licence.txt.
 * Copyright (c) 2015 Hal@shurabaP. All rights reserved.
 */
#include <QJsonObject>

#include "value/Language.h"
#include "LanguageJson.h"
#include "util/Execption.h"

QJsonValue &operator << (QJsonValue &left, const vsampler::corpus::Language &right) {
    return (left = QJsonValue(right.iso()));
}

const QJsonValue &operator >> (const QJsonValue &left, vsampler::corpus::Language &right) {
    if(!left.isString()) {
        throw new vsampler::util::Exception("LanguageJson can parse only JSON object.");
    }
    right = vsampler::corpus::Language(left.toString());
    return left;
}
