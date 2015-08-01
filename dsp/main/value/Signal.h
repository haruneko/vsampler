/**
 * Created by Hal@shurabaP on 2015/08/01.
 * This code is under The BSD 3-Clause License.
 * See more Licence.txt.
 * Copyright (c) 2015 Hal@shurabaP. All rights reserved.
 */
#ifndef VSAMPLER_SIGNAL_H
#define VSAMPLER_SIGNAL_H

#include <QSharedData>
#include <QSharedDataPointer>
#include "SignalBuffer.h"

namespace vsampler {
namespace dsp {
    class Signal final {
        class SignalData : public QSharedData {
        public:
            SignalData(int size, int samplingFrequency) : buffer(size, samplingFrequency) { }
            explicit SignalData(const SignalBuffer &buffer) : buffer(buffer) { }
            SignalData(const SignalData &d) : SignalData(d.buffer) { }
            SignalBuffer buffer;
        };
        QSharedDataPointer<SignalData> d;
    public:
        Signal() : Signal(0, 0) { }
        Signal(int size, int samplingFrequency) : d(new SignalData(size, samplingFrequency)) { }
        Signal(const SignalBuffer &buffer) : d(new SignalData(buffer)) { }
        Signal(const Signal &other) : d(other.d) { }

        void zeroClear() { d->buffer.zeroClear(); }

        double meanSquareBetween(int begin, int end) const { return d->buffer.meanSquareBetween(begin, end); }
        double maxBetween(int begin, int end) const { return d->buffer.maxBetween(begin, end); }

        double meanSquareBetween(double beginMillis, double endMillis) const { return d->buffer.meanSquareBetween(beginMillis, endMillis); }
        double maxBetween(double beginMillis, double endMillis) const { return d->buffer.maxBetween(beginMillis, endMillis); }

        const double *dataAt(int position) const { return d->buffer.dataAt(position); }
        int indexOf(double millis) const { return d->buffer.indexOf(millis); }
        double lengthMillis() const { return d->buffer.lengthMillis(); }

        const double *data() const { return d->buffer.data; }
        double *data() { return d->buffer.data; }

        int samplingFrequency() const { return d->buffer.samplingFrequency; }
        int size() const { return d->buffer.size; }
    };
}
}


#endif //VSAMPLER_SIGNAL_H
