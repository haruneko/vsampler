/**
 * Created by Hal@shurabaP on 2015/04/27.
 * This code is under The BSD 3-Clause License.
 * See more Licence.txt.
 * Copyright (c) 2015 Hal@shurabaP. All rights reserved.
 */
#include <QHash>
#include <QTextStream>
#include "MetaInfoReader.h"

using namespace vsampler::utau;
using namespace vsampler::utau::impl;

MetaInfo vsampler::utau::impl::MetaInfoReader::read(
        const QFileInfo &fileInfo,
        QTextCodec *codec,
        const vsampler::util::DeviceFactory &deviceFactory) {

    QSharedPointer<QIODevice> device = deviceFactory(fileInfo);
    if(!device->open(QIODevice::ReadOnly)) {
        return MetaInfo(QString(), QFileInfo(), QFileInfo(), QString(), QUrl());
    }
    QTextStream textStream(device.data());
    textStream.setCodec(codec);
    QHash<QString, QString> info;
    while (!textStream.atEnd()) {
        QString line = textStream.readLine();
        QStringList elements = line.split("=");
        if (elements.size() != 2) {
            continue;
        }
        info[elements[0]] = elements[1];
    }
    device->close();

    QString name = info.contains("name") ? info["name"] : QString();
    QFileInfo image = info.contains("image") ? info["name"] : QString();
    QFileInfo sample = info.contains("sample") ? info["sample"] : QString();
    QString author = info.contains("author") ? info["author"] : QString();
    QUrl web = info.contains("web") ? info["web"] : QString();
    return MetaInfo(name, image, sample, author, web);
}
