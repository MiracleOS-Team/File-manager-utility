
#include "shortcut.h"
#include "keyboardsearchmanager.h"

#include <QKeyEvent>

ShortCut::ShortCut(QObject *parent)
    : QObject(parent)
    , m_object(parent)
{
}

void ShortCut::install(QObject *target)
{
    // No need to remove, because memory space is automatically freed in qml.
    // if (m_object) {
    //     m_object->removeEventFilter(this);
    // }

    if (target) {
        target->installEventFilter(this);
        // m_object = target;
    }
}

bool ShortCut::eventFilter(QObject *obj, QEvent *e)
{
    if (e->type() == QEvent::KeyPress) {
        QKeyEvent *keyEvent = static_cast<QKeyEvent *>(e);
        // int keyInt = keyEvent->modifiers() + keyEvent->key();

        if (keyEvent->key() == Qt::Key_Enter || keyEvent->key() == Qt::Key_Return) {
            emit open();
        } else if (keyEvent->key() == Qt::Key_C && keyEvent->modifiers() & Qt::ControlModifier) {
            emit copy();
        } else if (keyEvent->key() == Qt::Key_X && keyEvent->modifiers() & Qt::ControlModifier) {
            emit cut();
        } else if (keyEvent->key() == Qt::Key_W && keyEvent->modifiers() & Qt::ControlModifier) {
            emit close();
        } else if (keyEvent->key() == Qt::Key_V && keyEvent->modifiers() & Qt::ControlModifier) {
            emit paste();
        } else if (keyEvent->key() == Qt::Key_F2) {
            emit rename();
        } else if (keyEvent->key() == Qt::Key_L && keyEvent->modifiers() & Qt::ControlModifier) {
            emit openPathEditor();
        } else if (keyEvent->key() == Qt::Key_A && keyEvent->modifiers() & Qt::ControlModifier) {
            emit selectAll();
        } else if (keyEvent->key() == Qt::Key_Backspace) {
            emit backspace();
        } else if (keyEvent->key() == Qt::Key_Delete) {
            emit deleteFile();
        } else if (keyEvent->key() == Qt::Key_F5) {
            emit refresh();
        } else if (keyEvent->key() == Qt::Key_H && keyEvent->modifiers() & Qt::ControlModifier) {
            emit showHidden();
        } else if (keyEvent->key() == Qt::Key_Z && keyEvent->modifiers() & Qt::ControlModifier) {
            emit undo();
        } else if (keyEvent->key() >= Qt::Key_A && keyEvent->key() <= Qt::Key_Z) {
            // Handle select
            // KeyboardSearchManager::self()->addKeys(keyEvent->text());
            emit keyPressed(keyEvent->text());
            keyEvent->ignore();
        }
    }

    return QObject::eventFilter(obj, e);
}
