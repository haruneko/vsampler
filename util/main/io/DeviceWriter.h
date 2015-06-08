/**
 * Created by Hal@shurabaP on 2015/06/06.
 * This code is under The BSD 3-Clause License.
 * See more Licence.txt.
 * Copyright (c) 2015 Hal@shurabaP. All rights reserved.
 */
#ifndef VSAMPLER_DEVICEWRITER_H
#define VSAMPLER_DEVICEWRITER_H

#include <QIODevice>
#include <QSharedPointer>

#include "util/Try.h"

namespace vsampler {
namespace util {
    template <class T> class DeviceWriter {
    public:
        virtual ~DeviceWriter() { }
        virtual Try<Unit> write(const T &t, const QSharedPointer<QIODevice> &device) = 0;
    };
}
}

#endif //VSAMPLER_DEVICEWRITER_H
