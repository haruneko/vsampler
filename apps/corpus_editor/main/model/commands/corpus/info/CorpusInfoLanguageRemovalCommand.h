/**
 * Created by Hal@shurabaP on 2015/07/07.
 * This code is under The BSD 3-Clause License.
 * See more Licence.txt.
 * Copyright (c) 2015 Hal@shurabaP. All rights reserved.
 */
#ifndef VSAMPLER_CORPUSINFOLANGUAGEREMOVALCOMMAND_H
#define VSAMPLER_CORPUSINFOLANGUAGEREMOVALCOMMAND_H

#include "entity/Corpus.h"
#include <QUndoCommand>

namespace vsampler {
namespace corpus_editor {

    class CorpusInfoLanguageRemovalCommand final : public QUndoCommand {
        domain::Corpus &corpus;
        const corpus::Language language;
        const domain::EditsCorpusInfo::Translatable translatable;
    public:
        CorpusInfoLanguageRemovalCommand(domain::Corpus &corpus, const QString &languageString, QUndoCommand *parent = 0);
        void redo();
        void undo();
    };
}
}


#endif //VSAMPLER_CORPUSINFOLANGUAGEREMOVALCOMMAND_H
