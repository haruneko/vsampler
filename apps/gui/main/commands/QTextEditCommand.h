/**
 * Created by Hal@shurabaP on 2015/06/28.
 * This code is under The BSD 3-Clause License.
 * See more Licence.txt.
 * Copyright (c) 2015 Hal@shurabaP. All rights reserved.
 */
#ifndef VSAMPLER_QTEXTEDITCOMMAND_H
#define VSAMPLER_QTEXTEDITCOMMAND_H

#include <QUndoCommand>

class QTextEdit;

namespace vsampler {
namespace gui {

    class QTextEditCommand final : public QUndoCommand {
        QTextEdit *target;
        const QString after;
        const QString before;
    public:
        QTextEditCommand(QTextEdit *target, const QString after, QUndoCommand * parent = 0);
        void undo() override;
        void redo() override;
        bool mergeWith(const QUndoCommand *) { return false; }
    };

}
}


#endif //VSAMPLER_QTEXTEDITCOMMAND_H
