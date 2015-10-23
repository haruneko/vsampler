/**
 * Created by Hal@shurabaP on 2015/08/08.
 * This code is under The BSD 3-Clause License.
 * See more Licence.txt.
 * Copyright (c) 2015 Hal@shurabaP. All rights reserved.
 */
#ifndef VSAMPLER_SPECGRAM_H
#define VSAMPLER_SPECGRAM_H

#include <QList>
#include <QSharedData>
#include <QSharedDataPointer>

#include "Spectrum.h"

namespace vsampler {
namespace dsp {
    class Specgram final {
        class SpecgramData : public QSharedData {
        public:
            SpecgramData() : SpecgramData(0, 0, 0, 0.0) { }
            SpecgramData(int fftSize, int frequency, int length, double frameMillis);

            explicit SpecgramData(const QList<Spectrum> &data, double frameMillis) : data(data), frameMillis(frameMillis) { }
            SpecgramData(const SpecgramData &other): SpecgramData(other.data, other.frameMillis) { }

            QList<Spectrum> data;
            double frameMillis;
            void zeroClear();
            int fftSize() const;
            int frequency() const;
        };
        QSharedDataPointer<SpecgramData> d;
    public:
        Specgram() : Specgram(0, 0, 0, 0.0) { }
        Specgram(int fftSize, int frequency, int length, double frameMillis) : d(new SpecgramData(fftSize, frequency, length, frameMillis)) { }
        Specgram(const QList<Spectrum> &data, double frameMillis) : d(new SpecgramData(data, frameMillis)) { }
        Specgram(const Specgram &other) : d(other.d) { }

        int fftSize() const { return d->fftSize(); }
        void zeroClear() { d->zeroClear(); }
        const QList<Spectrum> &data() const { return d->data; }
        double frameMillis() const { return d->frameMillis; }

        const Spectrum operator[] (int index) const;
        Spectrum operator[] (int index);
        const Spectrum operator() (double millis) const;
        Spectrum operator() (double millis);
    };
}
}

#endif //VSAMPLER_SPECGRAM_H
