/**
 * Created by Hal@shurabaP on 2015/06/02.
 * This code is under The BSD 3-Clause License.
 * See more Licence.txt.
 * Copyright (c) 2015 Hal@shurabaP. All rights reserved.
 */
#include <QString>
#include <QJsonObject>

#include "json/Json.h"

#include "value/PhonemeMetaInfo.h"
#include "value/json/PhonemeMetaInfoJson.h"
#include "value/json/MusicalContextJson.h"
#include "util/Execption.h"

using namespace vsampler::corpus;
using namespace vsampler::util;

namespace {
    const QString LabelKey("label");
    const QString PathKey("path");
    const QString TypeKey("type");
    const QString OffsetKey("offsetMillis");
    const QString LengthKey("lengthMillis");
    const QString PreutteranceKey("preutteranceMillis");
    const QString LoopBeginKey("loop_begin");
    const QString LoopEndKey("loop_end");
    const QString MusicalContextKey("musical_context");
    const QString keys[] = { LabelKey, PathKey, TypeKey, OffsetKey, LengthKey, PreutteranceKey, LoopBeginKey, LoopEndKey, MusicalContextKey };
}

using namespace vsampler::corpus;

QJsonValue &operator << (QJsonValue &left, const vsampler::corpus::PhonemeMetaInfo &right) {
    QJsonObject json;
    json[LabelKey] = right.label();
    json[PathKey] = right.path().filePath();
    json[TypeKey] = right.type();
    json[OffsetKey] = right.offsetMillis();
    json[LengthKey] = right.lengthMillis();
    json[PreutteranceKey] = right.preutteranceMillis();
    json[LoopBeginKey] = right.loopBeginMillis();
    json[LoopEndKey] = right.loopEndMillis();
    json[MusicalContextKey] = Json::toJson(right.context());
    return (left = QJsonValue(json));
}

const QJsonValue &operator >> (const QJsonValue &left, vsampler::corpus::PhonemeMetaInfo &right) {
    if(!left.isObject()) {
        throw new vsampler::util::Exception("PhonemeMetaInfoJson can parse only JSON object.");
    }
    QJsonObject json(left.toObject());
    for(const auto &key : keys) {
        if(!json.contains(key)) {
            throw new vsampler::util::Exception("PhonemeMetaInfoJson could not find the key : " + key);
        }
    }
    right = PhonemeMetaInfo(
            json[LabelKey].toString(),
            QFileInfo(json[PathKey].toString()),
            (PhonemeType)json[TypeKey].toInt(),
            json[OffsetKey].toInt(),
            json[LengthKey].toInt(),
            json[PreutteranceKey].toInt(),
            json[LoopBeginKey].toInt(),
            json[LoopEndKey].toInt(),
            Json::fromJson<MusicalContext>(json[MusicalContextKey])
    );
    return left;
}
