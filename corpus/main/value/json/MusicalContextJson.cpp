/**
 * Created by Hal@shurabaP on 2015/06/02.
 * This code is under The BSD 3-Clause License.
 * See more Licence.txt.
 * Copyright (c) 2015 Hal@shurabaP. All rights reserved.
 */
#include <QJsonObject>

#include "value/MusicalContext.h"

#include "MusicalContextJson.h"
#include "util/Execption.h"

using namespace vsampler::corpus;

namespace {
    const QString NoteNumberKey("note_number");
    const QString BrightnessKey("brightness");
    const QString VelocityKey("velocity");
    const QString TempoKey("tempo");
    const QString DurationKey("duration");
    const QString keys[] = { NoteNumberKey, BrightnessKey, VelocityKey, TempoKey, DurationKey };
}

QJsonValue &operator << (QJsonValue &left, const vsampler::corpus::MusicalContext &right) {
    QJsonObject json;
    json[NoteNumberKey] = right.noteNumber();
    json[BrightnessKey] = right.brightness();
    json[VelocityKey] = right.velocity();
    json[TempoKey] = right.tempo();
    json[DurationKey] = right.durationMs();
    return (left = json);
}

const QJsonValue &operator >> (const QJsonValue &left, vsampler::corpus::MusicalContext &right) {
    if(!left.isObject()) {
        throw new vsampler::util::Exception("MusicalContextJson can parse only JSON object.");
    }
    QJsonObject json(left.toObject());
    for(const auto &key : keys) {
        if(!json.contains(key)) {
            throw new vsampler::util::Exception("MusicalContextJson could not find the key : " + key);
        }
    }
    right = MusicalContext(
            json[NoteNumberKey].toInt(),
            json[BrightnessKey].toInt(),
            json[VelocityKey].toInt(),
            json[TempoKey].toInt(),
            json[DurationKey].toInt()
    );
    return left;
}


