#include "LINKLIST.h"

template<typename T>
LINKLIST<T>::LINKLIST():head(nullptr),tail(nullptr),size(0){}   


template <typename T>
LINKLIST<T>::~LINKLIST() {
    Node<T>* current = head;
    while (current) {
        Node<T>* temp = current;
        current = current->next;
        delete temp;
    }
}

template <typename T>
void LINKLIST<T>::addFirst(const T data) {
    Node<T>* newFirst = new Node<T>(data);//cấp phát động
    if(!head){
        head = tail = newFirst;
    }
    else{
    newFirst->next = head;
    head->prev = newFirst;
    head = newFirst;//cập nhật con trỏ head
    }
    size++;
}

template <typename T>
void LINKLIST<T>::addLast(const T data){
    Node<T>* newLast = new Node<T>(data);
    if(!tail){
        head = tail = newLast;
    }
    else{
        newLast->prev = tail;
        tail->next = newLast;
        tail = newLast;
    }
    size++;
}

template <typename T>
Node<T>* LINKLIST<T>::begin() const{
    return head;
}

template <typename T>
Node<T>* LINKLIST<T>::end() const{
    return tail;
}

template <typename T>
void LINKLIST<T>::removeFirst(){
    if(!head) return;
    Node<T>* temp = head;//Node cần xóa
    head = head->next;//head của list sau khi xóa
    if(head){
        head->prev=nullptr;
    }
    else{
        tail = nullptr;//Danh sách rỗng
    }
    delete temp;
    size--;
}

template <typename T>
void LINKLIST<T>::removeLast(){
    if(!tail)return;
    Node<T>* temp = tail;
    tail = tail->prev;
    if(tail){//Điều kiện tail khác rỗng
        tail->next = nullptr;
    }
    else{
        head = nullptr;//Danh sách rỗng
    }
    delete temp;
    size--;
}

template <typename T>
void LINKLIST<T>::remove(Node<T>* node){
    if(!head||!node){
    cout << "Danh sách rỗng hoặc không hợp lệ!\n";
    return;
    }
    if(node==head){
        removeFirst();
    }
    else if(node==tail){
        removeLast();
    }
    else{
        node->prev->next=node->next;
        node->next->prev=node->prev;
        delete node;
        size--;
    }
}

template <typename T>
Node<T>* LINKLIST<T>::find(const T data) const{
    Node<T>* current = head;
    while(current){
        if(*current->data==*data){
            return current;
        }
        current = current->next;
    }
    return nullptr;
}


template <typename T>
void LINKLIST<T>::display() const{
    //head = head ->next;
    Node<T>* current = head;
    while(current){
        cout  << *current->data;
        current=current->next;
    }
    cout << endl;
}



