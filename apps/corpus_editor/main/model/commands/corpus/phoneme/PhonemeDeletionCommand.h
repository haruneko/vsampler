/**
 * Created by Hal@shurabaP on 2015/06/22.
 * This code is under The BSD 3-Clause License.
 * See more Licence.txt.
 * Copyright (c) 2015 Hal@shurabaP. All rights reserved.
 */
#ifndef VSAMPLER_PHONEMEDELETIONCOMMAND_H
#define VSAMPLER_PHONEMEDELETIONCOMMAND_H

#include <QUndoCommand>

#include "entity/Corpus.h"

namespace vsampler {
    namespace corpus_editor {

        class PhonemeDeletionCommand final : public QUndoCommand {
            domain::Corpus *corpus;
            const corpus::Pronounce pronounce;
            const corpus::PhonemeInfoProperty phonemeMetaInfo;
        public:
            PhonemeDeletionCommand(
                    domain::Corpus *corpus,
                    const corpus::Pronounce &pronounce,
                    const corpus::PhonemeInfoProperty &phonemeMetaInfo)
                    : corpus(corpus), pronounce(pronounce), phonemeMetaInfo(phonemeMetaInfo) { }
            void undo() override;
            void redo() override;
            bool mergeWith(const QUndoCommand *) override { return false; }
        };

    }
}

#endif //VSAMPLER_PHONEMEDELETIONCOMMAND_H
