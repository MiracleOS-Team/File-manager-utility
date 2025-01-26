
#include "fm.h"
#include <QDir>
#include <QUrl>
#include <QStandardPaths>

#include <KIO/EmptyTrashJob>

Fm::Fm(QObject *parent) : QObject(parent)
{

}

QString Fm::rootPath()
{
    return QDir::rootPath();
}

void Fm::emptyTrash()
{
    KIO::Job *job = KIO::emptyTrash();
    job->start();
}

bool Fm::isFixedFolder(const QUrl &folderUrl)
{
    const QString folder = folderUrl.toLocalFile();

    return folder == QStandardPaths::standardLocations(QStandardPaths::HomeLocation).first() ||
           folder == QStandardPaths::standardLocations(QStandardPaths::DesktopLocation).first() ||
           folder == QStandardPaths::standardLocations(QStandardPaths::MusicLocation).first() ||
           folder == QStandardPaths::standardLocations(QStandardPaths::MoviesLocation).first() ||
           folder == QStandardPaths::standardLocations(QStandardPaths::PicturesLocation).first() ||
           folder == QStandardPaths::standardLocations(QStandardPaths::DocumentsLocation).first() ||
           folder == QStandardPaths::standardLocations(QStandardPaths::DownloadLocation).first();
}
