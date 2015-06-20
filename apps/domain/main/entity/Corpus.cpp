/**
 * Created by Hal@shurabaP on 2015/06/07.
 * This code is under The BSD 3-Clause License.
 * See more Licence.txt.
 * Copyright (c) 2015 Hal@shurabaP. All rights reserved.
 */
#include "value/json/CorpusPropertyJson.h"
#include "repsoitory/impl/JsonFileCorpusRepository.h"

#include "Corpus.h"

const QSharedPointer<vsampler::domain::CorpusRepository> vsampler::domain::DefaultCorpusRepository =
        QSharedPointer<vsampler::domain::CorpusRepository>(new vsampler::domain::impl::JsonFileCorpusRepository);
