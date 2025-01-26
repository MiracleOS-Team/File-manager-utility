

#include "window.h"
#include <QEvent>
#include <QDebug>
#include <QQuickWindow>
#include <QPixmapCache>

Window::Window(QObject *parent)
    : QQmlApplicationEngine(parent)
{
}

void Window::load(const QUrl &url)
{
    QQmlApplicationEngine::load(url);

    QQuickWindow *w = qobject_cast<QQuickWindow *>(rootObjects().first());

    if (w)
        w->installEventFilter(this);
}

bool Window::eventFilter(QObject *obj, QEvent *e)
{
    if (e->type() == QEvent::Close) {
        QPixmapCache::clear();
        clearComponentCache();
        deleteLater();
        e->accept();
    }

    return QObject::eventFilter(obj, e);
}
