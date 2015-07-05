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

    class CorpusInfoPropertyChangeCommand final : QUndoCommand {
        domain::Corpus *corpus;
        const corpus::CorpusInfoProperty newInfo;
        const corpus::CorpusInfoProperty previousInfo;
    public:
        CorpusInfoPropertyChangeCommand(
                domain::Corpus *corpus,
                const corpus::CorpusInfoProperty &corpusInfoProperty)
                : corpus(corpus), newInfo(corpusInfoProperty), previousInfo(corpus->value().infoProperty()) { }
        void undo() override;
        void redo() override;
        bool mergeWith(const QUndoCommand *) override { return false; }
    };

}
}


#endif //VSAMPLER_CORPUSMETAINFOCHANGECMMAND_H
