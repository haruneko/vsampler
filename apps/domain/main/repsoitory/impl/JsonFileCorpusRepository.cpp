/**
 * Created by Hal@shurabaP on 2015/06/10.
 * This code is under The BSD 3-Clause License.
 * See more Licence.txt.
 * Copyright (c) 2015 Hal@shurabaP. All rights reserved.
 */
#include "value/json/CorpusPropertyJson.h"

#include "JsonFileCorpusRepository.h"

using namespace vsampler::corpus;
using namespace vsampler::domain;
using namespace vsampler::util;

vsampler::util::Try<vsampler::domain::Corpus>
vsampler::domain::impl::JsonFileCorpusRepository::fetchBy(const CorpusId &id) {
    return reader.read(factory(QFileInfo(id))).map<Corpus>([id](const vsampler::corpus::CorpusProperty &prop) -> Corpus {
        return Corpus(id, prop);
    });
}

vsampler::util::Try<vsampler::util::Unit>
vsampler::domain::impl::JsonFileCorpusRepository::upsert(const Corpus &corpus) {
    return writer.write(corpus.value(), factory(QFileInfo(corpus.id()))).map<Unit>([](Unit u) -> Unit { return u; });
}
