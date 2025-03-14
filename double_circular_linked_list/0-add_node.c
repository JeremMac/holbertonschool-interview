#include "list.h"
#include <string.h>

/**
 * add_node_end - Adds a new node at the end of a double circular linked list
 * @list: A pointer to the head of the list
 * @str: The string to copy into the new node
 *
 * Return: The address of the new node, or NULL on failure
 */
List *add_node_end(List **list, char *str)
{
	List *new_node;
	List *tail;

	new_node = malloc(sizeof(List));
	if (!new_node)
		return (NULL);

	new_node->str = strdup(str);
	if (!new_node->str)
	{
		free(new_node);
		return (NULL);
	}

	if (*list == NULL)
	{
		new_node->next = new_node;
		new_node->prev = new_node;
		*list = new_node;
	}
	else
	{
		tail = (*list)->prev;
		tail->next = new_node;
		new_node->prev = tail;
		new_node->next = *list;
		(*list)->prev = new_node;
	}
	return (new_node);
}

/**
 * add_node_begin - Adds a new node at the beginning of
 * a double circular linked list
 * @list: A pointer to the head of the list
 * @str: The string to copy into the new node
 *
 * Return: The address of the new node, or NULL on failure
 */
List *add_node_begin(List **list, char *str)
{
	List *new_node;

	new_node = malloc(sizeof(List));
	if (!new_node)
		return (NULL);

	new_node->str = strdup(str);
	if (!new_node->str)
	{
		free(new_node);
		return (NULL);
	}

	if (*list == NULL)
	{
		new_node->next = new_node;
		new_node->prev = new_node;
		*list = new_node;
	}
	else
	{
		new_node->next = *list;
		new_node->prev = (*list)->prev;
		(*list)->prev->next = new_node;
		(*list)->prev = new_node;
		*list = new_node;
	}
	return (new_node);
}
