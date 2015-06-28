/**
 * Created by Hal@shurabaP on 2015/06/28.
 * This code is under The BSD 3-Clause License.
 * See more Licence.txt.
 * Copyright (c) 2015 Hal@shurabaP. All rights reserved.
 */
#ifndef VSAMPLER_QCOMBOBOXSELECTCHANGECOMMAND_H
#define VSAMPLER_QCOMBOBOXSELECTCHANGECOMMAND_H

#include <QUndoCommand>

class QComboBox;

namespace vsampler {
namespace gui {

    class QComboBoxSelectChangeCommand final : public QUndoCommand {
        QComboBox *target;
        const QString after;
        const QString before;
    public:
        QComboBoxSelectChangeCommand(QComboBox *target, const QString &after, QUndoCommand *parent);
        void undo() override;
        void redo() override;
        bool mergeWith(const QUndoCommand *) override { return false; }
    };

}
}


#endif //VSAMPLER_QCOMBOBOXSELECTCHANGECOMMAND_H
