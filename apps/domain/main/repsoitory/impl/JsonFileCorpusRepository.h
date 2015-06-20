/**
 * Created by Hal@shurabaP on 2015/06/10.
 * This code is under The BSD 3-Clause License.
 * See more Licence.txt.
 * Copyright (c) 2015 Hal@shurabaP. All rights reserved.
 */
#ifndef VSAMPLER_JSONFILECORPUSREPOSITORY_H
#define VSAMPLER_JSONFILECORPUSREPOSITORY_H

#include <io/DeviceJsonWriter.h>
#include <io/DeviceJsonReader.h>
#include <io/DeviceFactory.h>
#include "value/CorpusProperty.h"
#include "repsoitory/CorpusRepository.h"

namespace vsampler {
namespace domain {
namespace impl {

    class JsonFileCorpusRepository final : public CorpusRepository {
        typedef util::DeviceWriter<corpus::CorpusProperty> Writer;
        typedef util::DeviceReader<corpus::CorpusProperty> Reader;
        QSharedPointer<Writer> writer;
        QSharedPointer<Reader> reader;
        util::DeviceFactory factory;
    public:
        JsonFileCorpusRepository(
                QSharedPointer<Writer> writer = QSharedPointer<Writer>(new util::DeviceJsonWriter<corpus::CorpusProperty>),
                QSharedPointer<Reader> reader = QSharedPointer<Reader>(new util::DeviceJsonReader<corpus::CorpusProperty>),
                const util::DeviceFactory factory = util::FileDeviceFactory
        ) : writer(writer), reader(reader), factory(factory) { }

        util::Try<Corpus> fetchBy(const CorpusId &id) override;

        util::Try<util::Unit> upsert(const Corpus &corpus) override;
    };

}
}
}

#endif //VSAMPLER_JSONFILECORPUSREPOSITORY_H
