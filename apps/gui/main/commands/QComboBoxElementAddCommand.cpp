/**
 * Created by Hal@shurabaP on 2015/06/28.
 * This code is under The BSD 3-Clause License.
 * See more Licence.txt.
 * Copyright (c) 2015 Hal@shurabaP. All rights reserved.
 */
#include <QComboBox>

#include "QComboBoxElementAddCommand.h"

vsampler::gui::QComboBoxElementAddCommand::QComboBoxElementAddCommand(QComboBox *target, const QString &elementName)
        : target(target), elementName(elementName) {
}

void vsampler::gui::QComboBoxElementAddCommand::undo() {
    int index = target->findText(elementName, Qt::MatchExactly);
    if(index == -1) {
        return;
    }
    target->removeItem(index);
}

void vsampler::gui::QComboBoxElementAddCommand::redo() {
    int index = target->findText(elementName, Qt::MatchExactly);
    if(index != -1) {
        return;
    }
    target->addItem(elementName);
}
