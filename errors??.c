#include "main.h"

/**
  * print_errors - prints an error.
  * @data: shell data.
  *
  * Return: void.
  */
void print_errors(shdata_t *data)
{
	char *filename, *command, *massage;
	char *ps;
	int i, length;

	filename = _strdup(data->argvs[0]);
	command = _strdup(data->args[0]);
	ps = _strdup(itos(data->ps_count));

	i = length = 0;
	while (filename[i])
		i++, length++;
	i = 0;
	while (command[i])
		i++, length++;
	i = 0;
	while (ps[i])
		i++, length++;

	length += 16;

	massage = malloc(sizeof(char) * length + 1);
	massage = strcat(filename, ": ");
	massage = strcat(massage, ps);
	massage = strcat(massage, ": ");
	massage = strcat(massage, command);
	massage = strcat(massage, ": ");
	massage = strcat(massage, "not found\n");

	write(STDOUT_FILENO, massage, length);
}
