/**
 * Created by Hal@shurabaP on 2015/05/03.
 * This code is under The BSD 3-Clause License.
 * See more Licence.txt.
 * Copyright (c) 2015 Hal@shurabaP. All rights reserved.
 */
#ifndef SCORES_ROOT_EVENT_H
#define SCORES_ROOT_EVENT_H

namespace vsampler {
namespace scores {

    class Event {
    public:
        enum EventType {
            Unknown = -1,
            Note = 1,
            ControlChange
        };
        virtual ~Event() {}
        virtual EventType type() const = 0;
        virtual bool operator ==(const Event &other) const = 0;
        virtual int tick() const = 0;
    };

}
};


#endif //SCORES_ROOT_EVENT_H
