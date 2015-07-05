/**
 * Created by Hal@shurabaP on 2015/06/03.
 * This code is under The BSD 3-Clause License.
 * See more Licence.txt.
 * Copyright (c) 2015 Hal@shurabaP. All rights reserved.
 */
#include <QJsonObject>

#include "value/Language.h"
#include "CorpusInfoPropertyJson.h"
#include "value/json/LanguageJson.h"
#include "json/QHashJson.h"
#include "json/QStringJson.h"
#include "json/Json.h"
#include "value/CorpusInfoProperty.h"
#include "util/Execption.h"

using namespace vsampler::corpus;
using namespace vsampler::util;

namespace {
    const QString NameKey("name");
    const QString VersionKey("version");
    const QString IconPathKey("icon");
    const QString SamplePathKey("sample");
    const QString AuthorKey("author");
    const QString WebKey("web");
    const QString LicenseKey("license");
    const QString DescriptionKey("description");
    const QString keys[] = { NameKey, VersionKey, IconPathKey, SamplePathKey, AuthorKey, WebKey, LicenseKey, DescriptionKey };
}

QJsonValue &operator << (QJsonValue &left, const CorpusInfoProperty &right) {
    QJsonObject json;
    json[NameKey] = Json::toJson(right.name());
    json[VersionKey] = Json::toJson(right.version());
    json[IconPathKey] = Json::toJson(right.iconPath().filePath());
    json[SamplePathKey] = Json::toJson(right.samplePath().filePath());
    json[AuthorKey] = Json::toJson(right.author());
    json[WebKey] = Json::toJson(right.web().toString());
    json[LicenseKey] = Json::toJson(right.license());
    json[DescriptionKey] = Json::toJson(right.description());
    left = json;
    return left;
}

const QJsonValue &operator >> (const QJsonValue &left, CorpusInfoProperty &right) {
    if(!left.isObject()) {
        throw new Exception("CorpusInfoProperty can parse only JSON object.");
    }
    QJsonObject json(left.toObject());
    for(const auto &key : keys) {
        if(!json.contains(key)) {
            throw new Exception("CorpusInfoProperty could not find the key : " + key);
        }
    }
    right = CorpusInfoProperty(
            Json::fromJson<QHash<Language, QString> >(json[NameKey]),
            json[VersionKey].toString(),
            QFileInfo(json[IconPathKey].toString()),
            QFileInfo(json[SamplePathKey].toString()),
            Json::fromJson<QHash<Language, QString> >(json[AuthorKey]),
            QUrl(json[WebKey].toString()),
            Json::fromJson<QHash<Language, QString> >(json[LicenseKey]),
            Json::fromJson<QHash<Language, QString> >(json[DescriptionKey]));
    return left;
}

