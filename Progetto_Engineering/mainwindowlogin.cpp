#include "MainWindowLogin.h"
#include "MainWindow.h"
#include "login.h"

#include<QGroupBox>
#include<QGridLayout>
#include<QLabel>
#include<QLineEdit>
#include<QPushButton>
#include<QApplication>
#include<QMessageBox>
#include<QPalette>
#include<QPixmap>
#include<QHBoxLayout>
#include<QIcon>

MainWindowLogin::MainWindowLogin(QWidget *parent) :
    QWidget(parent)
{
    setWindowTitle("Administrator Login");
    setWindowIcon(QIcon(":/pics/DATA/tbbtlogo.png"));
    QPalette pal = palette();
    pal.setColor(QPalette::Background,Qt::darkCyan);
    setPalette(pal);

     /*QLabel* lab3 = new QLabel();
     lab3->setPixmap(QPixmap(":/pics/DATA/tbbtlogo.png"));*/

    QVBoxLayout* vb = new QVBoxLayout();
    QGroupBox* gb = new QGroupBox("Sign In",this);
    QGridLayout* gl= new QGridLayout();
    QLabel* lab1 = new QLabel("Username");
    QLabel* lab2 = new QLabel("Password");
    line1 = new QLineEdit();
    line2 = new QLineEdit();
    QPushButton* pb = new QPushButton("Login");
       gl->addWidget(lab1,0,0,Qt::AlignLeft);
       gl->addWidget(line1,0,1,Qt::AlignRight);
       gl->addWidget(lab2,1,0,Qt::AlignLeft);
       gl->addWidget(line2,1,1,Qt::AlignRight);
       gl->addWidget(pb,2,1,Qt::AlignRight);
       gb->setLayout(gl);
       vb->addWidget(gb);
       gb->setGeometry(100,100,200,200);


   connect(pb,SIGNAL(clicked()),this,SLOT(Connected()));

}

MainWindowLogin::~MainWindowLogin(){}

QSize MainWindowLogin::sizeHint()const{
    return QSize(400,400);
 }


void MainWindowLogin::Connected(){
    if(log->Connection(line1->text().toStdString(),line2->text().toStdString())){

        QMessageBox box(QMessageBox::Information, "Success","Welcome to The Administration Page", QMessageBox::Ok);
        box.exec();
        hide();
         wind= new MainWindow();
         wind->show();

    }
    else{

        QMessageBox box(QMessageBox::Warning, "Login Error","Incorrect Username o Password", QMessageBox::Ok);
        box.exec();
    }
}

