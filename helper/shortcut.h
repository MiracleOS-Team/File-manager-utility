

#ifndef SHORTCUT_H
#define SHORTCUT_H

#include <QObject>

class ShortCut : public QObject
{
    Q_OBJECT

public:
    explicit ShortCut(QObject *parent = nullptr);

    Q_INVOKABLE void install(QObject *target = nullptr);

signals:
    void open();
    void copy();
    void cut();
    void paste();
    void rename();
    void refresh();
    void openPathEditor();
    void selectAll();
    void backspace();
    void deleteFile();
    void showHidden();
    void keyPressed(const QString &text);
    void close();
    void undo();

protected:
    bool eventFilter(QObject *obj, QEvent *e) override;

private:
    QObject *m_object;
};

#endif // SHORTCUT_H
