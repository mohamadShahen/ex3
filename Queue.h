
#ifndef EX3_QUEUE_H
#define EX3_QUEUE_H

//Node class
template <class T>

class Node{
public:
    T m_data;
    Node* m_next;
};

//Queue class
template <class T>

class Queue{

    Node<T> *m_back;
    Node<T> *m_front;
    int m_size;

public:

    class Iterator;
    class EmptyQueue{};

    Queue();
    ~Queue();
    Queue& operator=(const Queue&) = default;
    void pushBack(const T&);
    T& front() const;
    void popFront();
    int size() const;

};


//Iterator Class

template<class T>

class Queue<T>::Iterator{
    Node<T> *m_ptr;

public:

    class InvalidOperation{};

    Iterator(Node<T> *ptr = nullptr);
    ~Iterator() = default;
    Iterator& operator=(const Iterator&) = default;

    Iterator& begin() const;
    Iterator& end() const;
    Iterator& operator++();
    bool operator!=(const Iterator&) const;
    T& operator*() const;

};

/*******************************************************************************************************
 *
 *                 implementation of member functions of the class Queue
 *
 *******************************************************************************************************/

template <class T>

Queue<T>::Queue() {
    m_back = m_front = nullptr;
    m_size = 0;
}

template <class T>

Queue<T>::~Queue()
{
    for (int i=0;i<m_size;i++)
    {
        popFront();
    }
}

template <class T>

void Queue<T>::pushBack(const T &data) {
    Node<T> newNode = new Node<T>;
    newNode.m_data = data;
    newNode.m_next = nullptr;
    if (m_size == 0) {
        m_back = newNode;
        m_front = newNode;
        m_size++;
    } else if (m_size > 0) {
        m_back->m_next = newNode;
        m_back = newNode;
        m_size++;
    }
}

template <class T>

T& Queue<T>::front() const {
    return m_front->m_data;
}

template <class T>

void Queue<T>::popFront() {
    if (m_size == 0) {
        throw EmptyQueue();
    } else if (m_size > 0) {
        Node<T> *temp = m_front;
        m_front = m_front->m_next;
        if (m_front == nullptr) {
            m_back = nullptr;
        }
        delete temp;
        m_size--;
    }
}

template <class T>

int Queue<T>::size() const {
    return m_size;
}

/*******************************************************************************************************
 *
 *                 implementation of member functions of Iterator
 *
 *******************************************************************************************************/

template <class T>

Queue<T>::Iterator::Iterator(Node<T> *ptr)
{
    m_ptr = ptr;
}

template <class T>

typename Queue<T>::Iterator& Queue<T>::Iterator::begin() const
{
    if(*this->m_size == 0)
    {
        throw EmptyQueue();
    }
    return Iterator(*this->m_front);
}

template <class T>

typename Queue<T>::Iterator& Queue<T>::Iterator::end() const
{
    if(*this->m_size == 0)
    {
        throw EmptyQueue();
    }
    return Iterator(*this->m_back->next);
}

template <class T>

typename Queue<T>::Iterator& Queue<T>::Iterator::operator++()
{
    if (m_ptr == nullptr)
    {
        throw Queue<T>::Iterator::InvalidOperation();
    }
    return Iterator(m_ptr->next);
}

template <class T>

bool Queue<T>::Iterator::operator!=(const Iterator& it) const
{
    return (m_ptr != it.m_ptr);
}

template <class T>

T& Queue<T>::Iterator::operator*() const
{
    if(m_ptr == nullptr)
    {
        throw InvalidOperation();
    }
    return m_ptr->m_data;
}


#endif //EX3_QUEUE_H
