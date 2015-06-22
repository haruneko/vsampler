/**
 * Created by Hal@shurabaP on 2015/05/04.
 * This code is under The BSD 3-Clause License.
 * See more Licence.txt.
 * Copyright (c) 2015 Hal@shurabaP. All rights reserved.
 */
#ifndef CORPUS_ROOT_MUSICALCONTEXT_H
#define CORPUS_ROOT_MUSICALCONTEXT_H

#include <QHash>
#include <QSharedData>
#include <QSharedDataPointer>

namespace vsampler {
namespace corpus {

    class MusicalContext final {
        class MusicalContextData : public QSharedData {
        public:
            MusicalContextData(int noteNumber, int brightness, int velocity, int tempo, int durationMs)
                    : noteNumber(noteNumber), brightness(brightness), velocity(velocity), tempo(tempo), durationMs(durationMs) { }
            int noteNumber;
            int brightness;
            int velocity;
            int tempo;
            int durationMs;
        };
        QSharedDataPointer<MusicalContextData> d;
    public:
        MusicalContext() : MusicalContext(60, 64, 64, 120, 5000) { }
        MusicalContext(int noteNumber, int brightness, int velocity, int tempo, int durationMs)
                : d(new MusicalContextData(noteNumber, brightness, velocity, tempo, durationMs)) { }
        MusicalContext(const MusicalContext &other) : d(other.d) { }
        int noteNumber() const { return d->noteNumber; }
        int brightness() const { return d->brightness; }
        int velocity() const { return d->velocity; }
        int tempo() const { return d->tempo; }
        int durationMs() const { return d->durationMs; }

        bool operator ==(const MusicalContext &other) const {
            return noteNumber() == other.noteNumber() &&
                   brightness() == other.brightness() &&
                   velocity() == other.velocity() &&
                   tempo() == other.tempo() &&
                   durationMs() == other.durationMs();
        }
        MusicalContext &operator =(const MusicalContext &right) { this->d = right.d; return *this; }
    };

    // qHash should be inside namespace
    // see more: https://bugreports.qt.io/browse/QTBUG-34912
    inline uint qHash(const vsampler::corpus::MusicalContext &context, uint seed = 0) {
        return ::qHash(context.noteNumber(), seed) ^
               ::qHash(context.brightness(), seed) ^
               ::qHash(context.velocity(), seed) ^
               ::qHash(context.tempo(), seed) ^
               ::qHash(context.durationMs(), seed);
    }

}
}


#endif //CORPUS_ROOT_MUSICALCONTEXT_H
