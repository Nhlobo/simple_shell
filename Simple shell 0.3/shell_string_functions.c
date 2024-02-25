/* Filename: shell_string_functions.c */

#include "shell_header.h"
#include <stdlib.h>

/**
 * custom_strcat - Concatenate two strings
 * @str1: First string
 * @str2: Second string
 *
 * Return: Pointer to the concatenated string
 */
char *custom_strcat(char *str1, char *str2)
{
    char *result;
    int i, j;

    /* Get length of resulting string */
    for (i = 0; str1[i] != '\0'; i++)
        ;
    for (j = 0; str2[j] != '\0'; j++)
        ;

    /* Allocate memory for the concatenated string */
    result = malloc(i + j + 2);

    if (result == NULL)
        return (NULL);

    /* Copy str1 to result */
    for (i = 0; str1[i] != '\0'; i++)
        result[i] = str1[i];

    /* Add '/' if needed */
    if (result[i - 1] != '/')
        result[i++] = '/';

    /* Copy str2 to result */
    for (j = 0; str2[j] != '\0'; j++)
        result[i + j] = str2[j];

    /* Add null terminator */
    result[i + j] = '\0';

    return (result);
}
