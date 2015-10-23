/**
 * Created by Hal@shurabaP on 2015/08/01.
 * This code is under The BSD 3-Clause License.
 * See more Licence.txt.
 * Copyright (c) 2015 Hal@shurabaP. All rights reserved.
 */
#ifndef VSAMPLER_CONTOUR_H
#define VSAMPLER_CONTOUR_H

#include <QList>
#include <QSharedData>
#include <QSharedDataPointer>

namespace vsampler {
namespace dsp {
    template <class T> class Contour final {
        class ContourData : public QSharedData {
        public:
            ContourData(const QList<T> &data, int samplingFrequency) : data(data), samplingFrequency(samplingFrequency) { }
            explicit ContourData(int samplingFrequency) : ContourData(QList<double>(), samplingFrequency) { }
            const int samplingFrequency;
            QList<T> data;
        };
        QSharedDataPointer<ContourData> d;
    public:
        Contour() : Contour(QList<T>(), 0) { }
        Contour(const QList<T> &data, int samplingFrequency) : d(new ContourData(data, samplingFrequency)) { }
        explicit Contour(int samplingFrequency) : d(new ContourData(samplingFrequency)) { }

        const QList<T> &data() const { return d->data; }
        QList<T> &data() { return d->data; }
        int samplingFrequency() const { return d->samplingFrequency; }
        double lengthMillis() const { return (double)(d->data.size()) / d->samplingFrequency * 1000.0;}
        T valueAt(double millis) const {
            double actualIndex = millis / lengthMillis() * d->data.size();
            int index = std::max(0, std::min((int)actualIndex, d->data.size() - 1));
            return d->data[index];
        }
    };
}
}


#endif //VSAMPLER_CONTOUR_H
