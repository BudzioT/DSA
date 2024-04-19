#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>

/* Node needed for Linked List */
template<typename T> class Node
{
public:
    Node();
    Node(T data);

    T data;
    Node* next;
};

/* Linked List */
template<typename T> class LinkedList
{
public:
    LinkedList();
    LinkedList(T value);

    ~LinkedList();

    Node<T>* head() const;

    void push(T value);
    void insertAfter(Node<T>* prev, T value);
    void append(T value);

    bool search(T value);
    bool searchR(T value, Node<T>* head);

    int length();
    int lengthR(Node<T>* head, int count = 0);

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

/* Get the head */
template<typename T> Node<T>* LinkedList<T>::head() const
{
    return m_head;
}

/* Inserting a Node at the beggining, Time: O(1), Auxiliary: O(1) */
template<typename T> void LinkedList<T>::push(T value)
{
    Node<T>* newNode = new Node<T>(value);
    newNode->next = m_head;
    m_head = newNode;
}

/* Insert a Node after given one, Time: O(1), Auxiliary: O(1) */
template<typename T> void LinkedList<T>::insertAfter(Node<T>* prev, T value)
{
    if (!prev)
        return;

    Node<T>* newNode = new Node<T>(value);
    newNode->next = prev->next;
    prev->next = newNode;
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

/* Searches if the given value exists, Time: O(N), Auxiliary: O(1) */
template<typename T> bool LinkedList<T>::search(T value)
{
    Node<T>* current = m_head;
    while (current) {
        if (current->data == value)
            return true;
        current = current->next;
    }
    return false;
}

/* Searches if the given value exists Recursive, Time: O(N), Auxiliary: O(N) */
template<typename T> bool LinkedList<T>::searchR(T value, Node<T>* head)
{
    if (!head)
        return false;
    if (head->data == value)
        return true;
    return searchR(value, head->next);
}

/* Get the length of List, Time: O(N), Auxiliary: O(1) */
template<typename T> int LinkedList<T>::length()
{
    int len = 0;
    Node<T>* curr = m_head;
    while (curr) {
        ++len;
        curr = curr->next;
    }
    return len;
}

/* Get the length of List Recursive, Time: O(N), Auxiliary: O(N) */
template<typename T> int LinkedList<T>::lengthR(Node<T>* head, int count)
{
    if (!head)
        return count;
    return lengthR(head->next, count + 1);
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
