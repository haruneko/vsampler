/**
 * Created by Hal@shurabaP on 2015/07/07.
 * This code is under The BSD 3-Clause License.
 * See more Licence.txt.
 * Copyright (c) 2015 Hal@shurabaP. All rights reserved.
 */
#ifndef VSAMPLER_CORPUSINFOTRANSLATABLECHANGECOMMAND_H
#define VSAMPLER_CORPUSINFOTRANSLATABLECHANGECOMMAND_H

#include "entity/Corpus.h"
#include <QUndoCommand>

namespace vsampler {
namespace corpus_editor {

    class CorpusInfoTranslatableChangeCommand final : public QUndoCommand {
        domain::Corpus &corpus;
        const corpus::Language language;
        const QString before;
        const QString after;
        void (domain::EditsCorpusInfo::*func)(const corpus::Language&, const QString &);
    public:
        CorpusInfoTranslatableChangeCommand(
                domain::Corpus &corpus,
                const corpus::Language &language,
                const QString &before,
                const QString &after,
                void (domain::EditsCorpusInfo::*func)(const corpus::Language&, const QString &),
                QUndoCommand *parent = 0);
        void redo();
        void undo();
    };
}
}


#endif //VSAMPLER_CORPUSINFOTRANSLATABLECHANGECOMMAND_H
