/**
 * Created by Hal@shurabaP on 2015/04/27.
 * This code is under The BSD 3-Clause License.
 * See more Licence.txt.
 * Copyright (c) 2015 Hal@shurabaP. All rights reserved.
 */
#ifndef UTAU_VOICEALIAS_H
#define UTAU_VOICEALIAS_H

#include <QFileInfo>
#include <QSharedData>
#include <QSharedDataPointer>
#include <QString>

namespace vsampler {
namespace utau {

    /**
     * VoiceAlias class is a value class for a single line of oto.ini.
     */
    class VoiceAlias {
        class VoiceAliasData : public QSharedData {
        public:
            VoiceAliasData(const QFileInfo &filePath,
                       double offsetMillis,
                       double fixedLengthMillis,
                       double rightBlankMillis,
                       double preUtteranceMillis,
                       double overlapMillis)
                    : filePath(filePath), offsetMillis(offsetMillis),
                      fixedLengthMillis(fixedLengthMillis),
                      rightBlankMillis(rightBlankMillis),
                      preUtteranceMillis(preUtteranceMillis),
                      overlapMillis(overlapMillis) { }
            QFileInfo filePath;
            double offsetMillis;
            double fixedLengthMillis;
            double rightBlankMillis;
            double preUtteranceMillis;
            double overlapMillis;
        };
        QSharedDataPointer<VoiceAliasData> d;
    public:
        VoiceAlias() : d() { }
        VoiceAlias(const QFileInfo &filePath,
                    double offsetMillis,
                    double fixedLengthMillis,
                    double rightBlankMillis,
                    double preUtteranceMillis,
                    double overlapMillis) :
                d(new VoiceAliasData(filePath, offsetMillis, fixedLengthMillis, rightBlankMillis, preUtteranceMillis, overlapMillis)) { }
        VoiceAlias(const VoiceAlias &other) : d(other.d) { }
        QFileInfo filePath() const { return d->filePath; }
        double offsetMillis() const { return d->offsetMillis; }
        double fixedLengthMillis() const { return d->fixedLengthMillis; }
        double rightBlankMillis() const { return d->rightBlankMillis; }
        double preUtteranceMillis() const { return d->preUtteranceMillis; }
        double overlapMillis() const { return d->overlapMillis; }

        bool operator ==(const VoiceAlias &o) const {
            return filePath() == o.filePath() &&
                    offsetMillis() == o.offsetMillis() &&
                    fixedLengthMillis() == o.fixedLengthMillis() &&
                    rightBlankMillis() == o.rightBlankMillis() &&
                    preUtteranceMillis() == o.preUtteranceMillis() &&
                    overlapMillis() == o.overlapMillis();
        }
    };
}
}


#endif //UTAU_VOICEALIAS_H
