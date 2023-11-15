#include "main.h"

/**
  * itos - convert an integer to a string.
  * @n: the integer to convert.
  *
  * Return: the string.
  */
char *itos(unsigned int n)
{
	unsigned int m, length;
	char *string;

	m = n;
	length = 1;

	while (m > 10)
	{
		m /= 10;
		length++;
	}

	string = malloc(sizeof(char) * length + 1);
	if (!string)
		return (NULL);

	m = length;
	while (m)
	{
		string[m - 1] = (n % 10) + '0';
		n /= 10;
		m--;
	}
	string[length] = '\0';

	return (string);
}
