#ifndef LINKED_LIST
#define LINKED_LIST

// Created by janek-j

template<typename T>
struct Node {
    T element;
    Node *next;
}; //each node contains element and pointer to the next Node.

template<class T>
class LinkedList {
private:
    Node<T> *head;
public:
    LinkedList(); // Constructor. Creates empty list.

    void insert_element(T element); // O(n).
    void delete_element(T element); // O(n).

    void print_list() const; // O(n).
    void make_empty(); // O(n).

    bool is_empty();

    ~LinkedList(); // Destructor. Removes element from list. It simply makes it empty and frees memory.
};

#include "linked_list.cpp"

#endif