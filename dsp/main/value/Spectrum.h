/**
 * Created by Hal@shurabaP on 2015/08/01.
 * This code is under The BSD 3-Clause License.
 * See more Licence.txt.
 * Copyright (c) 2015 Hal@shurabaP. All rights reserved.
 */
#ifndef VSAMPLER_SPECTRUM_H
#define VSAMPLER_SPECTRUM_H

#include <QSharedData>
#include <QSharedDataPointer>
#include "SpectrumBuffer.h"

namespace vsampler {
namespace dsp {
    class Spectrum final {
        class SpectrumData : public QSharedData {
        public:
            SpectrumData() : buffer() { }
            SpectrumData(int fftSize, int frequency) : buffer(fftSize, frequency) { }
            SpectrumData(const SpectrumBuffer &buffer) : buffer(buffer) { }
            SpectrumData(const SpectrumData &other) : SpectrumData(other.buffer) { }
            SpectrumBuffer buffer;
        };
        QSharedDataPointer<SpectrumData> d;
    public:
        Spectrum() : Spectrum(0, 0) { }
        Spectrum(int fftSize, int frequency) : d(new SpectrumData(fftSize, frequency)) { }
        explicit Spectrum(const SpectrumBuffer &buffer) : d(new SpectrumData(buffer)) { }
        Spectrum(const Spectrum &other) : d(other.d) { }

        void zeroClear() { d->buffer.zeroClear(); }
        int fftSize() const { return d->buffer.fftSize; }
        int frequency() const { return d->buffer.frequency; }
        const double *data() const { return d->buffer.data; }
        double *data() { return d->buffer.data; }
    };
}
}

#endif //VSAMPLER_SPECTRUM_H
