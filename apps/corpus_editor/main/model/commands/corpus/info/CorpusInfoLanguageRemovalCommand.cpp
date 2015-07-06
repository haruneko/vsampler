/**
 * Created by Hal@shurabaP on 2015/07/07.
 * This code is under The BSD 3-Clause License.
 * See more Licence.txt.
 * Copyright (c) 2015 Hal@shurabaP. All rights reserved.
 */
#include "CorpusInfoLanguageRemovalCommand.h"

vsampler::corpus_editor::CorpusInfoLanguageRemovalCommand::CorpusInfoLanguageRemovalCommand(
        domain::Corpus &corpus, const QString &languageString, QUndoCommand *parent)
        : corpus(corpus), language(languageString), translatable(corpus.findTranslatableIn(language)) {
}

void vsampler::corpus_editor::CorpusInfoLanguageRemovalCommand::redo() {
    corpus.remove(language);
}

void vsampler::corpus_editor::CorpusInfoLanguageRemovalCommand::undo() {
    corpus.add(language);
    corpus.changeAuthorAs(language, translatable.author);
    corpus.changeDescriptionAs(language, translatable.description);
    corpus.changeLicenseAs(language, translatable.license);
    corpus.changeNameAs(language, translatable.name);
}