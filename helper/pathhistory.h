

#ifndef PATHHISTORY_H
#define PATHHISTORY_H

#include <QObject>
#include <QVector>

class PathHistory : public QObject
{
    Q_OBJECT

public:
    explicit PathHistory(QObject *parent = nullptr);

    void append(const QUrl &path);

    QUrl first();
    QUrl last();

    QUrl at(int i);
    int count();

    bool isEmpty();

    QUrl posteriorPath();
    QUrl previousPath();

private:
    QVector<QUrl> m_prevHistory;
    QVector<QUrl> m_postHistory;
};

#endif // PATHHISTORY_H
