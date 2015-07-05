/**
 * Created by Hal@shurabaP on 2015/06/22.
 * This code is under The BSD 3-Clause License.
 * See more Licence.txt.
 * Copyright (c) 2015 Hal@shurabaP. All rights reserved.
 */
#ifndef VSAMPLER_PHONEMEINSERTIONCOMMAND_H
#define VSAMPLER_PHONEMEINSERTIONCOMMAND_H

#include <QUndoCommand>

#include "entity/Corpus.h"

namespace vsampler {
namespace corpus_editor {

    class PhonemeInsertionCommand final : public QUndoCommand {
        domain::Corpus *corpus;
        const corpus::Pronounce pronounce;
        const corpus::PhonemeInfoProperty phonemeMetaInfo;
    public:
        PhonemeInsertionCommand(
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


#endif //VSAMPLER_PHONEMEINSERTIONCOMMAND_H
