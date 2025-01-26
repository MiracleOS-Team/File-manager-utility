

#ifndef DESKTOPVIEW_H
#define DESKTOPVIEW_H

#include <QQuickView>
#include <QScreen>

class Desktop;
class DesktopView : public QQuickView
{
    Q_OBJECT
    Q_PROPERTY(QRect screenRect READ screenRect NOTIFY screenRectChanged)

public:
    explicit DesktopView(QScreen *screen = nullptr, QQuickView *parent = nullptr);

    QRect screenRect();

signals:
    void screenRectChanged();

private slots:
    void onPrimaryScreenChanged(QScreen *screen);
    void onGeometryChanged();

private:
    QScreen *m_screen;
    QRect m_screenRect;
};

#endif // DESKTOPVIEW_H
