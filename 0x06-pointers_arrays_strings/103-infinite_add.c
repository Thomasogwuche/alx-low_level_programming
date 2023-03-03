#include "main.h"

/**
 * rev_string - reverse array
 * @n: integer params
 * Return: 0
 */
#include <string.h>

char *infinite_add(char *n1, char *n2, char *r, int size_r) {
    int len1 = strlen(n1);
    int len2 = strlen(n2);
    int carry = 0, sum = 0;
    int i = len1 - 1, j = len2 - 1, k = size_r - 1;

    r[k] = '\0'; // set the terminating character

    while (i >= 0 || j >= 0) {
        int d1 = (i >= 0) ? n1[i--] - '0' : 0;
        int d2 = (j >= 0) ? n2[j--] - '0' : 0;

        sum = d1 + d2 + carry;
        carry = sum / 10;
        sum = sum % 10;

        if (k < 1) {
            return 0; // result can not be stored in r
        }
        r[--k] = sum + '0';
    }

    if (carry > 0) {
        if (k < 1) {
            return 0; // result can not be stored in r
        }
        r[--k] = carry + '0';
    }

    return &r[k];
}

