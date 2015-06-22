/**
 * Created by Hal@shurabaP on 2015/06/22.
 * This code is under The BSD 3-Clause License.
 * See more Licence.txt.
 * Copyright (c) 2015 Hal@shurabaP. All rights reserved.
 */
#ifndef VSAMPLER_CORPUSEDITOR_H
#define VSAMPLER_CORPUSEDITOR_H

#include <QUndoStack>
#include <QWidget>

#include "entity/Corpus.h"

namespace vsampler {
namespace corpus_editor {

    class CorpusEditor final {
        domain::Corpus *corpus;
        QUndoStack *undoStack;
        QWidget *widget;

    public:
        CorpusEditor();
        ~CorpusEditor();

        QWidget *mainWidget();
    };

}
}


#endif //VSAMPLER_CORPUSEDITOR_H
