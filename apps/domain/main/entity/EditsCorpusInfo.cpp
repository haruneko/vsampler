/**
 * Created by Hal@shurabaP on 2015/07/04.
 * This code is under The BSD 3-Clause License.
 * See more Licence.txt.
 * Copyright (c) 2015 Hal@shurabaP. All rights reserved.
 */
#include "EditsCorpusinfo.h"

void vsampler::domain::EditsCorpusInfo::changeAuthorAs(const corpus::Language &language, const QString &author) {
    info().author()[language] = author;
    notifyInfoChanged();
}

void vsampler::domain::EditsCorpusInfo::changeDescriptionAs(const corpus::Language &language, const QString &description) {
    info().description()[language] = description;
    notifyInfoChanged();
}

void vsampler::domain::EditsCorpusInfo::add(const corpus::Language &language) {
    info().author()[language] = QString();
    info().description()[language] = QString();
    info().license()[language] = QString();
    info().name()[language] = QString();
    notifyInfoChanged();
}

vsampler::domain::EditsCorpusInfo::Translatable vsampler::domain::EditsCorpusInfo::findTranslatableIn(
        const corpus::Language &language) {
    return Translatable(
            info().author().value(language, QString()),
            info().description().value(language, QString()),
            info().license().value(language, QString()),
            info().name().value(language, QString()));
}


void vsampler::domain::EditsCorpusInfo::remove(const corpus::Language &language) {
    info().author().remove(language);
    info().description().remove(language);
    info().license().remove(language);
    info().name().remove(language);
    notifyInfoChanged();
}

void vsampler::domain::EditsCorpusInfo::changeLicenseAs(const corpus::Language &language, const QString &license) {
    info().license()[language] = license;
    notifyInfoChanged();
}

void vsampler::domain::EditsCorpusInfo::changeNameAs(const corpus::Language &language, const QString &name) {
    info().name()[language] = name;
    notifyInfoChanged();
}

void vsampler::domain::EditsCorpusInfo::changeVersionAs(const QString &version) {
    info().setVersion(version);
    notifyInfoChanged();
}

void vsampler::domain::EditsCorpusInfo::changeIconPathAs(const QString &iconPath) {
    info().setIconPath(iconPath);
    notifyInfoChanged();
}

void vsampler::domain::EditsCorpusInfo::changeSamplePathAs(const QString &samplePath) {
    info().setSamplePath(samplePath);
    notifyInfoChanged();
}

void vsampler::domain::EditsCorpusInfo::changeWebAs(const QString &web) {
    info().setWeb(web);
    notifyInfoChanged();
}
