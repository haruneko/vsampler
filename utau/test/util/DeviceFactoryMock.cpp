/**
 * Created by Hal@shurabaP on 2015/04/29.
 * This code is under The BSD 3-Clause License.
 * See more Licence.txt.
 * Copyright (c) 2015 Hal@shurabaP. All rights reserved.
 */
#include <QBuffer>
#include "DeviceFactoryMock.h"

using namespace vsampler::util;

const DeviceFactory vsampler::util::DeviceFactoryMock(const QString &content) {
    return DeviceFactory([content] (const QFileInfo &) -> QSharedPointer<QIODevice> {
        QBuffer *buffer = new QBuffer();
        buffer->setData(content.toUtf8());
        return QSharedPointer<QIODevice>(buffer);
    });
}
