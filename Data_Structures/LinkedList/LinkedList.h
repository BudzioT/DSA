#ifndef LINKEDLIST_H
#define LINKEDLIST_H

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

#endif
