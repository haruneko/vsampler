/**
 * Created by Hal@shurabaP on 2015/07/07.
 * This code is under The BSD 3-Clause License.
 * See more Licence.txt.
 * Copyright (c) 2015 Hal@shurabaP. All rights reserved.
 */
#ifndef VSAMPLER_CORPUSINFOSTRINGCHANGECOMMAND_H
#define VSAMPLER_CORPUSINFOSTRINGCHANGECOMMAND_H

#include "entity/Corpus.h"
#include <QUndoCommand>

namespace vsampler {
namespace corpus_editor {

    class CorpusInfoStringChangeCommand final : public QUndoCommand {
        domain::Corpus &corpus;
        const QString before;
        const QString after;
        void (domain::EditsCorpusInfo::*func)(const QString &);
    public:
        CorpusInfoStringChangeCommand(
                domain::Corpus &corpus,
        const QString &before,
        const QString &after,
        void (domain::EditsCorpusInfo::*func)(const QString &),
                QUndoCommand *parent = 0);
        void redo();
        void undo();
    };

}
}

#endif //VSAMPLER_CORPUSINFOSTRINGCHANGECOMMAND_H
