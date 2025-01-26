
#ifndef APPLICATION_H
#define APPLICATION_H

#include <QApplication>

class Application : public QApplication
{
    Q_OBJECT

public:
    explicit Application(int& argc, char** argv);

    int run();

    // DBus
    void openFiles(const QStringList &paths);
    void moveToTrash(const QStringList &paths);
    void emptyTrash();

private:
    void openWindow(const QString &path);
    QStringList formatUriList(const QStringList &list);

private:
    bool parseCommandLineArgs();

private:
    bool m_instance;
};

#endif // APPLICATION_H
