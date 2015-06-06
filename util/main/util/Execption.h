/**
 * Created by Hal@shurabaP on 2015/06/06.
 * This code is under The BSD 3-Clause License.
 * See more Licence.txt.
 * Copyright (c) 2015 Hal@shurabaP. All rights reserved.
 */
#ifndef VSAMPLER_EXECPTION_H
#define VSAMPLER_EXECPTION_H

#include <QString>

namespace vsampler {
namespace util {

    class Exception {
    private:
        static QString getMessageInternal(const Exception *e) {
            return e->message + (e->cause != NULL ? "\n  Caused by " + getMessageInternal(e->cause) : QString());
        }
    public:
        Exception() : Exception(QString(), NULL) { }
        Exception(const QString &message, const Exception *cause = NULL) : message(message), cause(cause) { }
        Exception(const Exception &other) : Exception(other.message, other.cause) { }

        QString messages() const {
            getMessageInternal(this);
        }

        const QString message;
        const Exception *cause;
    };
}
}
#endif //VSAMPLER_EXECPTION_H
