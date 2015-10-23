/**
 * Created by Hal@shurabaP on 2015/08/08.
 * This code is under The BSD 3-Clause License.
 * See more Licence.txt.
 * Copyright (c) 2015 Hal@shurabaP. All rights reserved.
 */
#include "Specgram.h"

vsampler::dsp::Specgram::SpecgramData::SpecgramData(int fftSize, int frequency, int length, double frameMillis) :
        data(), frameMillis(frameMillis) {
    for(int i = 0; i < length; i++) {
        data.append(Spectrum(fftSize, frequency));
    }
}

void vsampler::dsp::Specgram::SpecgramData::zeroClear() {
    for(Spectrum &s : data) {
        s.zeroClear();
    }
}

int vsampler::dsp::Specgram::SpecgramData::fftSize() const {
    int fftSize = 0;
    for(const Spectrum &s : data) {
        fftSize = std::max(fftSize, s.fftSize());
    }
    return fftSize;
}

int vsampler::dsp::Specgram::SpecgramData::frequency() const {
    int frequency = 0;
    for(const Spectrum &s : data) {
        frequency = std::max(frequency, s.frequency());
    }
    return frequency;
}

const vsampler::dsp::Spectrum vsampler::dsp::Specgram::operator()(double millis) const {
    return (*this)[(int)(millis / frameMillis())];
}

vsampler::dsp::Spectrum vsampler::dsp::Specgram::operator()(double millis) {
    return (*this)[(int)(millis / frameMillis())];
}

const vsampler::dsp::Spectrum vsampler::dsp::Specgram::operator[](int index) const {
    return d->data.value(index, Spectrum());
}

 vsampler::dsp::Spectrum vsampler::dsp::Specgram::operator[](int index) {
    return d->data.value(index, Spectrum());
}
