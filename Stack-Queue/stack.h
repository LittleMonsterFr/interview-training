//
// Created by Damien Laidin on 23/10/2019.
//

#ifndef INTERVIEW_TRAINING_STACK_H
#define INTERVIEW_TRAINING_STACK_H

#include <stdexcept>

using namespace std;

template <typename T>
class Stack
{
private:
    template <typename U>
    class StackNode
    {
    private:
        StackNode<U> *next = nullptr;
        U _val;

    public:
        explicit StackNode<U>(U val) : _val(val) {};
    };

private:
    StackNode<T> *top = nullptr;

public:
    T pop();
    void push(T item);
    T peek();
    bool isEmpty();
};

template <typename T>
T Stack<T>::pop()
{
    if (top == nullptr)
    {
        throw logic_error("The stack is empty");
    }

    StackNode<T> *node = top->next;
    T item = top->_val;
    top = node;
    delete node;
    return item;
}

template<typename T>
void Stack<T>::push(T item)
{
    auto *node = new StackNode<T>(item);
    top->next = node;
    top = node;
}

template<typename T>
T Stack<T>::peek()
{
    if (top == nullptr)
    {
        throw logic_error("The stack is empty");
    }

    return top;
}

template<typename T>
bool Stack<T>::isEmpty()
{
    return top == nullptr;
}

#endif //INTERVIEW_TRAINING_STACK_H
