/**
 * Created by Hal@shurabaP on 2015/08/01.
 * This code is under The BSD 3-Clause License.
 * See more Licence.txt.
 * Copyright (c) 2015 Hal@shurabaP. All rights reserved.
 */
#include "SpectrumBuffer.h"

vsampler::dsp::SpectrumBuffer::SpectrumBuffer(int fftSize, int frequency)
        : fftSize(fftSize), frequency(frequency), data(new double[fftSize * 2]) {
}

vsampler::dsp::SpectrumBuffer::SpectrumBuffer(const SpectrumBuffer &other) : SpectrumBuffer(other.fftSize, other.frequency) {
    for(int i = 0; i < fftSize * 2; i++) {
        data[i] = other.data[i];
    }
}

vsampler::dsp::SpectrumBuffer::~SpectrumBuffer() {
    delete[] data;
}

void vsampler::dsp::SpectrumBuffer::zeroClear() {
    for(int i = 0; i < fftSize * 2; i++) {
        data[i] = 0;
    }
}
