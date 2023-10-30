#include "palindrome.h"

/**
 * is_palindrome - checks whether or not a given unsigned integer is a palindrome
 * @n: number to be checked
 * Return: 1 if n is a palindrome, and 0 otherwise
 */

int is_palindrome(unsigned long n)
{
    unsigned long rev = 0, temp = n;
    while (temp != 0)
    {
        rev = rev * 10;
        rev = rev + temp % 10;
        temp = temp / 10;
    }
    if (n == rev)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
