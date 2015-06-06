/**
 * Created by Hal@shurabaP on 2015/04/28.
 * This code is under The BSD 3-Clause License.
 * See more Licence.txt.
 * Copyright (c) 2015 Hal@shurabaP. All rights reserved.
 */
#ifndef UTIL_DEVICEFACTORY_H
#define UTIL_DEVICEFACTORY_H

#include <functional>
#include <QFileInfo>
#include <QIODevice>
#include <QSharedPointer>

namespace vsampler {
namespace util {

    typedef std::function<QSharedPointer<QIODevice>(const QFileInfo &)> DeviceFactory;

    extern const DeviceFactory FileDeviceFactory;

}
}



#endif //UTIL_DEVICEFACTORY_H
