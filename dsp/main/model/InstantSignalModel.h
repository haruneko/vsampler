/**
 * Created by Hal@shurabaP on 2015/08/08.
 * This code is under The BSD 3-Clause License.
 * See more Licence.txt.
 * Copyright (c) 2015 Hal@shurabaP. All rights reserved.
 */
#ifndef VSAMPLER_INSTANTSIGNALMODEL_H
#define VSAMPLER_INSTANTSIGNALMODEL_H

#include "value/Signal.h"

namespace vsampler {
namespace dsp {

    class InstantSignalModel {
    public:
        virtual ~InstantSignalModel() { }
        virtual void add(Signal &signal, double positionMillis) = 0;
    };

}
}

#endif //VSAMPLER_INSTANTSIGNALMODEL_H
