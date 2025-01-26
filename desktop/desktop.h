

#ifndef DESKTOP_H
#define DESKTOP_H

#include <QObject>
#include <QScreen>
#include <QDBusInterface>

#include "desktopview.h"

class Desktop : public QObject
{
    Q_OBJECT

public:
    explicit Desktop(QObject *parent = nullptr);

private slots:
    void screenAdded(QScreen *qscreen);
    void screenRemoved(QScreen *qscreen);

private:
    QMap<QScreen *, DesktopView *> m_list;
};

#endif // DESKTOP_H
