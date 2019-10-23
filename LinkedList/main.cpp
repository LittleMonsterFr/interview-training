//
// Created by Damien Laidin on 22/10/2019.
//

#include <iostream>
#include "linked-list.h"

int main()
{
    LinkedList<char> l = LinkedList<char>();
    bool res;

    try
    {
        res = l.remove('B');
    }
    catch (logic_error &error)
    {
        std::cout << error.what() << std::endl;
    }

    l.append('k');
    l.append('a');
    l.append('y');
    l.append('a');
    l.append('k');

    std::cout << (l.isAPalindrome() ? "true" : "false") << std::endl;

    l.append('z');

    std::cout << (l.isAPalindrome() ? "true" : "false") << std::endl;

    res = l.remove('z');
    std::cout << (res ? "Removed value successfully" : "Failed to remove value") << std::endl;

    std::cout << (l.isAPalindrome() ? "true" : "false") << std::endl;

    return 0;
}