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
        QString baseDirectory;
        QString language;
    public:
        CorpusInfoEditor(domain::Corpus &corpus, CorpusInfoEditorController *controller, QObject *parent = 0);
        void setController(CorpusInfoEditorController *controller);
    public slots:
        // Entity change
        void onNameChanged(const QString name);
        void onVersionChanged(const QString version);
        void onIconPathChanged(const QString iconPath);
        void onSamplePathChanged(const QString samplePath);
        void onAuthorChanged(const QString author);
        void onWebChanged(const QString web);
        void onLicenseChanged(const QString license);
        void onDescriptionChanged(const QString description);

        void onLanguageAdded(const QString language);
        void onLanguageRemoved(const QString language);

        // State change on view model
        void onLanguageSelected();
        void onBaseDirectoryChanged();

    signals:
        void notifyChange(QUndoCommand *command);
    };
}
}

#endif //VSAMPLER_CORPUSINFOEDITOR_H
