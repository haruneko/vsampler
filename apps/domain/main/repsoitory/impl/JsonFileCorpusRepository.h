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
#include "repsoitory/CorpusRepository.h"

namespace vsampler {
namespace domain {
namespace impl {

    class JsonFileCorpusRepository final : public CorpusRepository {
        util::DeviceJsonWriter<corpus::CorpusProperty> writer;
        util::DeviceJsonReader<corpus::CorpusProperty> reader;
        util::DeviceFactory factory;
    public:
        JsonFileCorpusRepository(
                const util::DeviceJsonWriter<corpus::CorpusProperty> &writer,
                const util::DeviceJsonReader<corpus::CorpusProperty> &reader,
                const util::DeviceFactory &factory
        ) : writer(writer), reader(reader), factory(factory) { }

        util::Try<Corpus> fetchBy(const CorpusId &id) override;

        util::Try<util::Unit> upsert(const Corpus &corpus) override;
    };

}
}
}

#endif //VSAMPLER_JSONFILECORPUSREPOSITORY_H
