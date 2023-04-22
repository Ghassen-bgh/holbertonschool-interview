#include "substring.h"

/**
 * check_substring - check if a substring is a concatenation of a list of words
 * @s: string to check
 * @words: array of words all substrings are a concatenation of
 * @nb_words: number of elements in @words
 * @word_len: length of each word
 * @start_index: index in @s to start checking from
 * Return: 1 if @s is a concatenation of all words in @words, else 0
 */
int check_substring(char const *s,
	char const **words, int nb_words, int word_len, int start_index)
{
	int *word_used = NULL;
	int i, j, k;

	word_used = malloc(sizeof(*word_used) * nb_words);
	if (!word_used)
		return (0);
	for (i = 0; i < nb_words; i++)
		word_used[i] = 0;

	for (i = start_index; i < start_index + nb_words * word_len; i += word_len)
	{
		for (j = 0; j < nb_words; j++)
		{
			if (word_used[j])
				continue;
			for (k = 0; k < word_len; k++)
			{
				if (s[i + k] != words[j][k])
					break;
			}
			if (k == word_len)
			{
				word_used[j] = 1;
				break;
			}
		}
		if (j == nb_words)
		{
			free(word_used);
			return (0);
		}
	}

	free(word_used);
	return (1);
}

/**
 * find_substring - find all substrings containing a list of words, within a
 *  given string
 * @s: string to search
 * @words: array of words all substrings must be a concatenation arrangement of
 * @nb_words: number of elements in @words
 * @n: stores the address at which to store the number of elements in the
 * returned array
 * Return: allocated array, storing each index in @s at which a substring was
 * found, or NULL if no solution is found
*/
int *find_substring(char const *s, char const **words, int nb_words, int *n)
{
	int *result = NULL;
	int word_len = strlen(words[0]);
	int s_len = strlen(s);
	int nb_substrings = s_len - nb_words * word_len + 1;

	*n = 0;
	if (nb_substrings <= 0)
		return (NULL);

	result = malloc(sizeof(*result) * nb_substrings);
	if (!result)
		return (NULL);

	for (i = 0; i < nb_substrings; i++)
	{
		if (check_substring(s, words, nb_words, word_len, i))
		{
			result[*n] = i;
			(*n)++;
		}
	}

	return (result);
}
