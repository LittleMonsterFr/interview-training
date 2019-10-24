//
// Created by Damien Laidin on 23/10/2019.
//

#ifndef INTERVIEW_TRAINING_QUEUE_HPP
#define INTERVIEW_TRAINING_QUEUE_HPP

#include <stdexcept>

using namespace std;

template <typename T>
class Queue
{
protected:
    template <typename U>
    class QueueNode
    {
    public:
        QueueNode<U> *next = nullptr;
        T& _val;

        explicit QueueNode(T& val) : _val(val) {}
    };

    QueueNode<T> *first = nullptr;
    QueueNode<T> *last = nullptr;

public:
    void add(T& item);
    T& remove();
    T& peek();
    bool isEmpty();
};

template<typename T>
void Queue<T>::add(T& item)
{
    auto *node = new QueueNode<T>(item);

    if (last != nullptr)
    {
        last->next = node;
    }
    last = node;
    if (first == nullptr)
    {
        first = last;
    }
}

template<typename T>
T& Queue<T>::remove()
{
    if (first == nullptr)
    {
        throw logic_error("The queue is empty.");
    }
    QueueNode<T> *new_first = first->next;
    T& data = first->_val;
    delete first;
    first  = new_first;
    if (first == nullptr)
    {
        last = nullptr;
    }
    return data;
}

template<typename T>
T& Queue<T>::peek()
{
    if (first == nullptr)
    {
        return logic_error("The queue is empty.");
    }

    return first->_val;
}

template<typename T>
bool Queue<T>::isEmpty()
{
    return first == nullptr;
}

#endif //INTERVIEW_TRAINING_QUEUE_HPP
