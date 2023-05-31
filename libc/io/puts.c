#include <stdio.h>
#include <internal/io.h>

int puts(const char *str)
{
    int len = 0;

    int result;
    while (*str)
    {
        result = putchar(*str++);
        if (result < 0)
        {
            return result;
        }
        else
        {
            len += result;
        }
    }
    result = putchar('\n');
    if (result < 0)
    {
        return result;
    }
    else
    {
        len += result;
    }
    return len;
}

int putchar(char c)
{
    return write(1, &c, 1);
}