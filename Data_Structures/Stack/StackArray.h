#ifndef STACK_H
#define STACK_H

const int MAX_SIZE = 1000;

template<typename T> class Stack
{
public:
    Stack();
    ~Stack();

    bool push(T element);
    T pop();
    T peek();
    bool isEmpty();
    bool isFull();

private:
    int m_top;
    T m_arr[MAX_SIZE];
};

template<typename T>
bool Stack<T>::isFull() {
    return m_top >= MAX_SIZE - 1;
}

/* Is the stack empty */
template<typename T>
bool Stack<T>::isEmpty() {
    return m_top < 0;
}

/* Grab element at the top */
template<typename T>
T Stack<T>::peek() {
    if (m_top > -1)
        return m_arr[m_top];
    return T();
}

/* Pop the element off the stack */
template<typename T>
T Stack<T>::pop() {
    if (m_top > -1)
        return m_arr[m_top--];
    return T();
}

/* Push element on top of the stack */
template<typename T>
bool Stack<T>::push(T element) {
    if (m_top < MAX_SIZE - 1) {
        m_arr[++m_top] = element;
        return true;
    }

    return false;
}

template<typename T>
Stack<T>::~Stack() = default;

template<typename T>
Stack<T>::Stack() : m_top(-1)
{ }

#endif //STACK_H
