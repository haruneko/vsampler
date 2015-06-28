/**
 * Created by Hal@shurabaP on 2015/06/27.
 * This code is under The BSD 3-Clause License.
 * See more Licence.txt.
 * Copyright (c) 2015 Hal@shurabaP. All rights reserved.
 */
#ifndef VSAMPLER_QLINEEDITCOMMAND_H
#define VSAMPLER_QLINEEDITCOMMAND_H

#include <QUndoCommand>

class QLineEdit;

namespace vsampler {
namespace gui {
    class QLineEditCommand final : public QUndoCommand {
        QLineEdit *target;
        const QString after;
        const QString before;
    public:
        QLineEditCommand(QLineEdit *target, const QString &after, QUndoCommand *parent = 0);
        void undo() override;
        void redo() override;
        bool mergeWith(const QUndoCommand *) override { return false; }
    };
}
}


#endif //VSAMPLER_QLINEEDITCOMMAND_H
