#include "main.h"

/**
  * _strlen - returns the length of a string
  * @s: the string
  *
  * Return: length of s
  */
int _strlen(char *s)
{
	int i = 0;

	if (!s)
		return (0);

	while (*(s + i) != '\0')
		i++;
	return (i);
}
