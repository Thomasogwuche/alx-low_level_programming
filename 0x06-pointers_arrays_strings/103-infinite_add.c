#include "main.h"

/**
 * infinite_add - Adds two numbers represented as strings and stores the result
 *                in a buffer.
 *
 * @n1: The first number as a string.
 * @n2: The second number as a string.
 * @r: The buffer to store the result.
 * @size_r: The size of the buffer r.
 *
 * Return: A pointer to the result string on success, or 0 on failure.
 */
char *infinite_add(char *n1, char *n2, char *r, int size_r)
{
    int len1 = _strlen(n1);
    int len2 = _strlen(n2);
    int carry = 0, sum = 0;
    int i = len1 - 1, j = len2 - 1, k = size_r - 1;

    r[k] = '\0'; /* Set the terminating character */

    while (i >= 0 || j >= 0)
    {
        int d1 = (i >= 0) ? n1[i--] - '0' : 0;
        int d2 = (j >= 0) ? n2[j--] - '0' : 0;

        sum = d1 + d2 + carry;
        carry = sum / 10;
        sum = sum % 10;

        if (k < 1)
        {
            return (0); /* Result can not be stored in r */
        }
        r[--k] = sum + '0';
    }

    if (carry > 0)
    {
        if (k < 1)
        {
            return (0); /* Result can not be stored in r */
        }
        r[--k] = carry + '0';
    }

    return (&r[k]);
}

/**
 * _strlen - Calculates the length of a string.
 *
 * @s: The string to calculate the length of.
 *
 * Return: The length of the string.
 */
int _strlen(char *s)
{
    int len = 0;

    while (s[len] != '\0')
    {
        len++;
    }

    return (len);
}
