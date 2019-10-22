//
// Created by Damien Laidin on 22/10/2019.
//

#include "string_compression.h"

#include <cstring>
#include <cstdlib>

using namespace std;

char *int_to_ascii(int val)
{
    int r = val % 10;
    int a = val;

    char *res = (char *) calloc(8, sizeof(char));
    int index = 0;

    while (r != 0)
    {
        res[index++] = '0' + r;
        a = a / 10;
        r = a % 10;
    }

    size_t len = strlen(res);
    for (size_t i = 0; i < len / 2; i++)
    {
        char tmp = res[i];
        res[i] = res[len - 1 - i];
        res[len - 1 - i] = tmp;
    }

    return res;
}

char *compress_string(char *str)
{
    if (str == nullptr)
    {
        return nullptr;
    }

    size_t len = strlen(str);
    char *res = (char *) calloc(len, sizeof(char));
    int res_index = 0;

    char c = str[0];
    int num = 1;
    for (size_t index = 1; index <= len; index++)
    {
        if (index < len && str[index] == c)
        {
            num++;
        }
        else
        {
            res[res_index++] = c;
            char *num_char = int_to_ascii(num);
            size_t num_char_len = strlen(num_char);
            if (res_index + num_char_len >= len)
            {
                return str;
            }
            memcpy(&res[res_index], num_char, sizeof(char) * num_char_len);
            free(num_char);
            res_index += num_char_len;
            c = str[index];
            num = 1;
        }
    }

    return res;
}