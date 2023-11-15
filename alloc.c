#include "main.h"

/**
  * strcat_alloc - reallocate memory for the both strings
  * and concatentes them.
  * @dest: the string to be appended to.
  * @src: the string to append.
  *
  * Return: the rusulting string.
  */
char *strcat_alloc(char *dest, char *src)
{
	int i, j;

	i = j = 0;

	while (dest[i] != '\0')
		i++;

	while (src[j] != '\0')
		j++;

	dest = _realloc(dest, i + 1, sizeof(char) * (i + j) + 1);
	if (!dest)
		return (NULL);

	j = 0;
	while (src[j] != '\0')
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';

	return (dest);
}
