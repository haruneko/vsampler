/**
 * Created by Hal@shurabaP on 2015/06/28.
 * This code is under The BSD 3-Clause License.
 * See more Licence.txt.
 * Copyright (c) 2015 Hal@shurabaP. All rights reserved.
 */
#include <QTextEdit>

#include "QTextEditCommand.h"

vsampler::gui::QTextEditCommand::QTextEditCommand(QTextEdit *target, const QString after, QUndoCommand *parent)
        : target(target), after(after), before(target->toPlainText()), QUndoCommand(parent) {
}

void vsampler::gui::QTextEditCommand::undo() {
    target->setText(before);
}

void vsampler::gui::QTextEditCommand::redo() {
    target->setText(after);
}
