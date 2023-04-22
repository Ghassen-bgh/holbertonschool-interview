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
	int remaining = nb_words;
	char const *p = s + start_index;

	while (remaining > 0)
	{
		int found = 0;

		for (int j = 0; j < nb_words; j++)
		{
			if (strncmp(p, words[j], word_len) == 0)
			{
				p += word_len;
				found = 1;
				remaining--;
				break;
			}
		}

		if (!found)
		{
			return (0);
		}
	}
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
	int s_len = strlen(s);
	int word_len = strlen(words[0]);
	int substr_len = word_len * nb_words;

	if (s_len < substr_len || nb_words == 0)
	{
		*n = 0;
		return (NULL);
	}

	int *result = (int *) malloc(sizeof(int) * s_len);
	int result_count = 0;

	for (int i = 0; i <= s_len - substr_len; i++)
	{
		if (check_substring(s, words, nb_words, word_len, i))
		{
			result[result_count++] = i;
		}
	}

	if (result_count == 0)
	{
		free(result);
		*n = 0;
		return (NULL);
	}

	*n = result_count;
	return (result);
}
