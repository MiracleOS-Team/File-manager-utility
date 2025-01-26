
#ifndef OPENWITHDIALOG_H
#define OPENWITHDIALOG_H

#include <QQuickView>

class OpenWithDialog : public QQuickView
{
    Q_OBJECT
    Q_PROPERTY(QString url READ url CONSTANT)

public:
    explicit OpenWithDialog(const QUrl &url, QQuickView *parent = nullptr);

    QString url() const;

private:
    QString m_url;
};

#endif // OPENWITHDIALOG_H
