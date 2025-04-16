#include "linked_list.h"

template<typename T>
LinkedList<T>::LinkedList() {
    // Creates empty list. It implies, that head should be made null.
    head = nullptr;
}

template<typename T>
void LinkedList<T>::insert_element(T element) {
    Node<T> *new_node = new Node<T>{element, nullptr};
    if (!head) {
        head = new_node;
        return;
    } else {
        Node<T> *current = head;
        while (current -> next) {
            current = current->next;
        }
        current->next = new_node;
    }
}

template<typename T>
void LinkedList<T>::delete_element(T element) {
    Node<T> *current = head;
    if (current && current->element == element) {
        head = head->next;
        delete current;
        return;
    }
    while (current && current->next) {
        if (current->next->element == element) {
            Node<T>* to_delete = current->next;
            current->next = current->next->next;
            delete to_delete;
            return;
        }
        current = current->next;
    }
}

template<typename T>
void LinkedList<T>::print_list() const {
    std::cout << "Priting list: " << std::endl;
    Node<T> *current = head;
    while (current  ) {
        std::cout << current->element << " ";
        current = current -> next;
    }
    std::cout << std::endl;
}

template<typename T>
void LinkedList<T>::make_empty() {
    Node<T> *current = head;
    while (current) {
        Node<T> *temp = current;
        current = current -> next;
        delete temp;
    }
    head = nullptr;
}

template<typename T>
LinkedList<T>::~LinkedList() {
    make_empty();
}

template<typename T>
bool LinkedList<T>::is_empty() {
    return head == nullptr;
}