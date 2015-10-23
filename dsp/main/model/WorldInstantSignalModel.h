/**
 * Created by Hal@shurabaP on 2015/08/09.
 * This code is under The BSD 3-Clause License.
 * See more Licence.txt.
 * Copyright (c) 2015 Hal@shurabaP. All rights reserved.
 */
#ifndef VSAMPLER_WORLDINSTANTSIGNALMODEL_H
#define VSAMPLER_WORLDINSTANTSIGNALMODEL_H

#include <value/Spectrum.h>
#include "InstantSignalModel.h"

namespace vsampler {
namespace dsp {

    class WorldInstantSignalModel final : public InstantSignalModel {
    public:
        WorldInstantSignalModel(int fftSize, int samplingFrequency) : power(fftSize, samplingFrequency), aperiodicity(fftSize, samplingFrequency) { }
        WorldInstantSignalModel(const Spectrum &power, const Spectrum &aperiodicity) : power(power), aperiodicity(aperiodicity) { }
        WorldInstantSignalModel(const WorldInstantSignalModel &other) : WorldInstantSignalModel(other.power, other.aperiodicity) { }
        Spectrum power;
        Spectrum aperiodicity;
    };

}
}


#endif //VSAMPLER_WORLDINSTANTSIGNALMODEL_H
