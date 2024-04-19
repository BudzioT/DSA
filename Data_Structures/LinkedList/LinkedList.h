#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>

template<typename T> class Node
{
public:
    Node();
    Node(T data);

    T data;
    Node* next;
};

template<typename T> class LinkedList
{
public:
    LinkedList();
    LinkedList(T value);

    ~LinkedList();

    void push(T value);
    void append(T value);

    template<typename T> friend std::ostream& operator<<(std::ostream& os, const LinkedList<T>& list);
private:
    Node<T>* m_head;
};


/* Node methods */

template<typename T> Node<T>::Node() : data(), next(nullptr)
{ }

template<typename T> Node<T>::Node(T value) : data(value), next(nullptr)
{ }


/* LinkedList methods */

template<typename T> LinkedList<T>::LinkedList() : m_head(nullptr)
{ }

template<typename T> LinkedList<T>::LinkedList(T value)
{
    m_head = new Node<T>(value);
}

template<typename T> LinkedList<T>::~LinkedList()
{
    while (m_head) {
        Node<T>* next = m_head->next;
        delete m_head;
        m_head = next;
    }
}

/* Inserting a Node at the beggining, Time: O(1), Auxiliary: O(1) */
template<typename T> void LinkedList<T>::push(T value)
{
    Node<T>* newNode = new Node<T>(value);
    newNode->next = m_head;
    m_head = newNode;
}

/* Insert a Node at the end, Time: O(N), Auxiliary: O(1) */
template<typename T> void LinkedList<T>::append(T value)
{
    Node<T>* newNode = new Node<T>(value);
    newNode->next = nullptr;

    Node<T>* last = m_head;
    while (last->next)
        last = last->next;
    last->next = newNode;
}


/* Friend functions */

/* Show the list content */
template<typename T> std::ostream& operator<<(std::ostream& os, const LinkedList<T>& list)
{
    Node<T>* node = list.m_head;
    while (node) {
        std::cout << node->data << " ";
        node = node->next;
    }
    return os;
}

#endif
