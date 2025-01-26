

#include "openwithdialog.h"
#include "../mimetype/mimeappmanager.h"
#include "../helper/filelauncher.h"

#include <QQmlEngine>
#include <QQmlContext>

OpenWithDialog::OpenWithDialog(const QUrl &url, QQuickView *parent)
    : QQuickView(parent)
    , m_url(url.toLocalFile())
{
    setFlag(Qt::Dialog);
    setTitle(tr("Open With"));
    setResizeMode(QQuickView::SizeViewToRootObject);

    engine()->rootContext()->setContextProperty("main", this);
    engine()->rootContext()->setContextProperty("mimeAppManager", MimeAppManager::self());
    engine()->rootContext()->setContextProperty("launcher", FileLauncher::self());

    setSource(QUrl("qrc:/qml/Dialogs/OpenWithDialog.qml"));

    QRect rect = geometry();
    setMinimumSize(rect.size());
    setMaximumSize(rect.size());

    connect(this, &QQuickView::visibleChanged, this, [=] {
        if (!this->isVisible())
            this->deleteLater();
    });
}

QString OpenWithDialog::url() const
{
    return m_url;
}
