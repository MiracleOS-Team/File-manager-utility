

#include "desktop.h"
#include <QQmlContext>
#include <QQmlEngine>

#include <QGuiApplication>
#include <QDBusServiceWatcher>

Desktop::Desktop(QObject *parent)
    : QObject(parent)
{
    for (QScreen *screen : QGuiApplication::screens()) {
        screenAdded(screen);
    }

    connect(qApp, &QGuiApplication::screenAdded, this, &Desktop::screenAdded);
    connect(qApp, &QGuiApplication::screenRemoved, this, &Desktop::screenRemoved);
}

void Desktop::screenAdded(QScreen *screen)
{
    if (!m_list.contains(screen)) {
        DesktopView *view = new DesktopView(screen);
        view->show();
        m_list.insert(screen, view);
    }
}

void Desktop::screenRemoved(QScreen *screen)
{
    if (m_list.contains(screen)) {
        DesktopView *view = m_list.find(screen).value();
        view->setVisible(false);
        view->deleteLater();
        m_list.remove(screen);
    }
}
