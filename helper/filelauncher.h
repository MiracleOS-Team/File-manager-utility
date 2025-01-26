

#ifndef FILELAUNCHER_H
#define FILELAUNCHER_H

#include <QObject>

class FileLauncher : public QObject
{
    Q_OBJECT

public:
    static FileLauncher *self();
    explicit FileLauncher(QObject *parent = nullptr);

    Q_INVOKABLE bool launchApp(const QString &desktopFile, const QString &fileName);
    Q_INVOKABLE bool launchExecutable(const QString &fileName);

    static bool startDetached(const QString &exec, QStringList args = QStringList());
    static bool startDetached(const QString &exec, const QString &workingDir, QStringList args = QStringList());
};

#endif // FILELAUNCHER_H
