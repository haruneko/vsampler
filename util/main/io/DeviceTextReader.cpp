/**
 * Created by Hal@shurabaP on 2015/06/06.
 * This code is under The BSD 3-Clause License.
 * See more Licence.txt.
 * Copyright (c) 2015 Hal@shurabaP. All rights reserved.
 */
#include <QTextStream>
#include <util/Execption.h>

#include "DeviceTextReader.h"

using namespace vsampler::util;

QString vsampler::util::DeviceTextReader::readAll(const QSharedPointer<QIODevice> &device, QTextCodec *codec) {
    if(device.isNull() || !device->isOpen() || !device->isReadable()) {
        throw new Exception("Given device is not readable.");
    }
    QTextStream ts(device.data());
    ts.setCodec(codec);
    return ts.readAll();
}

QString vsampler::util::DeviceTextReader::readLine(const QSharedPointer<QIODevice> &device, QTextCodec *codec) {
    if(device.isNull() || !device->isOpen() || !device->isReadable()) {
        throw new Exception("Given device is not readable.");
    }
    QTextStream ts(device.data());
    ts.setCodec(codec);
    return ts.readLine();
}
