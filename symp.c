#include "main.h"

/**
  * check_symbols - checks for ";" and "#".
  * @string: the string to check.
  * @data: shell data.
  *
  * Return: an array of commands.
 */
char **check_symbols(char *string, shdata_t *data)
{
	char **cmd_arr;
	int i = 0;

	while (string[i])
	{
		if (string[i] == '#')
		{
			string[i] = '\0';
			break;
		}
		else if (string[i] == '$')
		{
			switch (string[i + 1])
			{
				case '$':
					string = expand(string, &i, '$', data);
					break;
				case '?':
					string = expand(string, &i, '?', data);
					break;
				case ' ':
					break;
				default:
					string = expand(string, &i, 'v', data);
			}
		}
		i++;
	}
	cmd_arr = split_string(string, "\t\0\n;");
	return (cmd_arr);
}

/**
 * expand - expands a shell variable.
 * @string: the whole command (will be edited).
 * @i: the index of the expand specifier.
 * @to_expand: type of expantion.
 * @data: shell data.
 *
 * Return: the command after expantion.
 */
char *expand(char *string, int *i, char to_expand, shdata_t *data)
{
	char *before, *after, *new = "";
	char *var_name, *var_value;
	int length, j;

	before = _strdup(string);
	before[*i] = '\0';
	after = _strdup(string);
	after = after + *i;
	while (!(*after == ' ' || *after == '\0'))
		after++;
	new = strcat_alloc(new, before);
	switch (to_expand)
	{
		case '$':
			data->pid = getpid();
			new = strcat_alloc(new, itos(data->pid));
			new = strcat_alloc(new, after);
			(*i) += _strlen(itos(data->pid));
			break;
		case '?':
			new = strcat_alloc(new, itos(data->status));
			new = strcat_alloc(new, after);
			(*i) += _strlen(itos(data->status));
			break;
		case 'v':
			length = j = 0;
			while (string[*i + 1 + length] != ' ')
				length++;
			var_name = malloc(sizeof(char) * length + 1);
			while (j < length)
				var_name[j] = string[*i + 1 + j], j++;
			var_name[j] = '\0';
			var_value = _getenv(var_name, list_to_array(data->sh_env));
			if (var_value == NULL)
				var_value = "";
			new = strcat_alloc(new, var_value);
			new = strcat_alloc(new, after);
			i += _strlen(var_value);
	}

	free(before), free(after), free(var_name), free(var_value);
	return (new);
}
