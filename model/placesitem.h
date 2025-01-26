

#ifndef PLACESITEM_H
#define PLACESITEM_H

#include <QObject>
#include <QPointer>
#include <QUrl>

#include <Solid/Device>
#include <Solid/StorageAccess>

class PlacesItem : public QObject
{
    Q_OBJECT

public:
    explicit PlacesItem(const QString &displayName = QString(),
                        QUrl url = QUrl(),
                        QObject *parent = nullptr);

    QString displayName() const;
    void setDisplayName(const QString &name);

    QString iconName() const;
    void setIconName(const QString &name);

    QString iconPath() const;
    void setIconPath(const QString &path);

    QUrl url() const;
    void setUrl(const QUrl &url);

    QString path() const;

    QString udi() const;
    void setUdi(const QString &udi);

    bool isDevice();
    bool setupNeeded();

    QString category() const;
    void setCategory(const QString &category);

    bool isOpticalDisc() const;

signals:
    void itemChanged(PlacesItem *);

private slots:
    void updateDeviceInfo(const QString &udi);
    void onAccessibilityChanged(bool isAccessible);

private:
    QString m_displayName;
    QString m_iconName;
    QString m_iconPath;
    QString m_udi;
    QUrl m_url;
    QString m_category;

    bool m_isOpticalDisc;
    bool m_isAccessible;

    Solid::Device m_device;
    QPointer<Solid::StorageAccess> m_access;
};

#endif // PLACESITEM_H
