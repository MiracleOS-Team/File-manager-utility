
#include "pathhistory.h"
#include <QUrl>

PathHistory::PathHistory(QObject *parent)
    : QObject(parent)
{

}

void PathHistory::append(const QUrl &path)
{
    m_prevHistory.append(path);
}

QUrl PathHistory::first()
{
    return m_prevHistory.first();
}

QUrl PathHistory::last()
{
    return m_prevHistory.last();
}

QUrl PathHistory::at(int i)
{
    return m_prevHistory.at(i);
}

int PathHistory::count()
{
    return m_prevHistory.count();
}

bool PathHistory::isEmpty()
{
    return m_prevHistory.isEmpty();
}

QUrl PathHistory::posteriorPath()
{
    if (m_postHistory.isEmpty())
        return QUrl();

    return m_postHistory.takeLast();
}

QUrl PathHistory::previousPath()
{
    if (m_prevHistory.isEmpty())
        return QUrl();

    if (m_prevHistory.length() < 2)
        return m_prevHistory.at(0);

    m_postHistory.append(m_prevHistory.takeLast());
    return m_prevHistory.takeLast();
}

