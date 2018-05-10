#ifndef WIDGET_HPP
#define WIDGET_HPP

#include <QWidget>

namespace Ui
{
    class Widget;
}

class QLocalSocket;

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_btnConnect_clicked();
    void on_btnQuit_clicked();

private:
    Ui::Widget *ui;
    QLocalSocket *mSocket;
};

#endif // WIDGET_HPP
