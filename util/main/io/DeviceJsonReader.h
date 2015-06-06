/**
 * Created by Hal@shurabaP on 2015/06/06.
 * This code is under The BSD 3-Clause License.
 * See more Licence.txt.
 * Copyright (c) 2015 Hal@shurabaP. All rights reserved.
 */
#ifndef VSAMPLER_DEVICEJSONREADER_H
#define VSAMPLER_DEVICEJSONREADER_H

#include <QJsonDocument>

#include "DeviceReader.h"
#include "DeviceTextReader.h"
#include "json/Json.h"
#include "util/Execption.h"

namespace vsampler {
namespace util {

    template  <class T> class DeviceJsonReader final : public DeviceReader<T> {
    private:
        QTextCodec *codec;
    public:
        DeviceJsonReader(QTextCodec *codec = QTextCodec::codecForName("utf-8")) : codec(codec) { }

        Try<T> read(const QSharedPointer<QIODevice> &device) {
            return Try<T>::apply([device, codec]() -> {
                QString jsonString = DeviceTextReader::readAll(device, codec);
                QJsonParseError error;
                QJsonDocument doc(QJsonDocument::fromJson(jsonString.toUtf8(), &error).object());
                if(error.error != QJsonParseError::NoError) {
                    throw new util::Exception(
                            "Json parse error @" + QString::number(error.offset) + " message is `"  + error.errorString() + "`\n");
                }
                if(!doc.isObject()) {
                    throw new Exception("Given JSON is not an object.");
                }
                return Json::fromJson<T>(doc.object());
            });
        }
    };

}
}


#endif //VSAMPLER_DEVICEJSONREADER_H
