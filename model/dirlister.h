

#ifndef DIRLISTER_H
#define DIRLISTER_H

#include <KDirLister>
#include <KIO/Job>

class DirLister : public KDirLister
{
    Q_OBJECT

public:
    explicit DirLister(QObject *parent = nullptr);
    ~DirLister() override;

Q_SIGNALS:
    void error(const QString &string);

protected:
    void handleError(KIO::Job *job) override;
};

#endif // DIRLISTER_H
