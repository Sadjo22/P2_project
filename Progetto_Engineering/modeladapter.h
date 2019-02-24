#ifndef MODELADAPTER_H
#define MODELADAPTER_H
#include<QAbstractListModel>
#include <QSortFilterProxyModel>
#include<string>
#include<iostream>
//#include"container.h"
template<class T>
class Container;
using namespace std;

class Engineering;
class Model; // dichiarazione incompleta


class ModelAdapter:public QAbstractListModel{

private:
    Model* model;   //riferimento al model


public:
    ModelAdapter(QObject* =nullptr);
    ~ModelAdapter() override;

       int rowCount(const QModelIndex& = QModelIndex()) const override;
       Model* getModel()const;
       QVariant data(const QModelIndex&, int role = Qt::DisplayRole) const override;
       void saveToFile()const;
       void loadFromFile();
       void Read_Info()const;
       QString modifica();
       void insertrow(int indice,const string&,const string&, const string&,const string&, const string&, int, const string&, int,
                      int, const string&, int, int);
       bool removeRows(int, int = 1, const QModelIndex& = QModelIndex()) override;


protected:
   // bool filterAcceptsRow(int, const QModelIndex&) const override;
};


#endif // MODELADAPTER_H
