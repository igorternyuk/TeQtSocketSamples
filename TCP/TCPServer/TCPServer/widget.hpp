#ifndef WIDGET_HPP
#define WIDGET_HPP

#include <QWidget>

namespace Ui
{
    class Widget;
}

class TcpServer;

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_btnSendMessage_clicked();

    void on_btnStartServer_clicked();

private:
    Ui::Widget *ui;
    TcpServer *mServer;
};

#endif // WIDGET_HPP
