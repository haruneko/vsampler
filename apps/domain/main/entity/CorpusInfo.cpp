/**
 * Created by Hal@shurabaP on 2015/07/04.
 * This code is under The BSD 3-Clause License.
 * See more Licence.txt.
 * Copyright (c) 2015 Hal@shurabaP. All rights reserved.
 */
#include "CorpusInfo.h"

vsampler::domain::CorpusInfo::CorpusInfo(corpus::CorpusInfoProperty &corpusInfoProperty, QObject *parent)
        : QObject(parent), info(corpusInfoProperty){
}

void vsampler::domain::CorpusInfo::changeAuthorAs(const corpus::Language language, const QString author) {
    info.author()[language] = author;
}

void vsampler::domain::CorpusInfo::changeDescriptionAs(const corpus::Language language, const QString description) {
    info.description()[language] = description;
}

void vsampler::domain::CorpusInfo::add(const corpus::Language language) {
    info.author()[language] = QString();
    info.description()[language] = QString();
    info.license()[language] = QString();
    info.name()[language] = QString();
}

void vsampler::domain::CorpusInfo::remove(const corpus::Language language) {
    info.author().remove(language);
    info.description().remove(language);
    info.license().remove(language);
    info.name().remove(language);
}

void vsampler::domain::CorpusInfo::changeLicenseAs(const corpus::Language language, const QString license) {
    info.license()[language] = license;
}

void vsampler::domain::CorpusInfo::changeNameAs(const corpus::Language language, const QString name) {
    info.name()[language] = name;
}
