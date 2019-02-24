#include "mainwindow.h"
#include "view1.h"
#include "items_window.h"
#include "modeladapter.h"
#include "model.h"
#include "engineering.h"
#include "dialog1.h"
#include "dialog2.h"
#include <QDesktopWidget>
#include<QApplication>
#include<QHBoxLayout>
#include<QVBoxLayout>
#include<QPushButton>
#include <QMenuBar>
#include <QMenu>
#include <QFont>
#include <QAction>
#include <QGroupBox>
#include <QLabel>
#include <QMessageBox>


MainWindow::MainWindow(QWidget *parent):QWidget(parent),
    area_ricerca(new QHBoxLayout()),
    facultiesview(new View1(this)),
    adapter(new ModelAdapter(this)),
    line1(new QLineEdit(this))
{

       move(QApplication::desktop()->screen()->rect().center() - rect().center());
       setWindowTitle(tr("University Faculties"));
      setWindowIcon(QIcon(":/imag/images/logo.jpeg"));

      // upload data from file
         loadData();

      facultiesview->setModel(adapter);



       //menubar and menu composant
      QHBoxLayout* mnb=new QHBoxLayout();
      QMenuBar* menuBar= new QMenuBar(this);
      menuBar->setFont(QFont("Times",10,QFont::Black));
      QMenu *menu=new QMenu("Menu",menuBar);
      QAction *salva=new QAction("Save",menu);
      QAction *cancel=new QAction("Close",menu);
      cancel->setIcon(QIcon(":/imag/images/close.png"));
      salva->setIcon(QIcon(":/imag/images/save.png"));


      //INTRODUCE MENU IN MENUBAR
      menuBar->addMenu(menu);
      menu->addAction(salva);
      menu->addAction(cancel);
      mnb->addWidget(menuBar);
      menuBar->setFont(QFont("Times",10,QFont::Black));

      //area di ricerca
      QHBoxLayout *a_ric=new QHBoxLayout();
      //QLineEdit* line1=new QLineEdit();
      line1->setPlaceholderText("Search");
      QPushButton* pb=new QPushButton("Delete");
      pb->setIcon(QIcon(":/imag/images/delete.png"));
      pb->setFont(QFont("Times",10,QFont::DemiBold));
      area_ricerca->addWidget(line1);
      area_ricerca->addWidget(pb);
      a_ric->addLayout(area_ricerca);


      //layout
       QHBoxLayout *mainlayout= new QHBoxLayout();

       //GRIDBOX
     QVBoxLayout *cont= new QVBoxLayout();

     QGroupBox* gb=new QGroupBox();
     QGridLayout* gl= new QGridLayout();
     QLabel* lab12= new QLabel("Faculties: ");
     fac=new QComboBox();
     fac->addItem("Mechanical Engineering");
     fac->addItem("Computer Engineering");
     fac->addItem("Aeronautic");
     QLabel* lab11= new QLabel("Student Name:");
     line7= new QLineEdit();
     QLabel* lab8= new QLabel("Student Number:");
     line6=new QLineEdit();
     QLabel* lab1= new QLabel("Head Of Dipartment Name:");
     line2=new QLineEdit();
     QLabel* lab2= new QLabel("Facuty_Location: ");
     line3=new QLineEdit();
     QLabel* lab3=new QLabel("Entry_Exam: ");
     deg= new QComboBox();
     deg->addItem("1");
     QLabel* lab4= new QLabel("Bachelor_Degree: ");
     bac= new QComboBox();
     bac->addItem("Baccalaureat");
     bac->addItem("Certificate of secondary school");
     QLabel* lab5= new QLabel("Math_Exam_Score: ");
     matesam =new QComboBox();
     matesam->addItem("0");matesam->addItem("1");matesam->addItem("2");matesam->addItem("3");matesam->addItem("4");
     matesam->addItem("5");matesam->addItem("6");matesam->addItem("7");matesam->addItem("8");matesam->addItem("9");
     matesam->addItem("10");matesam->addItem("11");matesam->addItem("12");matesam->addItem("13");matesam->addItem("14");
     matesam->addItem("15");matesam->addItem("16");matesam->addItem("17");matesam->addItem("18");matesam->addItem("19");
     matesam->addItem("20");
     QLabel* lab6= new QLabel("Logic_Exam_Score: ");
     logicesam = new QComboBox();
     logicesam->addItem("0");logicesam->addItem("1");logicesam->addItem("2");logicesam->addItem("3");logicesam->addItem("4");
     logicesam->addItem("5");logicesam->addItem("6");logicesam->addItem("7");logicesam->addItem("8");logicesam->addItem("9");
     logicesam->addItem("10");logicesam->addItem("11");logicesam->addItem("12");logicesam->addItem("13");logicesam->addItem("14");
     logicesam->addItem("15");logicesam->addItem("16");logicesam->addItem("17");logicesam->addItem("18");logicesam->addItem("19");
     logicesam->addItem("20");

     QLabel* lab7= new QLabel("Engineering_Degree: ");
     laurea= new QComboBox();
     laurea->addItem("None");
     laurea->addItem("Physics");
     laurea->addItem("Maths");
     laurea->addItem("Informatics");
     laurea->addItem("Mechanical_Engineering");
     QLabel* lab9= new QLabel("Engineering_Degree_Score:");
     degreescore = new QComboBox();

    degreescore->addItem("18");degreescore->addItem("19"); degreescore->addItem("20");degreescore->addItem("21");
    degreescore->addItem("22");degreescore->addItem("23");degreescore->addItem("24"); degreescore->addItem("25");
    degreescore->addItem("26");degreescore->addItem("27");degreescore->addItem("28");degreescore->addItem("29");
    degreescore->addItem("30");

     QLabel* lab10= new QLabel("Exam_Score:");
     //line8=new QLineEdit();
     entryscore = new QComboBox();
     entryscore->addItem("0");entryscore->addItem("1");entryscore->addItem("2");entryscore->addItem("3");entryscore->addItem("4");
     entryscore->addItem("5");entryscore->addItem("6");entryscore->addItem("7");entryscore->addItem("8");entryscore->addItem("9");
     entryscore->addItem("10");entryscore->addItem("11");entryscore->addItem("12");entryscore->addItem("13");entryscore->addItem("14");
     entryscore->addItem("15");entryscore->addItem("16");entryscore->addItem("17");entryscore->addItem("18");entryscore->addItem("19");
     entryscore->addItem("20");

     gl->addWidget(lab12,0,0,Qt::AlignLeft);
     gl->addWidget(fac,0,1,Qt::AlignRight);
     gl->addWidget(lab11,1,0,Qt::AlignLeft);
     gl->addWidget(line7,1,1,Qt::AlignRight);
     gl->addWidget(lab8,2,0,Qt::AlignLeft);
     gl->addWidget(line6,2,1,Qt::AlignRight);
     gl->addWidget(lab1,3,0,Qt::AlignLeft);
     gl->addWidget(line2,3,1,Qt::AlignRight);
     gl->addWidget(lab2,4,0,Qt::AlignLeft);
     gl->addWidget(line3,4,1,Qt::AlignRight);
     gl->addWidget(lab3,5,0,Qt::AlignLeft);
     gl->addWidget(deg,5,1,Qt::AlignRight);
     gl->addWidget(lab4,6,0,Qt::AlignLeft);
     gl->addWidget(bac,6,1,Qt::AlignRight);
     gl->addWidget(lab5,7,0,Qt::AlignLeft);
     gl->addWidget(matesam,7,1,Qt::AlignRight);
     gl->addWidget(lab6,8,0,Qt::AlignLeft);
     gl->addWidget(logicesam,8,1,Qt::AlignRight);
     gl->addWidget(lab7,9,0,Qt::AlignLeft);
     gl->addWidget(laurea,9,1,Qt::AlignRight);
     gl->addWidget(lab9,10,0,Qt::AlignLeft);
     gl->addWidget(degreescore,10,1,Qt::AlignRight);
     gl->addWidget(lab10,11,0,Qt::AlignLeft);
     gl->addWidget(entryscore,11,1,Qt::AlignRight);



     gb->setLayout(gl);
    // cont->addWidget(cb);
     cont->addWidget(gb);


       //MAIN WINDOW
      mainlayout->addWidget(facultiesview);
      mainlayout->addLayout(cont);

      //BUTTON
      QHBoxLayout* push_b=new QHBoxLayout();
      QPushButton* aggiungi= new QPushButton("Add"); // buttone per aggiungere una nuova facolta
      aggiungi->setIcon(QIcon(":/imag/images/add.png"));
      QPushButton* remove= new QPushButton("Cancel"); // per togliere un elemento sulla del model visibile sulla view
      remove->setIcon(QIcon(":/imag/images/cancel.png"));
      QPushButton* M_eng= new QPushButton("Mechanical Engineering"); // per aggiungere una specialita in facolta di engineering
      M_eng->setIcon(QIcon(":/imag/images/mecanical.png"));
      QPushButton* C_eng= new QPushButton("Computer Engineering"); //per aggiungere una specialita in facolta di science.
      C_eng->setIcon(QIcon(":/imag/images/comp.png"));
      QPushButton* aero= new QPushButton("Aeronautic Engineering");
      aero->setIcon(QIcon(":/imag/images/aero.png"));
      QPushButton* info= new QPushButton("Faculty Information");
      info->setIcon(QIcon(":/imag/images/info.png"));
      push_b->addWidget(aggiungi);
      push_b->addWidget(remove);
      push_b->addWidget(M_eng);
      push_b->addWidget(C_eng);
      push_b->addWidget(aero);
      push_b->addWidget(info);
      aggiungi->setFont(QFont("Times",10,QFont::DemiBold));
      remove->setFont(QFont("Times",10,QFont::DemiBold));
      M_eng->setFont(QFont("Times",10,QFont::DemiBold));
      C_eng->setFont(QFont("Times",10,QFont::DemiBold));
      aero->setFont(QFont("Times",10,QFont::DemiBold));
      info->setFont(QFont("Times",10,QFont::DemiBold));

      QVBoxLayout* fin=new QVBoxLayout(this);
      fin->addLayout(mnb);
      fin->addLayout(a_ric);
      fin->addLayout(mainlayout);
      fin->addLayout(push_b);

           //conection
      connect(pb,SIGNAL(clicked()),line1,SLOT(clear()));
      connect(cancel,SIGNAL(triggered()),this,SLOT(close()));
      connect(salva, SIGNAL(triggered()), this, SLOT(saveData()));
      connect(aggiungi,SIGNAL(clicked()),this,SLOT(addFac()));
      connect(remove,SIGNAL(clicked()),this,SLOT(remove_row()));
      connect(M_eng,SIGNAL(clicked()),this,SLOT(Mec_eng()));
      connect(C_eng,SIGNAL(clicked()),this,SLOT(Comp_eng()));
      connect(aero,SIGNAL(clicked()),this,SLOT(Aero()));
      connect(info,SIGNAL(clicked()),this,SLOT(Fac_info()));
      connect(line1, SIGNAL(textChanged(QString)), this, SLOT(textFilterChanged()));

}

