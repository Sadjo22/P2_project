#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include <QWidget>
#include <QApplication>
#include <QHBoxLayout>
#include <QGroupBox>
#include <QLineEdit>
#include <QComboBox>
#include <iostream>

using namespace std;


class Items_Window;
class View1;
class ModelAdapter;
class Model;

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow()override;
    QSize sizeHint()const override;

private:
    QHBoxLayout* area_ricerca;
    View1* facultiesview;
    ModelAdapter* adapter;
    QLineEdit* line1;
    QLineEdit* line2;
    QLineEdit* line3;
    QLineEdit* line6;
    QLineEdit* line7;
    QComboBox* laurea;
    QComboBox* deg;
    QComboBox* bac;
   // QComboBox *cb;
    QComboBox *fac;
    QComboBox *matesam;
    QComboBox *logicesam;
    QComboBox *degreescore;
    QComboBox *entryscore;

    void loadData();


private slots:
  void addFac();
  void remove_row();
  void saveData();
  void Mec_eng();
  void Comp_eng();
  void Aero();
  void Fac_info();
 // void textFilterChanged();

};


#endif // MAINWINDOW_H
