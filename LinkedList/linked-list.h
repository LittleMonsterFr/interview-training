//
// Created by Damien Laidin on 22/10/2019.
//

#ifndef INTERVIEW_TRAINING_LINKED_LIST_H
#define INTERVIEW_TRAINING_LINKED_LIST_H

class Node
{
public:
    explicit Node(int val) : _val(val){};

    Node *next = nullptr;
    int _val;
};

class LinkedList
{};



#endif //INTERVIEW_TRAINING_LINKED_LIST_H
