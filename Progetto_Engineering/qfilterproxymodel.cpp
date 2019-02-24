/*#include "qfilterproxymodel.h"
#include "modeladapter.h"

QFilterProxyModel::QFilterProxyModel(QObject* parent) : QSortFilterProxyModel (parent) {

}

bool QFilterProxyModel::toggleType(const QModelIndex& index) {
    QModelIndex index_source = mapToSource(index);
    return static_cast<QListModelAdapter*>(sourceModel())->toggleType(index_source);
}

bool QFilterProxyModel::insertrow(int indice,int count,const string& a,const string& b, const string&c, const string& d, int e, const string& f, int g,
                                        int h, const string& i, int j, int k,const QModelIndex& parent){
    bool result = sourceModel()->insertrow(indice,count,a,b,c,d,e,f,g,h,i,j,k, parent);
    invalidateFilter();
    return result;
}

bool QFilterProxyModel::filterAcceptsRow(int row_source, const QModelIndex&) const {
    // ritornare true se il testo del Todo matcha una RegExp
    // altrimenti ritorna false
    QModelIndex index_source = sourceModel()->index(row_source, 0);

    return sourceModel()->data(index_source).toString().contains(filterRegExp());
}
*/
