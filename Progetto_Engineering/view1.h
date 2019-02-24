#ifndef VIEW1_H
#define VIEW1_H

#include<QListView>




class View1:public QListView{

public:
    View1(QWidget* =nullptr);
    QSize sizeHint() const override;
};

#endif // VIEW1_H
