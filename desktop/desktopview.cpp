
#include "desktopview.h"
#include "dockdbusinterface.h"
#include "thumbnailer/thumbnailprovider.h"

#include <QQmlEngine>
#include <QQmlContext>

#include <QDebug>
#include <QGuiApplication>
#include <QScreen>

#include <KWindowSystem>

DesktopView::DesktopView(QScreen *screen, QQuickView *parent)
    : QQuickView(parent)
    , m_screen(screen)
{
    m_screenRect = m_screen->geometry();
    this->setFlag(Qt::FramelessWindowHint);
    this->setColor(QColor(Qt::transparent));
    KWindowSystem::setType(winId(), NET::Desktop);
    KWindowSystem::setState(winId(), NET::KeepBelow);

    engine()->rootContext()->setContextProperty("desktopView", this);
    engine()->rootContext()->setContextProperty("Dock", DockDBusInterface::self());
    QWindow::fromWinId(winId())->setOpacity(0.99);
    engine()->addImageProvider("thumbnailer", new ThumbnailProvider());

    setTitle(tr("Desktop"));
    setScreen(m_screen);
    setResizeMode(QQuickView::SizeRootObjectToView);

    onGeometryChanged();
    onPrimaryScreenChanged(QGuiApplication::primaryScreen());

    // 主屏改变
    connect(qGuiApp, &QGuiApplication::primaryScreenChanged, this, &DesktopView::onPrimaryScreenChanged);

    connect(m_screen, &QScreen::virtualGeometryChanged, this, &DesktopView::onGeometryChanged);
    connect(m_screen, &QScreen::geometryChanged, this, &DesktopView::onGeometryChanged);
}

QRect DesktopView::screenRect()
{
    return m_screenRect;
}

void DesktopView::onPrimaryScreenChanged(QScreen *screen)
{
    bool isPrimaryScreen = m_screen->name() == screen->name();

    onGeometryChanged();

    setSource(isPrimaryScreen ? QStringLiteral("qrc:/qml/Desktop/Main.qml")
                              : QStringLiteral("qrc:/qml/Desktop/Wallpaper.qml"));
}

void DesktopView::onGeometryChanged()
{
    m_screenRect = m_screen->geometry().adjusted(0, 0, 1, 1);
    setGeometry(m_screenRect);
    emit screenRectChanged();
}
