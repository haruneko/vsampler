/**
 * Created by Hal@shurabaP on 2015/07/07.
 * This code is under The BSD 3-Clause License.
 * See more Licence.txt.
 * Copyright (c) 2015 Hal@shurabaP. All rights reserved.
 */
#ifndef VSAMPLER_CORPUSINFOEDITOR_H
#define VSAMPLER_CORPUSINFOEDITOR_H

#include "controller/CorpusInfoEditorController.h"
#include "entity/Corpus.h"
#include <QObject>

class QUndoCommand;

namespace vsampler {
namespace corpus_editor {

    /**
     * View model class for the editor of CorpusInfo.
     */
    class CorpusInfoEditor : QObject {
        Q_OBJECT
        domain::Corpus &corpus;
    public:
        CorpusInfoEditor(domain::Corpus &corpus, CorpusInfoEditorController *controller, QObject *parent = 0);
        void setController(CorpusInfoEditorController *controller);
    public slots:
        // Entity change
        void onNameChanged(const QString name, const QString language);
        void onVersionChanged(const QString version);
        void onIconPathChanged(const QString iconPath, const QString baseDirectory);
        void onSamplePathChanged(const QString samplePath, const QString baseDirectory);
        void onAuthorChanged(const QString author, const QString language);
        void onWebChanged(const QString web);
        void onLicenseChanged(const QString license, const QString language);
        void onDescriptionChanged(const QString description, const QString language);

        void onLanguageAdded(const QString language);
        void onLanguageRemoved(const QString language);

    signals:
        void notifyChange(QUndoCommand *command);
    };
}
}

#endif //VSAMPLER_CORPUSINFOEDITOR_H
