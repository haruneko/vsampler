/**
 * Created by Hal@shurabaP on 2015/06/27.
 * This code is under The BSD 3-Clause License.
 * See more Licence.txt.
 * Copyright (c) 2015 Hal@shurabaP. All rights reserved.
 */
#include <QLineEdit>

#include "QLineEditCommand.h"

vsampler::gui::QLineEditCommand::QLineEditCommand(QLineEdit *target, const QString &after, QUndoCommand *parent)
        : target(target), after(after), before(target->text()), QUndoCommand(parent) {
}

void vsampler::gui::QLineEditCommand::undo() {
    target->setText(before);
}

void vsampler::gui::QLineEditCommand::redo() {
    target->setText(after);
}