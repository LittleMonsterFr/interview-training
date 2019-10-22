//
// Created by Damien Laidin on 22/10/2019.
//

#include "string_compression.h"
#include <iostream>

int main()
{
    const char *str = "aabcccccaaa";

    char *res = compress_string((char *) str);

    std::cout << "result is : " << res << std::endl;

    free(res);

    return 0;
}