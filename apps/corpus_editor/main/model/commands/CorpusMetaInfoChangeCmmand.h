/**
 * Created by Hal@shurabaP on 2015/06/22.
 * This code is under The BSD 3-Clause License.
 * See more Licence.txt.
 * Copyright (c) 2015 Hal@shurabaP. All rights reserved.
 */
#ifndef VSAMPLER_CORPUSMETAINFOCHANGECMMAND_H
#define VSAMPLER_CORPUSMETAINFOCHANGECMMAND_H

#include <QUndoCommand>

#include "entity/Corpus.h"

namespace vsampler {
namespace corpus_editor {

    class CorpusMetaInfoChangeCommand final : QUndoCommand {
        domain::Corpus *corpus;
        const corpus::CorpusMetaInfo newInfo;
        const corpus::CorpusMetaInfo previousInfo;
    public:
        CorpusMetaInfoChangeCommand(
                domain::Corpus *corpus,
                const corpus::CorpusMetaInfo &corpusMetaInfo)
                : corpus(corpus), newInfo(corpusMetaInfo), previousInfo(corpus->value().metaInfo()) { }
        void undo() override;
        void redo() override;
        bool mergeWith(const QUndoCommand *) override { return false; }
    };

}
}


#endif //VSAMPLER_CORPUSMETAINFOCHANGECMMAND_H
