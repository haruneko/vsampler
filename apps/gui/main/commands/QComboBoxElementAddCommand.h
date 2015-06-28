/**
 * Created by Hal@shurabaP on 2015/06/28.
 * This code is under The BSD 3-Clause License.
 * See more Licence.txt.
 * Copyright (c) 2015 Hal@shurabaP. All rights reserved.
 */
#ifndef VSAMPLER_QCOMBOBOXELEMENTADDCOMMAND_H
#define VSAMPLER_QCOMBOBOXELEMENTADDCOMMAND_H

#include <QUndoCommand>

class QComboBox;

namespace vsampler {
namespace gui {

    class QComboBoxElementAddCommand final : public QUndoCommand {
        QComboBox *target;
        const QString elementName;
    public:
        QComboBoxElementAddCommand(QComboBox *target, const QString &elementName);
        void undo() override;
        void redo() override;
        bool mergeWith(const QUndoCommand *) override { return false; }
    };

}
}



#endif //VSAMPLER_QCOMBOBOXELEMENTADDCOMMAND_H
