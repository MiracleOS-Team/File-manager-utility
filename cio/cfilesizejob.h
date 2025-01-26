
#ifndef CFILESIZEJOB_H
#define CFILESIZEJOB_H

#include <QThread>
#include <QList>
#include <QUrl>

class CFileSizeJob : public QThread
{
    Q_OBJECT

public:
    explicit CFileSizeJob(QObject *parent = nullptr);
    ~CFileSizeJob();

    qint64 totalSize() const;

    void start(const QList<QUrl> &urls);
    void stop();

signals:
    void sizeChanged();
    void result();

protected:
    void run() override;

private:
    bool m_running;
    QList<QUrl> m_urls;
    qint64 m_totalSize;
    int m_filesCount;
    int m_directoryCount;
};

#endif // CFILESIZEJOB_H
