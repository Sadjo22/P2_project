#ifndef MAINWINDOWLOGIN_H
#define MAINWINDOWLOGIN_H

#include <QGroupBox>
#include<QVBoxLayout>
#include<QHBoxLayout>
#include <QMainWindow>
#include <QWidget>
#include <QSize>
#include <QLineEdit>

class MainWindow;
class Login;


class MainWindowLogin : public QWidget
{
    Q_OBJECT

public:
    explicit MainWindowLogin(QWidget *parent = 0);
    ~MainWindowLogin();
    QSize sizeHint()const override;

private:
   QLineEdit* line1,*line2;
   MainWindow* wind;
   Login* log;

public slots:
   void Connected();

};


#endif // MAINWINDOWLOGIN_H
