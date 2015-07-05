/**
 * Created by Hal@shurabaP on 2015/07/04.
 * This code is under The BSD 3-Clause License.
 * See more Licence.txt.
 * Copyright (c) 2015 Hal@shurabaP. All rights reserved.
 */
#ifndef VSAMPLER_CORPUSINFO_H
#define VSAMPLER_CORPUSINFO_H

#include <QObject>
#include "value/CorpusInfoProperty.h"

namespace vsampler {
namespace domain {

    class CorpusInfo final : QObject{
        Q_OBJECT
    private:
        corpus::CorpusInfoProperty &info;
    public:
        CorpusInfo(corpus::CorpusInfoProperty &corpusInfoProperty, QObject *parent = 0);
        void add(const corpus::Language language);
        void remove(const corpus::Language language);
        void changeAuthorAs(const corpus::Language language, const QString author);
        void changeDescriptionAs(const corpus::Language language, const QString description);
        void changeLicenseAs(const corpus::Language language, const QString license);
        void changeNameAs(const corpus::Language language, const QString name);
    signals:
        void notifyCorpusInfoChanged(corpus::CorpusInfoProperty *);
    };
}
}


#endif //VSAMPLER_CORPUSINFO_H
