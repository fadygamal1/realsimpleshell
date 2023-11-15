#include "main.h"

/**
 * prompt - prints the prompt.
 *
 * Return: no thing.
 */
void prompt(void)
{
	int length;
	char *cwd;

	cwd = getcwd(NULL, 4096);
	length = 0;
	while (cwd[length])
		length++;
	write(STDOUT_FILENO, cwd, length);
	write(STDOUT_FILENO, "(^~^) ", 6);
	fflush(stdout);
}
