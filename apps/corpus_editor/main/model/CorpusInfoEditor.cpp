/**
 * Created by Hal@shurabaP on 2015/07/07.
 * This code is under The BSD 3-Clause License.
 * See more Licence.txt.
 * Copyright (c) 2015 Hal@shurabaP. All rights reserved.
 */
#include <model/commands/corpus/info/CorpusInfoLanguageAdditionCommand.h>
#include <model/commands/corpus/info/CorpusInfoLanguageRemovalCommand.h>
#include <model/commands/corpus/info/CorpusInfoTranslatableChangeCommand.h>
#include <model/commands/corpus/info/CorpusInfoStringChangeCommand.h>
#include "CorpusInfoEditor.h"

using namespace vsampler::corpus_editor;

vsampler::corpus_editor::CorpusInfoEditor::CorpusInfoEditor(domain::Corpus &corpus, CorpusInfoEditorController *controller, QObject *parent)
        : QObject(parent), corpus(corpus) {
    setController(controller);
}

void vsampler::corpus_editor::CorpusInfoEditor::setController(CorpusInfoEditorController *controller) {
}

void vsampler::corpus_editor::CorpusInfoEditor::onDescriptionChanged(const QString description, const QString l) {
    corpus::Language language(l);
    QString before(corpus.value().infoProperty().description().value(language, QString()));
    emit(new CorpusInfoTranslatableChangeCommand(corpus, language, before, description, &domain::Corpus::changeDescriptionAs));
}

void vsampler::corpus_editor::CorpusInfoEditor::onNameChanged(const QString name, const QString l) {
    corpus::Language language(l);
    QString before(corpus.value().infoProperty().name().value(language, QString()));
    emit(new CorpusInfoTranslatableChangeCommand(corpus, language, before, name, &domain::Corpus::changeNameAs));
}

void vsampler::corpus_editor::CorpusInfoEditor::onVersionChanged(const QString version) {
    QString before(corpus.value().infoProperty().version());
    emit(new CorpusInfoStringChangeCommand(corpus, before, version, &domain::Corpus::changeVersionAs));
}

void vsampler::corpus_editor::CorpusInfoEditor::onIconPathChanged(const QString iconPath, const QString baseDirectory) {
    QString before(corpus.value().infoProperty().iconPath().filePath());
    QString after(QDir(baseDirectory).relativeFilePath(iconPath));
    emit(new CorpusInfoStringChangeCommand(corpus, before, after, &domain::Corpus::changeIconPathAs));
}

void vsampler::corpus_editor::CorpusInfoEditor::onSamplePathChanged(const QString samplePath, const QString baseDirectory) {
    QString before(corpus.value().infoProperty().iconPath().filePath());
    QString after(QDir(baseDirectory).relativeFilePath(samplePath));
    emit(new CorpusInfoStringChangeCommand(corpus, before, after, &domain::Corpus::changeSamplePathAs));
}

void vsampler::corpus_editor::CorpusInfoEditor::onAuthorChanged(const QString author, const QString l) {
    corpus::Language language(l);
    QString before(corpus.value().infoProperty().author().value(language, QString()));
    emit(new CorpusInfoTranslatableChangeCommand(corpus, language, before, author, &domain::Corpus::changeAuthorAs));
}

void vsampler::corpus_editor::CorpusInfoEditor::onWebChanged(const QString web) {
    QString before(corpus.value().infoProperty().web().toString());
    emit(new CorpusInfoStringChangeCommand(corpus, before, web, &domain::Corpus::changeWebAs));
}

void vsampler::corpus_editor::CorpusInfoEditor::onLicenseChanged(const QString license, const QString l) {
    corpus::Language language(l);
    QString before(corpus.value().infoProperty().license().value(language, QString()));
    emit(new CorpusInfoTranslatableChangeCommand(corpus, language, before, license, &domain::Corpus::changeLicenseAs));
}

void vsampler::corpus_editor::CorpusInfoEditor::onLanguageAdded(const QString language) {
    emit(new CorpusInfoLanguageAdditionCommand(corpus, language));
}

void vsampler::corpus_editor::CorpusInfoEditor::onLanguageRemoved(const QString language) {
    emit(new CorpusInfoLanguageRemovalCommand(corpus, language));
}

void vsampler::corpus_editor::CorpusInfoEditor::onLanguageSelected() {

}

void vsampler::corpus_editor::CorpusInfoEditor::onBaseDirectoryChanged() {

}
