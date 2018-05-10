#ifndef WIDGET_HPP
#define WIDGET_HPP

#include <QWidget>

namespace Ui
{
    class Widget;
}

class QUdpSocket;

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_btnSend_clicked();

private:
    Ui::Widget *ui;
    QUdpSocket *mSocket;
};

#endif // WIDGET_HPP
