/**
 * Created by Hal@shurabaP on 2015/06/06.
 * This code is under The BSD 3-Clause License.
 * See more Licence.txt.
 * Copyright (c) 2015 Hal@shurabaP. All rights reserved.
 */
#include <QTextStream>

#include "DeviceTextReader.h"

using namespace vsampler::util;

QString DeviceTextReader::readAll(QSharedPointer<QIODevice> &device, QTextCodec *codec) {
    if(device.isNull() || device->isOpen()) {
        return QString();
    }
    QTextStream ts(device.data());
    ts.setCodec(codec);
    return ts.readAll();
}

QString DeviceTextReader::readLine(QSharedPointer<QIODevice> &device, QTextCodec *codec) {
    if(device.isNull() || device->isOpen()) {
        return QString();
    }
    QTextStream ts(device.data());
    ts.setCodec(codec);
    return ts.readLine();
}
