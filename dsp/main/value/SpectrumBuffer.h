/**
 * Created by Hal@shurabaP on 2015/08/01.
 * This code is under The BSD 3-Clause License.
 * See more Licence.txt.
 * Copyright (c) 2015 Hal@shurabaP. All rights reserved.
 */
#ifndef VSAMPLER_SPECTRUMBUFFER_H
#define VSAMPLER_SPECTRUMBUFFER_H

namespace vsampler {
namespace dsp {

    class SpectrumBuffer final {
    public:
        SpectrumBuffer() : SpectrumBuffer(0, 0) { }
        SpectrumBuffer(int fftSize, int frequency);
        SpectrumBuffer(const SpectrumBuffer &other);
        ~SpectrumBuffer();

        void zeroClear();

        const int fftSize;
        const int frequency;
        double *data;
    };

}
}


#endif //VSAMPLER_SPECTRUMBUFFER_H
