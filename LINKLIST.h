#ifndef LINKLIST_H
#define LINKLIST_H

#include <iostream>
using namespace std;

template <typename T>
struct Node {
    T data;
    Node<T>* next;
    Node<T>* prev;
    Node(T value) : data(value), prev(nullptr), next(nullptr) {}
};

template<typename T>
class LINKLIST {
private:
    Node<T>* head;
    Node<T>* tail;
    int size;

public:
    LINKLIST();
    ~LINKLIST();
    void addFirst(T const data);
    void addLast(T const data);
    Node<T>* begin() const;
    Node<T>* end() const;
    Node<T>* find(T const data) const;
    void removeFirst();
    void removeLast();
    void remove(Node<T>* node);
    void display() const;
    int getSize() const { return size; }
};

#endif
