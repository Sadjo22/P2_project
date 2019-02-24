#ifndef CONTAINER_H
#define CONTAINER_H


#include <iostream>
#include <string>
using std::cerr;
using std::endl;
using std::cout;



template <class T>
class Container{

        friend class iterator;
        friend class iteratore;
private:
     class ListNode{
         friend class Container<T>;
         friend class iterator;
     ListNode():data(0),next(0),prev(0){}
     ListNode(const T &e,ListNode* p=0,ListNode* n=0) : data(e),prev(p),next(n){}

//     ~ListNode(){if(next) delete next;}
         T data;
         ListNode *prev;
         ListNode *next;

     };
    ListNode *head;
    ListNode *tail;
    int size;


public:
    Container();
    int getSize()const;
    void append(const T &);
    void removeInternal(ListNode *);
    void pop_back();
    void pop_front();
    void removeAt(int);
    T& front();
    T& back();
    ~Container();
    Container& operator=(const Container&);

    T& operator[](unsigned int) const;
    const T At(int index)const;

    class iterator{
        public:
            ListNode *pos;
            iterator();
            T& operator*()const;
            T* operator->()const;
            bool operator==(const iterator& ) const;
            bool operator!=(const iterator&) const;
            iterator operator++(int);
            iterator operator--(int);
            iterator& operator++();
            iterator& operator--();

     };

    class iteratore{
    public:
        const ListNode* pos;
        iteratore();
        iteratore& operator++();
        iteratore operator ++(int);
        iteratore& operator--();
        iteratore operator --(int)const;
        const T& operator*()const;
        const T* operator->()const;
        bool operator!= (const iteratore&) const;
        bool operator==(const iteratore&)const;

    };

     iterator begin();
     iterator end();
     iteratore begin()const;
     iteratore end()const;
     static ListNode* copy(ListNode* fst,ListNode*& lst){
         if(fst== nullptr) return lst=nullptr;
         ListNode* ptr= new ListNode(fst->data,nullptr,nullptr);
         ListNode* p=ptr;
         while(fst->next !=nullptr){
             p->next=new ListNode(fst->next->data,p,nullptr);
             fst=fst->next;
             p=p->next;
         }
         lst=p;
         return ptr;
    }
    

};

#endif // CONTAINER_H

template<class T>
Container<T>::Container(): head(0), tail(0),size(0){}

// get the size of the list
template<class T>
int Container<T>::getSize()const {
    return size;
}

template< class T>
Container<T>& Container<T>::operator=(const Container& cont){
     if(this !=&cont){
       if(head) delete head;
       size=cont.size;
       head=copy(cont.head,tail);
     }
     return *this;
 }

// insert at the head of the list
template <class T>
void Container<T>::append(const T &e){

     if(!head){
         head=new ListNode(e,0,0);
         tail =head;
         size=1;
         return;
     }
     else{

         ListNode* ptr= new ListNode(e,0,head);
         head->prev=ptr;
         head=ptr;
     }
     size++;
     return;

}

//remove auxillary function

template <class T>
void Container<T>::removeInternal(ListNode *pos){
    if(pos){
        if(pos->prev)
            pos->prev->next = pos->next;
 
		if(pos->next)
			pos->next->prev = pos->prev;
 
		if(pos == head)
			head = pos->next;
 
		if(pos == tail)
			tail = pos->prev;
 
		delete pos;
 
		size--;
	}
}

//remove the node at the end of the list
template <class T>
void Container<T>::pop_back(){
    removeInternal(tail);
	
}

//remove the node first of the list
template <class T>
void Container<T>::pop_front(){		
	removeInternal(head);
	
}

// collect the first node of the list
template<class T>
T& Container<T>::front(){
    return head->data; 
}

//collect the last node of the list
template<class T>
T& Container<T>::back(){ 
    return tail->data;
}

template<class T>
void Container<T>::removeAt(int indice){
    if(head== nullptr || indice<0)
        return;
    ListNode* ptr=head;
    ListNode* prece=0;
    while(indice>=1 && ptr){
        prece=ptr;
        ptr=ptr->next;
        indice--;
    }
    if(ptr){
        if(!prece)
            head=ptr->next;
       else
            prece->next=ptr->next;
    }
     size--;
     delete ptr;
     return;
}

