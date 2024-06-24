#ifndef STACK_H
#define STACK_H

template<typename T> class Node
{
public:
    explicit Node(T element);

public:
    T data;
    Node* next = nullptr;
};

template<typename T>
Node<T>::Node(T element) : data(element)
{ }

template<typename T> class Stack
{
public:
    Stack();
    ~Stack();

    void push(T element);
    T pop();
    T peek() const;
    bool isEmpty();

private:
    Node<T>* root;
};

template<typename T>
bool Stack<T>::isEmpty() {
    return !root;
}

template<typename T>
T Stack<T>::peek() const {
    return (root) ? root->data : T();
}

template<typename T>
T Stack<T>::pop() {
    if (root) {
        Node<T> temp = *root;
        root = root->next;
        return temp.data;
    }

    return T();
}

template<typename T>
void Stack<T>::push(T element) {
    auto* node = new Node<T>(element);
    node->next = root;
    root = node;
}

template<typename T>
Stack<T>::~Stack() {
    while (root && root->next) {
        auto* temp = root->next;
        delete root;
        root = temp;
    }

    delete root;
    root = nullptr;
}


template<typename T>
Stack<T>::Stack() : root(nullptr)
{ }




#endif //STACK_H
