/**
 * Created by Hal@shurabaP on 2015/06/05.
 * This code is under The BSD 3-Clause License.
 * See more Licence.txt.
 * Copyright (c) 2015 Hal@shurabaP. All rights reserved.
 */
#include <QJsonArray>
#include <QJsonObject>

#include "value/CorpusProperty.h"

#include "CorpusPropertyJson.h"
#include "CorpusInfoPropertyJson.h"
#include "value/json/LanguageJson.h"
#include "value/json/MusicalContextJson.h"
#include "PhonemeInfoPropertyJson.h"
#include "value/json/PronounceJson.h"

#include "json/QSetJson.h"
#include "json/QHashJson.h"
#include "json/Json.h"

#include "util/Execption.h"

using namespace vsampler::corpus;
using namespace vsampler::util;

namespace {
    const QString InfoPropertyKey("info");
    const QString PhonemesKey("phonemes");
    const QString keys[] = {InfoPropertyKey, PhonemesKey };
}

QJsonValue &operator << (QJsonValue &left, const vsampler::corpus::CorpusProperty &right) {
    QJsonObject json;
    json[InfoPropertyKey] = Json::toJson(right.infoProperty());
    json[PhonemesKey] = Json::toJson(right.phonemeSet());
    return (left = json);
}

const QJsonValue &operator >> (const QJsonValue &left, vsampler::corpus::CorpusProperty &right) {
    if(!left.isObject()) {
        throw new Exception("CorpusJson can parse only JSON object.");
    }
    QJsonObject json(left.toObject());
    for(const QString &key : keys) {
        if(!json.contains(key)) {
            throw new Exception("CorpusJson could not find the key : " + key);
        }
    }
    right = CorpusProperty(
            Json::fromJson<CorpusInfoProperty>(json[InfoPropertyKey]),
            Json::fromJson<QHash<Pronounce, PhonemeSet> >(json[PhonemesKey]));
    return left;
}

