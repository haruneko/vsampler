/**
 * Created by Hal@shurabaP on 2015/08/09.
 * This code is under The BSD 3-Clause License.
 * See more Licence.txt.
 * Copyright (c) 2015 Hal@shurabaP. All rights reserved.
 */
#ifndef VSAMPLER_WORLDSIGNALMODEL_H
#define VSAMPLER_WORLDSIGNALMODEL_H

#include <value/Contour.h>
#include <value/Signal.h>
#include "WorldInstantSignalModel.h"

namespace vsampler {
namespace dsp {

    class WorldSignalModel final {
    public:
        WorldSignalModel() : WorldSignalModel(Signal(), Contour<double>(), Contour<int>()) { }
        WorldSignalModel(const Signal &signal, const Contour<double> &f0, const Contour<int> peeks) :
                signal(signal), f0(f0), peeks(peeks) { }
        Signal signal;
        Contour<double> f0;
        Contour<int> peeks;

        WorldInstantSignalModel calculateInstantSignalAt(double millis) const;
    };

}
}


#endif //VSAMPLER_WORLDSIGNALMODEL_H
