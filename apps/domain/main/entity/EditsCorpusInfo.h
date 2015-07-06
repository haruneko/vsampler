/**
 * Created by Hal@shurabaP on 2015/07/04.
 * This code is under The BSD 3-Clause License.
 * See more Licence.txt.
 * Copyright (c) 2015 Hal@shurabaP. All rights reserved.
 */
#ifndef VSAMPLER_CORPUSINFO_H
#define VSAMPLER_CORPUSINFO_H

#include "value/CorpusInfoProperty.h"

namespace vsampler {
namespace domain {

    class EditsCorpusInfo {
    protected:
        virtual corpus::CorpusInfoProperty &info() = 0;
        virtual void notifyInfoChanged() = 0;
    public:
        virtual ~EditsCorpusInfo() { }

        class Translatable final {
        public:
            Translatable(const Translatable &other) : Translatable(other.author, other.description, other.license, other.name) { }
            Translatable(const QString &author, const QString &description, const QString &license, const QString &name)
                    : author(author), description(description), license(license), name(name) { }
            const QString author;
            const QString description;
            const QString license;
            const QString name;
        };

        void add(const corpus::Language &language);
        Translatable findTranslatableIn(const corpus::Language &language);
        void remove(const corpus::Language &language);
        void changeAuthorAs(const corpus::Language &language, const QString &author);
        void changeDescriptionAs(const corpus::Language &language, const QString &description);
        void changeLicenseAs(const corpus::Language &language, const QString &license);
        void changeNameAs(const corpus::Language &language, const QString &name);
        void changeVersionAs(const QString &version);
        void changeIconPathAs(const QString &iconPath);
        void changeSamplePathAs(const QString &samplePath);
        void changeWebAs(const QString &web);
    };
}
}


#endif //VSAMPLER_CORPUSINFO_H
