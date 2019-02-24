/*#ifndef QFILTERPROXYMODEL_H
#define QFILTERPROXYMODEL_H


#include <QSortFilterProxyModel>



class QFilterProxyModel : public QSortFilterProxyModel {
public:
    QFilterProxyModel(QObject* = nullptr);

    bool toggleType(const QModelIndex&);
    bool insertRows(int, int = 1, const QModelIndex& = QModelIndex()) override;
    bool insertrow(int indice,int row,const string&,const string&, const string&, const string&, int, const string&, int,
                   int, const string&, int, int,const QModelIndex& parent);

protected:
    bool filterAcceptsRow(int, const QModelIndex&) const override;
};


#endif // QFILTERPROXYMODEL_H
*/
