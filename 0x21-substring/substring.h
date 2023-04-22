#ifndef SUBSTRING_H
#define SUBSTRING_H

#include <stdlib.h>
#include <string.h>
int check_substring(char const *s,
	char const **words, int nb_words, int word_len, int start_index);
int *find_substring(char const *s, char const **words, int nb_words, int *n);

#endif
