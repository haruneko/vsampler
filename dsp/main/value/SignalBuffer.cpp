/**
 * Created by Hal@shurabaP on 2015/08/01.
 * This code is under The BSD 3-Clause License.
 * See more Licence.txt.
 * Copyright (c) 2015 Hal@shurabaP. All rights reserved.
 */
#include <math.h>
#include <QtGlobal>
#include "SignalBuffer.h"

vsampler::dsp::SignalBuffer::SignalBuffer(int size, int samplingFrequency)
        : size(size), samplingFrequency(samplingFrequency), data(new double[size]) {
}

vsampler::dsp::SignalBuffer::SignalBuffer(const SignalBuffer &other) : SignalBuffer(other.size, other.samplingFrequency) {
    for(int i = 0; i < size; i++) {
        data[i] = other.data[i];
    }
}

vsampler::dsp::SignalBuffer::~SignalBuffer() {
    delete[] data;
}

void vsampler::dsp::SignalBuffer::zeroClear() {
    for(int i = 0; i < size; i++) {
        data[i] = 0;
    }
}

double vsampler::dsp::SignalBuffer::meanSquareBetween(int begin, int end) const {
    double mean = 0;
    begin = qMax(0, begin);
    end = qMin(end, size - 1);
    for(int i = begin; i < end; i++) {
        mean += pow(data[i], 2.0);
    }
    mean /= (double)(end - begin);
    return sqrt(mean);
}

double vsampler::dsp::SignalBuffer::maxBetween(int begin, int end) const {
    double max = 0;
    begin = qMax(0, begin);
    end = qMin(end, size - 1);
    for(int i = begin; i < end; i++) {
        max = qMax(max, fabs(data[i]));
    }
    return max;
}

double vsampler::dsp::SignalBuffer::meanSquareBetween(double beginMillis, double endMillis) const {
    return meanSquareBetween(indexOf(beginMillis), indexOf(endMillis));
}

double vsampler::dsp::SignalBuffer::maxBetween(double beginMillis, double endMillis) const {
    return maxBetween(indexOf(beginMillis), indexOf(endMillis));
}

const double* vsampler::dsp::SignalBuffer::dataAt(int position) const {
    return data + position;
}

int vsampler::dsp::SignalBuffer::indexOf(double millis) const {
    return (int)(size * millis / lengthMillis());
}

double vsampler::dsp::SignalBuffer::lengthMillis() const {
    return (double)size / (double)samplingFrequency * 1000.0;
}
