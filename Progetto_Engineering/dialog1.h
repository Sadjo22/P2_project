#ifndef DIALOG1_H
#define DIALOG1_H

#include<QDialog>
#include"mainwindow.h"
#include"model.h"


class dialog1: public QDialog{

public:
    explicit dialog1(QWidget *parent ,Container<string> );
    ~dialog1()override {}

private:
    Container<string> cont;

private slots:
    void accept() override;
};

#endif // DIALOG1_H
