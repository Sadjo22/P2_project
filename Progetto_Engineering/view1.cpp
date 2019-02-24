#include "view1.h"

View1::View1(QWidget* parent):QListView(parent){
    setSelectionMode( QAbstractItemView::SingleSelection);
}

QSize View1::sizeHint()const{
   return QSize(500,150);
}
