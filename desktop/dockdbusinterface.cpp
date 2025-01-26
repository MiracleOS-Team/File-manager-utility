
#include "dockdbusinterface.h"
#include <QDBusServiceWatcher>
#include <QRect>

static DockDBusInterface *DOCKDBUS_SELF = nullptr;

DockDBusInterface *DockDBusInterface::self()
{
    if (!DOCKDBUS_SELF)
        DOCKDBUS_SELF = new DockDBusInterface;

    return DOCKDBUS_SELF;
}

DockDBusInterface::DockDBusInterface(QObject *parent)
    : QObject(parent)
    , m_dockInterface("com.cutefish.Dock",
                    "/Dock",
                    "com.cutefish.Dock", QDBusConnection::sessionBus())
    , m_leftMargin(0)
    , m_rightMargin(0)
    , m_bottomMargin(0)
{
    if (m_dockInterface.isValid()) {
        updateMargins();
        connect(&m_dockInterface, SIGNAL(primaryGeometryChanged()), this, SLOT(updateMargins()));
        connect(&m_dockInterface, SIGNAL(directionChanged()), this, SLOT(updateMargins()));
        connect(&m_dockInterface, SIGNAL(visibilityChanged()), this, SLOT(updateMargins()));
    } else {
        QDBusServiceWatcher *watcher = new QDBusServiceWatcher("com.cutefish.Dock",
                                                               QDBusConnection::sessionBus(),
                                                               QDBusServiceWatcher::WatchForUnregistration,
                                                               this);
        connect(watcher, &QDBusServiceWatcher::serviceUnregistered, this, [=] {
            updateMargins();
            connect(&m_dockInterface, SIGNAL(primaryGeometryChanged()), this, SLOT(updateMargins()));
            connect(&m_dockInterface, SIGNAL(directionChanged()), this, SLOT(updateMargins()));
            connect(&m_dockInterface, SIGNAL(visibilityChanged()), this, SLOT(updateMargins()));
        });
    }
}

int DockDBusInterface::leftMargin() const
{
    return m_leftMargin;
}

int DockDBusInterface::rightMargin() const
{
    return m_rightMargin;
}

int DockDBusInterface::bottomMargin() const
{
    return m_bottomMargin;
}

void DockDBusInterface::updateMargins()
{
    QRect dockGeometry = m_dockInterface.property("primaryGeometry").toRect();
    int dockDirection = m_dockInterface.property("direction").toInt();
    int visibility = m_dockInterface.property("visibility").toInt();

    m_leftMargin = 0;
    m_rightMargin = 0;
    m_bottomMargin = 0;

    // AlwaysHide
    if (visibility == 1) {
        emit marginsChanged();
        return;
    }

    if (dockDirection == 0) {
        m_leftMargin = dockGeometry.width();
    } else if (dockDirection == 1) {
        m_bottomMargin = dockGeometry.height();
    } else if (dockDirection == 2) {
        m_rightMargin = dockGeometry.width();
    }

    emit marginsChanged();
}
