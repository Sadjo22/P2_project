#include "items_window.h"


Items_Window::Items_Window(QWidget* parent):QListView(parent){
   setSelectionMode( QAbstractItemView::SingleSelection);

}

