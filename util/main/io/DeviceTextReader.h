/**
 * Created by Hal@shurabaP on 2015/06/06.
 * This code is under The BSD 3-Clause License.
 * See more Licence.txt.
 * Copyright (c) 2015 Hal@shurabaP. All rights reserved.
 */
#ifndef VSAMPLER_DEVICETEXTREADER_H
#define VSAMPLER_DEVICETEXTREADER_H

#include <QIODevice>
#include <QSharedPointer>
#include <QString>
#include <QTextCodec>

namespace vsampler {
namespace util {
    class DeviceTextReader {
    public:
        static QString readAll(QSharedPointer<QIODevice> &device, QTextCodec *codec = QTextCodec::codecForName("utf-8"));
        static QString readLine(QSharedPointer<QIODevice> &device, QTextCodec *codec = QTextCodec::codecForName("utf-8"));
    };
}
}


#endif //VSAMPLER_DEVICETEXTREADER_H
