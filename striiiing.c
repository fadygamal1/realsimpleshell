#include "main.h"

char **split_string(const char *str, const char *delimiter);

/**
 * split_string - function that splits a string of words into tokens
 * @str: string to split
 * @delimiter: delimiters
 * Return: tokens of words
 */
char **split_string(const char *str, const char *delimiter)
{
	int word_count = 0;
	int index, i;
	char **str_array;
	const char *token;
	char *str_copy1, *str_copy2;

	if (!str)
		return (NULL);
	str_copy1 = _strdup(str);
	str_copy2 = _strdup(str);

	/* Figure out how many words are in str */
	word_count = 0;
	token = strtok(str_copy1, delimiter);
	while (token != NULL)
	{
		word_count++;
		token = strtok(NULL, delimiter);
	}

	/*
	 * Allocate enough space for that many char*s,
	 * plus one for the NULL pointer
	 */
	str_array = malloc(sizeof(char *) * (word_count + 1));
	if (str_array == NULL)
		return (NULL);

	/* Use strtok to get each word and add it to your array */
	token = strtok(str_copy2, delimiter);
	index = 0;
	while (token != NULL)
	{
		str_array[index] = _strdup(token);
		if (str_array[index] == NULL)
		{
			i = 0;
			while (i < index)
			{
				free(str_array[i]);
				i++;
			}
			free(str_array);
			free(str_copy1);
			free(str_copy2);
			return (NULL);
		}
		index++;
		token = strtok(NULL, delimiter);
	}
	str_array[word_count] = NULL;

	free(str_copy1);
	free(str_copy2);
	return (str_array);
}

/**
 * _strdup - duplicates a string
 * @str: string to duplicate
 * Return: a pointer to the duplicated string
 */
char *_strdup(const char *str)
{
	int len, index;
	char *new_str;

	if (str == NULL)
		return (NULL);

	len = 0;
	while (str[len] != '\0')
		len++;

	new_str = malloc(sizeof(char) * (len + 1));
	if (new_str == NULL)
		return (NULL);

	index = 0;
	while (index < len)
	{
		new_str[index] = str[index];
		index++;
	}
	new_str[index] = '\0';

	return (new_str);
}

/**
 * _strcmp - compares to strings
 * @s1: the first string
 * @s2: the second string
 * Return: 1 if the same and 0 otherwise
 */
int _strcmp(char *s1, char *s2)
{
	int i = 0, d = 0;

	while (d == 0)
	{
		if (s1[i] == '\0' && s2[i] == '\0')
			break;
		d = s1[i] - s2[i];
		i++;
	}
	return (d);
}

/**
 * _strcat - concatenates two strings
 * @str1: string to add to
 * @str2: string to append
 * Return: the concatenated string
 */
char *_strcat(char *str1, const char *str2)
{
	int index1 = 0, index2 = 0;

	while (str1[index1] != '\0')
		index1++;

	while (str2[index2])
		str1[index1++] = str2[index2++];

	str1[index1] = '\0';

	return (str1);
}

/**
 * _strtok - breaks a string into a sequesnce of more non-empty tokens
 * @str: string to be parsed
 * @delim: delimits the tokens in the parsed string
 * Return: a pointer to the next token or NULL if there are no more tokens
 */
char *_strtok(char *str, const char *delim)
{
	static char *next_token;
	int index, delim_index;

	if (str == NULL && next_token == NULL)
		return (NULL);

	if (str == NULL)
		str = next_token;
	else
		next_token = str;

	while (*str != '\0')
	{
		delim_index = 0;
		while (delim[delim_index] != '\0')
		{
			if (*str == delim[delim_index])
			{
				str++;
				break;
			}
			delim_index++;
		}
		if (delim[delim_index] == '\0')
			break;
	}

	index = 0;
	while (str[index] != '\0')
	{
		delim_index = 0;
		while (delim[delim_index] != '\0')
		{
			if (str[index] == delim[delim_index])
			{
				str[index] = '\0';
				break;
				next_token = &str[index + 1];
			}
			delim_index++;
		}
		index++;
	}
	if (str[index] == '\0')
		next_token = NULL;

	return (str);
}
