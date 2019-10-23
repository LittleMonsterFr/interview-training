//
// Created by Damien Laidin on 22/10/2019.
//

#ifndef INTERVIEW_TRAINING_LINKED_LIST_H
#define INTERVIEW_TRAINING_LINKED_LIST_H

#include <stdexcept>

using namespace std;

template <typename T> class LinkedList
{
    template<typename U> class Node
    {
    public:
        explicit Node(U val) : _val(val){};

        Node *prev = nullptr;
        Node *next = nullptr;
        U _val;
    };

private:
    Node<T> *head = nullptr;
    Node<T> *tail = nullptr;

public:

    void append(T val);
    bool remove(T val);
    bool isAPalindrome();
};

template <typename T>
void LinkedList<T>::append(T val)
{
    auto *node = new Node<T>(val);

    if (head == nullptr)
    {
        head = node;
        tail = head;
    }
    else
    {
        tail->next = node;
        node->prev = tail;
        tail = node;
    }
}

template <typename T>
bool LinkedList<T>::remove(T val)
{
    Node<T> *node = head;
    if (head == nullptr)
    {
        throw logic_error("The linked list is empty.");
    }

    if (head->_val == val)
    {
        head = head->next;
        delete head;
        return true;
    }

    while (node->next != nullptr)
    {
        if (node->next->_val == val)
        {
            Node<T> *node_to_remove = node->next;
            node->next = node_to_remove->next;
            if (node_to_remove->next != nullptr)
            {
                node_to_remove->next->prev = node;
            }
            else
            {
                tail = node_to_remove->next;
            }
            delete node_to_remove;
            return true;
        }
        node = node->next;
    }

    return false;
}

template<typename T>
bool LinkedList<T>::isAPalindrome()
{
    Node<T> *start = head;
    Node<T> *end = tail;

    if (head == nullptr)
    {
        return false;
    }
    else if (head == tail)
    {
        return true;
    }

    while (start != nullptr && end != nullptr)
    {
        if (start->_val != end->_val)
        {
            return false;
        }

        if (start->next == end)
        {
            return true;
        }

        start = start->next;
        end = end->next;
    }

    return true;
}

#endif //INTERVIEW_TRAINING_LINKED_LIST_H
