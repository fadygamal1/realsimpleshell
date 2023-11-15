#include "main.h"

/**
 * non_interactive - short description.
 * @data: data
 * Return: 0 on success or -1 on failure
 */
int non_interactive(shdata_t *data)
{
	char *lineptr = NULL;
	size_t n = 0;
	int count;
	int (*func)(shdata_t *);
	char **cmd_arr;

	while (getline(&lineptr, &n, stdin) != -1)
	{
		if (*lineptr == '\n' && !*(lineptr + 1))
			return (0);
		cmd_arr = check_symbols(lineptr, data);
		count = 0;
		while (cmd_arr[count])
		{
			data->args = split_string(cmd_arr[count], "\n ");
			func = get_builtin(data);
			if (func != NULL)
			{
				data->status = 0;
				if (data->args[1])
					data->status = atoi(data->args[1]);
				func(data);
				data->ps_count++;
				count++;
			}
			execute(data);
			count++;
			data->ps_count++;
		}
	}
	return (0);
}
/**
 * run_shell - runs the prompt loop.
 * @data: data of the shell.
 *
 * Return: void.
 */
void run_shell(shdata_t *data)
{
	char *lineptr = NULL;
	size_t n = 0;
	int count;
	int (*func)(shdata_t *);
	char **cmd_arr;

	signal(SIGINT, signal_handler);

	while (1)
	{
		prompt();
		if (getline(&lineptr, &n, stdin) == -1)
			break;
		if (*lineptr == '\n' && !*(lineptr + 1))
			continue;
		cmd_arr = check_symbols(lineptr, data);
		count = 0;
		while (cmd_arr[count])
		{
			data->args = split_string(cmd_arr[count], "\n ");
			func = get_builtin(data);
			if (func != NULL)
			{
				data->status = 0;
				if (data->args[1])
					data->status = atoi(data->args[1]);
				func(data);
				data->ps_count++;
				count++;
				continue;
			}
			execute(data);
			count++;
			data->ps_count++;
		}
	}

	data->ps_count++;
	free(lineptr);
}
