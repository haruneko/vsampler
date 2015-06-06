/**
 * Created by Hal@shurabaP on 2015/05/03.
 * This code is under The BSD 3-Clause License.
 * See more Licence.txt.
 * Copyright (c) 2015 Hal@shurabaP. All rights reserved.
 */
#ifndef SCORES_ROOT_NOTEEVENT_H
#define SCORES_ROOT_NOTEEVENT_H

#include <QSharedData>
#include <QSharedDataPointer>
#include "value"

namespace vsampler {
namespace scores {

    class NoteEvent final : public Event {
        class NoteEventData : public QSharedData {
        public:
            NoteEventData() : NoteEventData(60, 0, 0, 64) { }
            NoteEventData(int noteNumber, int tick, int length, int velocity)
                    : noteNumber(noteNumber), tick(tick), length(length), velocity(velocity) { }
            int noteNumber;
            int tick;
            int length;
            int velocity;
        };
        QSharedDataPointer<NoteEventData> d;
    public:
        NoteEvent() : d() { }
        EventType type() const override { return EventType::Note; }
        NoteEvent(int noteNumber, int tick, int length, int velocity)
                : d(new NoteEventData(noteNumber, tick, length, velocity)) { }
        NoteEvent(const NoteEvent &other) : d(other.d) { }
        int noteNumber() const { return d->noteNumber; }
        int tick() const override { return d->tick; }
        int length() const { return d->length; }
        int velocity() const { return d->velocity; }
        void setNoteNumber(int noteNumber) { d->noteNumber = std::max(0, std::min(127, noteNumber)); }
        void setTick(int tick) { d->tick = tick; }
        void setLength(int length) { d->length = length; }
        void setVelocity(int velocity) { d->velocity = std::max(0, std::min(127, velocity)); }
        bool operator ==(const Event &other) const override {
            if(type() != other.type()) {
                return false;
            }
            const NoteEvent *o = dynamic_cast<const NoteEvent *>(&other);
            return noteNumber() == o->noteNumber() && tick() == o->tick() && length() == o->length() && velocity() == o->velocity();
        }
    };

}
}


#endif //SCORES_ROOT_NOTEEVENT_H
