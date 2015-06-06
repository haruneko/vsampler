/**
 * Created by Hal@shurabaP on 2015/05/04.
 * This code is under The BSD 3-Clause License.
 * See more Licence.txt.
 * Copyright (c) 2015 Hal@shurabaP. All rights reserved.
 */
#ifndef SCORES_ROOT_TRACK_H
#define SCORES_ROOT_TRACK_H

#include <QHash>
#include <QSharedData>
#include <QSharedDataPointer>
#include "ControlTrack.h"

namespace vsampler {
namespace scores {

    class Track {
        class TrackData : public QSharedData {
        public:
            QHash<ControlTrack::Type, ControlTrack> controls;
        };
        QSharedDataPointer<TrackData> d;
    };

}
}


#endif //SCORES_ROOT_TRACK_H
