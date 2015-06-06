/**
 * Created by Hal@shurabaP on 2015/06/07.
 * This code is under The BSD 3-Clause License.
 * See more Licence.txt.
 * Copyright (c) 2015 Hal@shurabaP. All rights reserved.
 */
#ifndef VSAMPLER_CORPUS_H
#define VSAMPLER_CORPUS_H

#include <QSharedData>
#include <QSharedDataPointer>

#include "value/CorpusProperty.h"
#include "util/Entity.h"

namespace vsampler {
namespace domain {
    typedef QString CorpusId;
    typedef vsampler::Entity<CorpusId, corpus::CorpusProperty> Corpus;
}
}



#endif //VSAMPLER_CORPUS_H
