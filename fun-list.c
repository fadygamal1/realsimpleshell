#include "main.h"

char **list_to_array(list_t *head);
/**
  * add_node_end - adds a node to the end of a nexted list.
  * @head : a pointer to the head pointer.
  * @str: the string to add.
  *
  * Return: the new list after update.
  */
list_t *add_node_end(list_t **head, char *str)
{
	list_t *new, *temp;

	new = malloc(sizeof(list_t));
	if (!new)
		return (NULL);

	new->str = _strdup(str);
	if (!new->str)
	{
		free(new);
		return (NULL);
	}
	new->next = NULL;

	temp = *head;
	if (!temp)
	{
		*head = new;
	}
	else
	{
		while (temp->next)
			temp = temp->next;
		temp->next = new;
	}

	return (*head);
}


/**
 * delete_node_at_index - deletes a node at a certain position.
 *
 * @head: the head pointer.
 * @index: the index to delete from.
 * Return: 1 if succeded and 0 if not.
 */
int delete_node_at_index(list_t **head, unsigned int index)
{
	list_t *ptr, *ptr2;

	ptr = ptr2 = *head;
	if (ptr == NULL)
		return (-1);

	if (index == 0)
	{
		*head = (*head)->next;
		free(ptr->str);
		free(ptr);
		ptr = ptr2 = NULL;
		return (1);
	}
	else
	{
		while (index)
		{
			if (!ptr2)
				return (-1);
			ptr = ptr2;
			ptr2 = ptr2->next;
			index--;
		}
		ptr->next = ptr2->next;
		free(ptr2->str);
		free(ptr2);
		ptr2 = NULL;
	}
	return (1);
}


/**
 * insert_node - inserts a node at a certain position.
 * @head: the head pointer.
 * @idx: the index to insert at.
 * @string: the inserted node data.
 *
 * Return: a pointer to the inserted node.
 */
list_t *insert_node(list_t **head, unsigned int idx, char *string)
{
	unsigned int i;
	list_t *ptr, *new;

	ptr = *head;

	if (idx != 0)
	{
		for (i = 0; i < idx - 1 && ptr != NULL; i++)
			ptr = ptr->next;
	}

	if (ptr == NULL && idx != 0)
		return (NULL);

	new = malloc(sizeof(list_t));
	if (!new)
		return (NULL);

	new->str = _strdup(string);
	if (!new->str)
	{
		free(new);
		return (NULL);
	}
	new->next = NULL;

	if (idx == 0)
	{
		new->next = *head;
		*head = new;
	}
	else
	{
		new->next = ptr->next;
		ptr->next = new;
	}

	return (new);
}


/**
  * list_to_array - fills an array with a list contnets.
  * @head: the list head.
  *
  * Return: the filled array.
  */
char **list_to_array(list_t *head)
{
	char **arr;
	list_t *tmp;
	int i, j;

	tmp = head;
	i = 0;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}

	arr = malloc(sizeof(char *) * (i + 1));

	i = 0;
	tmp = head;
	while (tmp)
	{
		arr[i] = _strdup(tmp->str);
		if (arr[i] == NULL)
		{
			j = 0;
			while (j < i)
			{
				free(arr[j]);
				j++;
			}
			free(arr);
			return (NULL);
		}
		tmp = tmp->next;
		i++;
	}

	arr[i] = NULL;

	/*
	* j = 0;
	* while (j < i)
	* {
	*	free(arr[j]);
	*	j++;
	* }
	* free(arr);
	*/

	return (arr);
}


/**
 * free_list - frees a list.
 *
 * @head: the head pointer.
 * Return: Nothing.
 */
void free_list(list_t **head)
{
	list_t *current;
	list_t *temp;

	if (*head != NULL)
	{
		current = *head;
		while ((temp = current) != NULL)
		{
			current = current->next;
			free(temp->str);
			free(temp);
		}
		*head = NULL;
	}
}
