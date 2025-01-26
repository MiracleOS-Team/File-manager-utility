

#ifndef FM_H
#define FM_H

#include <QObject>

class Fm : public QObject
{
    Q_OBJECT

public:
    explicit Fm(QObject *parent = nullptr);

    Q_INVOKABLE QString rootPath();
    Q_INVOKABLE static void emptyTrash();
    static bool isFixedFolder(const QUrl &folderUrl);
};

#endif // FM_H
