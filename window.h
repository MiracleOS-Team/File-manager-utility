
#ifndef WINDOW_H
#define WINDOW_H

#include <QQmlApplicationEngine>

class Window : public QQmlApplicationEngine
{
    Q_OBJECT

public:
    explicit Window(QObject *parent = nullptr);

    void load(const QUrl &url);

protected:
    bool eventFilter(QObject *o, QEvent *e);
};

#endif // WINDOW_H
