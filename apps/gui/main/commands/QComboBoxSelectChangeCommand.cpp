/**
 * Created by Hal@shurabaP on 2015/06/28.
 * This code is under The BSD 3-Clause License.
 * See more Licence.txt.
 * Copyright (c) 2015 Hal@shurabaP. All rights reserved.
 */
#include <QComboBox>

#include "QComboBoxSelectChangeCommand.h"

vsampler::gui::QComboBoxSelectChangeCommand::QComboBoxSelectChangeCommand(QComboBox *target, const QString &after, QUndoCommand *parent)
        : target(target), after(after), before(target->currentText()), QUndoCommand(parent) {
}

void vsampler::gui::QComboBoxSelectChangeCommand::undo() {
    int index = target->findText(before);
    if(index == -1) {
        return;
    }
    target->setCurrentIndex(index);
}

void vsampler::gui::QComboBoxSelectChangeCommand::redo() {
    int index = target->findText(after);
    if(index == -1) {
        return;
    }
    target->setCurrentIndex(index);
}
