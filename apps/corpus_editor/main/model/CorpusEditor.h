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

    class CorpusEditor final : public QObject {
        Q_OBJECT
    private:
        domain::Corpus *corpus;
        QUndoStack *undos;
        QWidget *widget;

    public:
        CorpusEditor(QObject *parent = 0);
        ~CorpusEditor();

        QWidget *mainWidget();
        QUndoStack *undoStack();
    public slots:
        void open(const QString &filePath);
        void save();
        void saveAs(const QString &filePath);
    signals:
        void onError(const vsampler::util::Exception *);
    };

}
}


#endif //VSAMPLER_CORPUSEDITOR_H