MainWindow::~MainWindow(){}


QSize MainWindow:: sizeHint()const{
    return QSize(600,350);
}

//add a new element at the top of the listview
void MainWindow::addFac(){


        adapter->insertrow(adapter->rowCount(),line7->text().toStdString(),line6->text().toStdString(),fac->currentText().toStdString(),line2->text().toStdString(),line3->text().toStdString(),
                             deg->currentText().toInt(),bac->currentText().toStdString(),matesam->currentText().toInt(),
                             logicesam->currentText().toInt(),laurea->currentText().toStdString(),degreescore->currentText().toInt(),
                             entryscore->currentText().toInt());

        facultiesview->clearSelection();
        facultiesview->selectionModel()->clearCurrentIndex();
        facultiesview->selectionModel()->select(adapter->index(adapter->rowCount() - 1, 0), QItemSelectionModel::Select);
}


// cancel selected element in the list view
void MainWindow::remove_row(){

   adapter->removeRows(facultiesview->selectionModel()->currentIndex().row());
}


// SAVE data on xml file
void MainWindow::saveData() {
    try {
        adapter->saveToFile();
    } catch (std::exception) {
        QMessageBox box(QMessageBox::Warning, "Errore di salvataggio", "Non è stato possibile scrivere sul file", QMessageBox::Ok);
        box.exec();
    }
}


//collect the student name in the faculty of mechanical enGINEERING
void MainWindow::Mec_eng(){

    dialog1* dia=new dialog1(this,adapter->getModel()->Mec_StudentName());
    dia->exec();

}

void MainWindow::Comp_eng(){

    dialog1* dia=new dialog1(this,adapter->getModel()->Comp_StudentName());
    dia->exec();

}


void MainWindow::Aero(){

    dialog1* dia=new dialog1(this,adapter->getModel()->Aero_StudentName());
    dia->exec();

}

//return the information in base of the choosen row on the view.
void MainWindow::Fac_info(){

    int aux= facultiesview->selectionModel()->currentIndex().row();
    if(aux < 0)
        aux=adapter->rowCount();

    Dialog2* dia2=new Dialog2(this,adapter->getModel()->getFaculty(aux));
    dia2->exec();

}

void MainWindow::loadData() {

    adapter->loadFromFile();
}


/*void MainWindow::textFilterChanged() {
    QRegExp regex(line1->text(), Qt::CaseInsensitive, QRegExp::Wildcard);
    adapter->setFilterRegExp(regex);
}*/
