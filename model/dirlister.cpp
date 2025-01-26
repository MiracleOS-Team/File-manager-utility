

#include "dirlister.h"

DirLister::DirLister(QObject *parent)
    : KDirLister(parent)
{
}

DirLister::~DirLister()
{
}

void DirLister::handleError(KIO::Job *job)
{
    if (!autoErrorHandlingEnabled()) {
        emit error(job->errorString());
        return;
    }

    KDirLister::handleError(job);
}
