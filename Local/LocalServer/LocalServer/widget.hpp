#ifndef WIDGET_HPP
#define WIDGET_HPP

#include <QWidget>

namespace Ui
{
    class Widget;
}

class LocalServer;

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_btnStartServer_clicked();
    void on_btnSendMessage_clicked();
    void on_btnQuit_clicked();

private:
    Ui::Widget *ui;
    LocalServer *mLocalServer;
};

#endif // WIDGET_HPP
