#ifndef _MAIN_
#define _MAIN__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>

extern char **environ;

typedef struct list_s
{
	char *str;
	struct list_s *next;
} list_t;

typedef struct shdata_s
{
	char **args;
	list_t *sh_env;
	int ps_count;
	int status;
	int pid;
	int setenv_flag;
} shdata_t;


typedef struct builtin_func_s
{
	char *name;
	int (*func)(shdata_t *);
} builtin_funcs_t;

/* string functions */
int _strlen(char *);
int _strcmp(char *, char *);
char *_strdup(const char *);
char *_strcat(char *str1, const char *str2);
char *_strchr(const char *s, char c);
char *_strtok(char *str, const char *delim);
char *strcat_alloc(char *, char *);
char **split_string(const char *str, const char *delimiter);
int _atoi(char *);
char *itos(unsigned int );

/* built-in functions */
int (*get_builtin(shdata_t *))(shdata_t *);
int builtin_exit(shdata_t *data);
int builtin_env(shdata_t *data);
int builtin_cd(shdata_t *data);
int builtin_setenv(shdata_t *data);
int builtin_unsetenv(shdata_t *data);

/* list manegment */
void free_list(list_t **head);
char **list_to_array(list_t *);
list_t *add_node_end(list_t **, char *);
int delete_node_at_index(list_t **head, unsigned int index);
list_t *insert_node(list_t **head, unsigned int idx, char * string);


int execute(shdata_t *);
int search_array(char *, char **);
char *_getenv(const char *, char **);
char *check_exe(char *, list_t *);
void print_path(void);
void print_list(list_t *);
list_t *path_list();
ssize_t _getline(char **lineptr, size_t *n, FILE *stream);
void shell_exit(int status, int args, char **argv);
void run_shell(shdata_t *);
int fill_shdata(shdata_t *, char **);
void signal_handler();
void prompt();
char **check_symbols(char *, shdata_t *);
char *expand(char *, int *, char, shdata_t *);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
int read_script(shdata_t *);
int non_interactive(shdata_t *);

#endif
