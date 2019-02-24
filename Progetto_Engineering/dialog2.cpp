#include "dialog2.h"
#include<QLabel>
#include<QLayout>
#include<QVBoxLayout>
#include<QRect>
#include<QMenuBar>
#include<QFont>
#include<QListWidget>

Dialog2::Dialog2(QWidget* parent,const Engineering* ptr):QDialog(parent),eng(ptr){


     setWindowTitle(tr("Faculty Information"));
     setWindowIcon(QIcon(":/imag/images/info.jpg"));


         QListWidget* wid= new QListWidget();
         wid->addItem(QString::fromStdString("Head of dipartment Name: ")+QString::fromStdString(" ") +QString::fromStdString(eng->getResponsibleName()));
         wid->addItem(QString::fromStdString("Faculty Location: ")+QString::fromStdString(" ") + QString::fromStdString(eng->getLocation()));
         wid->addItem(QString::fromStdString(eng->Educational_Pathway()));
         wid->addItem(QString::fromStdString(eng->Academic_Employment_Opportunities()));
         wid->addItem(QString::fromStdString(eng->Professional_Employment_Opportunities()));


     QVBoxLayout* lay=new QVBoxLayout(this);
     for(int i=0; i<4;i++)
       lay->addWidget(wid);

}


void Dialog2::accept(){
   close();
}
