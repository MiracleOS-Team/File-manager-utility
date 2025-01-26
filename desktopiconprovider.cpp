
#include "desktopiconprovider.h"
#include <QIcon>

DesktopIconProvider::DesktopIconProvider()
    : QQuickImageProvider(QQuickImageProvider::Pixmap)
{

}

QPixmap DesktopIconProvider::requestPixmap(const QString &id, QSize *realSize,
                                           const QSize &requestedSize)
{
    QSize size(requestedSize);
    if (size.width() < 1)
        size.setWidth(1);
    if (size.height() < 1)
        size.setHeight(1);

    if (realSize)
        *realSize = size;

    if (id.startsWith(QLatin1Char('/')))
        return QPixmap(id).scaled(size);

    QIcon icon = QIcon::fromTheme(id);
    if (icon.isNull())
        icon = QIcon::fromTheme(QLatin1String("application-x-desktop"));

    return icon.pixmap(size);
}
