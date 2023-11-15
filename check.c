#include "main.h"
#include <sys/stat.h>

/**
 * check_exe - checks if an executable exists in PATH.
 * @filename: the name of the executable.
 * @env: environment variable
 * Return: the absolute path of the executable or NULL
 * if it doesn't exist.
 */
char *check_exe(char *filename, list_t *env)
{
	char **path_dirs;
	char *path, *tmp;
	int i;
	struct stat st;

	if (!stat(filename, &st))
		return (filename);

	path = _getenv("PATH", list_to_array(env));
	path_dirs = split_string(path, ":");

	i = 0;
	while (path_dirs[i])
	{
		tmp = _strdup(path_dirs[i]);
		tmp = strcat(tmp, "/");
		tmp = strcat(tmp, filename);
		if (!stat(tmp, &st))
		{
			return (tmp);
		}
		i++;
	}
	free(tmp);
	return (NULL);
}
