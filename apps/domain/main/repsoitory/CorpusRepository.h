/**
 * Created by Hal@shurabaP on 2015/06/07.
 * This code is under The BSD 3-Clause License.
 * See more Licence.txt.
 * Copyright (c) 2015 Hal@shurabaP. All rights reserved.
 */
#ifndef VSAMPLER_CORPUSREPOSITORY_H
#define VSAMPLER_CORPUSREPOSITORY_H

#include "entity/Corpus.h"
#include "util/Try.h"

namespace vsampler{
namespace domain {
    class CorpusRepository {
    public:
        virtual ~CorpusRepository() { }
        virtual util::Try<Corpus> fetchBy(const CorpusId &id) = 0;
        virtual util::Try<util::Unit> upsert(const Corpus &corpus) = 0;
    };
}
}

#endif //VSAMPLER_CORPUSREPOSITORY_H
