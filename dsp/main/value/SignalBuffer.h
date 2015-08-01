/**
 * Created by Hal@shurabaP on 2015/08/01.
 * This code is under The BSD 3-Clause License.
 * See more Licence.txt.
 * Copyright (c) 2015 Hal@shurabaP. All rights reserved.
 */
#ifndef VSAMPLER_SIGNALBUFFER_H
#define VSAMPLER_SIGNALBUFFER_H

namespace vsampler {
namespace dsp {

    class SignalBuffer final {
        SignalBuffer() : data(0), size(0), samplingFrequency(0) { }
    public:
        SignalBuffer(int size, int samplingFrequency);
        SignalBuffer(const SignalBuffer &other);
        ~SignalBuffer();
        void zeroClear();

        double meanSquareBetween(int begin, int end) const;
        double maxBetween(int begin, int end) const;

        double meanSquareBetween(double beginMillis, double endMillis) const;
        double maxBetween(double beginMillis, double endMillis) const;

        const double *dataAt(int position) const;
        int indexOf(double millis) const;
        double lengthMillis() const;

        double *data;
        const int size;
        const int samplingFrequency;
    };
}
}


#endif //VSAMPLER_SIGNALBUFFER_H
