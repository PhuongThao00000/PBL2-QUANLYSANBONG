#ifndef LINKLIST_H
#define LINKLIST_H

#include <iostream>
using namespace std;

template <typename T>
struct Node{
    T data;
    Node<T> *next;
    Node<T> *prev;
    Node(T value):data(value),prev(nullptr),next(nullptr){}
};

template<typename T>
class LINKLIST {
    private:
        Node<T>* head;
        Node<T>* tail;//thêm con trỏ tail để tối ưu hóa
        int size;
    public:
        LINKLIST();
        ~LINKLIST();
        void addFirst(T const data);
        void addLast(T const data);
        Node<T>* begin() const;
        Node<T>* end() const;
        Node<T>* find(T const data) const;
        //Node<T>* operator[](int index) const;
        void removeFirst();
        void removeLast();
        //void removeMiddle(int pos);
        void remove(Node<T>* node);
        void display()const;
        int getSize() const {return size;}
};

#endif
