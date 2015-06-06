/**
 * Created by Hal@shurabaP on 2015/05/03.
 * This code is under The BSD 3-Clause License.
 * See more Licence.txt.
 * Copyright (c) 2015 Hal@shurabaP. All rights reserved.
 */
#ifndef SCORES_ROOT_CONTROLCHANGEEVENT_H
#define SCORES_ROOT_CONTROLCHANGEEVENT_H

#include <QSharedData>
#include <QSharedDataPointer>
#include "value/Event.h"

namespace vsampler {
namespace scores {

    class ControlChangeEvent final : public Event {
        class ControlChangeEventData : public QSharedData {
        public:
            ControlChangeEventData() : ControlChangeEventData(0, 0) { }
            ControlChangeEventData(int tick, int value) : tick(tick), value(value) { }
            int tick;
            int value;
        };
        QSharedDataPointer<ControlChangeEventData> d;
    public:
        ControlChangeEvent() : d() { }
        ControlChangeEvent(int tick, int value) : d(new ControlChangeEventData(tick, value)) { }
        ControlChangeEvent(const ControlChangeEvent &other) : d(other.d) { }

        EventType type() const override { return EventType::ControlChange; }
        int tick() const override { return d->tick; }
        int value() const { return d->value; }
        void setTick(int tick) { d->tick = tick; }
        void setValue(int value) { d->value = value; }
        bool operator ==(const Event &other) const override {
            if(type() != other.type()) {
                return false;
            }
            const ControlChangeEvent *o = dynamic_cast<const ControlChangeEvent *>(&other);
            return tick() == o->tick() && value() == o->value();
        }
    };

}
}

#endif //SCORES_ROOT_CONTROLCHANGEEVENT_H
