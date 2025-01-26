

#ifndef DOCKDBUSINTERFACE_H
#define DOCKDBUSINTERFACE_H

#include <QObject>
#include <QDBusInterface>

class DockDBusInterface : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int leftMargin READ leftMargin NOTIFY marginsChanged)
    Q_PROPERTY(int rightMargin READ rightMargin NOTIFY marginsChanged)
    Q_PROPERTY(int bottomMargin READ bottomMargin NOTIFY marginsChanged)

public:
    static DockDBusInterface *self();
    explicit DockDBusInterface(QObject *parent = nullptr);

    int leftMargin() const;
    int rightMargin() const;
    int bottomMargin() const;

signals:
    void marginsChanged();

private slots:
    void updateMargins();

private:
    QDBusInterface m_dockInterface;

    int m_leftMargin;
    int m_rightMargin;
    int m_bottomMargin;
};

#endif // DOCKDBUSINTERFACE_H