//container destruct. which operate the deep destruction on the list
template <class T>
Container<T>::~Container(){
    ListNode *current(head);
	while(current){
            ListNode *next( current->next );
			delete current;
			current = next;
	}
}

template<class T>
T& Container<T>::iterator::operator*()const{
    return pos->data;
}

template<class T>
const T& Container<T>::iteratore::operator*()const{
    return pos->data;
}

template<class T>
T* Container<T>::iterator::operator->()const{
    return &(pos->data);
}

template<class T>
const T* Container<T>::iteratore::operator->()const{
    return &(pos->data);
}

template<class T>
bool Container<T>::iterator::operator!=(const iterator &rhs)const{
    return this->pos != rhs.pos; 
}

template<class T>
bool Container<T>::iteratore::operator!=(const iteratore &rhs)const{
    return this->pos != rhs.pos;
}

template<class T>
typename Container<T>::iterator Container<T>::iterator::operator++(int){
   iterator temp;
    if(pos){
        temp.pos=pos;
        pos=pos->next;
    }
    return temp;
}

template<class T>
typename Container<T>::iteratore Container<T>::iteratore::operator++(int){
   iteratore temp;
    if(pos){
        temp.pos=pos;
        pos=pos->next;
    }
    return temp;
}


template<class T>
typename Container<T>::iterator Container<T>::iterator::operator--(int){
   iterator temp;
    if(pos){
        temp.pos=pos;
        pos=pos->prev;
    }
    return temp;
}

template<class T>
typename Container<T>::iteratore Container<T>::iteratore::operator--(int)const{
   iteratore temp;
    if(pos){
        temp.pos=pos;
        pos=pos->prev;
    }
    return temp;
}


template <class T>
bool Container<T>::iterator::operator==(const iterator& i) const
{
    return this->pos==i.pos;
}

template <class T>
bool Container<T>::iteratore::operator==(const iteratore& i) const
{
    return this->pos==i.pos;
}

template<class T>
typename Container<T>::iterator& Container<T>::iterator::operator--(){
    pos = pos->prev;
    return *this; 
}

template<class T>
typename Container<T>::iteratore& Container<T>::iteratore::operator--(){
    pos = pos->prev;
    return *this;
}

  
template <class T>
typename Container<T>::iterator Container<T>::begin(){
   // return iterator(head);
    iterator temp;
    temp.pos=head;
    return temp;
}

template <class T>
typename Container<T>::iteratore Container<T>::begin()const{

    iteratore temp;
    temp.pos=head;
    return temp;
}


template <class T>
typename Container<T>::iterator Container<T>::end(){
    //return iterator(0);
    iterator temp;
    return temp;
}

template <class T>
typename Container<T>::iteratore Container<T>::end()const{
    iteratore temp;
    return temp;
}

template<class T>
T & Container<T>::operator[](unsigned int i) const{

    if(i>=size){

           cout<<"indice fuori bound";
           //return;
    }

    ListNode * temp= head;
    bool esci =false;
    for (unsigned int j=0; j<size && !esci; ++j){
        if(j==i)
            esci=true;
        else
        temp=temp->next;
    }

    return (temp->data);
}

// return the node at the nth position
template<class T>
const T Container<T>::At(int index)const{
    ListNode* ptr=head;
    int counter=0;

            while(ptr != nullptr){
                if(counter==index)
                    return ptr->data;
                counter++;
                ptr=ptr->next;

            }
            return 0;
}


template<class T>
Container<T>::iterator::iterator():pos(0){}

template<class T>
Container<T>::iteratore::iteratore():pos(0){}

template <class T>
typename Container<T>::iterator& Container<T>::iterator::operator++()
{
    if(pos)
        pos=pos->next;
    return *this;
}


template <class T>
typename Container<T>::iteratore& Container<T>::iteratore::operator++()
{
    if(pos)
        pos=pos->next;
    return *this;
}



/*template<class T>
Container<T>::ListNode* container<T>::copy(ListNode* fst,ListNode *prv,ListNode* &l){

    if(fst==nullptr) return lst=nullptr;

    ListNode* ptr= new ListNode(fst-> )


}*/

