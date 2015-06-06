/**
 * Created by Hal@shurabaP on 2015/05/04.
 * This code is under The BSD 3-Clause License.
 * See more Licence.txt.
 * Copyright (c) 2015 Hal@shurabaP. All rights reserved.
 */
#ifndef SCORES_ROOT_CONTROLTRACK_H
#define SCORES_ROOT_CONTROLTRACK_H

#include <QList>
#include <QSharedData>
#include <QSharedDataPointer>
#include "ControlChangeEvent.h"

namespace vsampler {
namespace scores {

    class ControlTrack final {
        class ControlTrackData : public QSharedData {
        public:
            ControlTrackData(int defaultValue, int minValue, int maxValue, const QList<ControlChangeEvent> &control)
                    : defaultValue(defaultValue), minValue(minValue), maxValue(maxValue), control(control) { }
            ControlTrackData() : ControlTrackData(64, 0, 127, QList<ControlChangeEvent>()) { }
            ControlTrackData(const ControlTrackData &other) : ControlTrackData(other.defaultValue, other.minValue, other.maxValue, other.control) { }

            int defaultValue;
            int minValue;
            int maxValue;
            QList<ControlChangeEvent> control;
        };
        QSharedDataPointer<ControlTrackData> d;
    public:
        ControlTrack() : d(new ControlTrackData()) { }
        ControlTrack(const ControlTrack &other) : d(other.d) { }
        ControlTrack(int defaultValue, int minValue, int maxValue, const QList<ControlChangeEvent> &control)
                : d(new ControlTrackData(defaultValue, minValue, maxValue, control)) { }

        QList<ControlChangeEvent> rawValues() const { return d->control; }
        enum Type {
            Unknown = -1,
            Brightness,
            Gendor,
        };
    };

}
}


#endif //SCORES_ROOT_CONTROLTRACK_H
