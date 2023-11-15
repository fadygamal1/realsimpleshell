#include "main.h"

/**
  * shell_exit - handles the exit status of the shell
  * @status: exit status
  * @args: number of arguments
  * @argv: arguments passed
  * Return: void
  */
void shell_exit(int status, int args, char **argv)
{
	if (args != 2)
	{
		write(2, "Incorrect number of arguments was passed\n", 41);
		status = 0;
	}
	else
		status = _atoi(argv[1]);

	exit(status);
}
