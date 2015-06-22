#include <QtGui/QGuiApplication>

#include "model/CorpusEditor.h"

int main(int argc, char **argv) {
    QGuiApplication app(argc, argv);

    vsampler::corpus_editor::CorpusEditor editor;
    editor.mainWidget()->show();

    return app.exec();
}
