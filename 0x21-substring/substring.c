#include "substring.h"


/**
* find_substring - finds all possible
*    substrings of a list of words within a given string
* @s: string to scan
* @words: array of words all substrings must be concatenation arrangement of
* @nb_words: number of the elements in an array words
* @n: address at which to store number of the elements in returned array
* Return: allocated array, storing each index in s,
*    at which a substring was found, else NULL
*/

int *find_substring(char const *s, char const **words, int nb_words, int *n)
{
	int len, word_length, j, i = 0, k;
	int *element, *found;

	if (!s)
		return (NULL);
	*n = 0, len = strlen(s), word_length = strlen(words[0]);
	found = malloc(nb_words * sizeof(int));
	element = malloc(len * sizeof(int));
	while (i <= len - nb_words * word_length)
	{
		for (j = 0; j < nb_words; j++)
			found[j] = 0;
		for (j = 0; j < nb_words; j++)
		{
			for (k = 0; k < nb_words; k++)
			{
				if (found[k] == 0 &&
					strncmp(s + i + j * word_length, words[k], word_length) == 0)
				{
					found[k] = 1;
					break;
				}
			}
			if (k == nb_words)
				break;
		}
		if (j == nb_words)
			element[(*n)++] = i;
		i++;
	}
	free(found);
	return (element);
}
