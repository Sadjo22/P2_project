#ifndef DIALOG2_H
#define DIALOG2_H

#include<QDialog>
#include"mainwindow.h"
#include"model.h"
#include"engineering.h"


class Dialog2: public QDialog{

public:
    explicit Dialog2(QWidget *parent ,const Engineering*);
    ~Dialog2()override{}

private:
    const Engineering * eng;

private slots:
    void accept() override;
};


#endif // DIALOG2_H
