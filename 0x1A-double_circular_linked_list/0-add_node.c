#include <stdio.h>
#include <stdlib.h>
#include "list.h"



/**
 * *add_node_end - adds a new node at the beginning of a DCLL
 *
 * @list: A pointer to the head of the linkd list
 * @str: the string to copy into the new node
 *
 * Return: Address of the new node, or NULL on failure
 */

List *add_node_begin(List **list, char *str)
{
	List *added_node, *previous_node;

	if (!list)
		return (NULL);

	if (!str)
		return (NULL);

	added_node = malloc(sizeof(List));
	if (!added_node)
		return (NULL);

	added_node->str = strdup(str);
	if (!added_node->str)
	{
		free(added_node);
		return (NULL);
	}

	if (*list == NULL)
	{
		added_node->next = added_node->prev = added_node;
		*list = added_node;
		return (added_node);
	}

	previous_node = (*list)->prev;

	added_node->next = (*list);
	added_node->prev = previous_node;
	(*list)->prev = previous_node->next = added_node;
	*list = added_node;

	return (added_node);
}

/**
 * *add_node_end - adds a new node at the end of a double circular linked list
 *
 * @list: A pointer to the head of the linkd list
 * @str: the string to copy into the new node
 *
 * Return: Address of the new node, or NULL on failure
 */

List *add_node_end(List **list, char *str)
{
	List *added_node, *previous_node;

	if (!list)
		return (NULL);

	if (!str)
		return (NULL);

	added_node = malloc(sizeof(List));
	if (!added_node)
		return (NULL);

	added_node->str = strdup(str);
	if (!added_node->str)
	{
		free(added_node);
		return (NULL);
	}

	if (*list == NULL)
	{
		added_node->next = added_node->prev = added_node;
		*list = added_node;
		return (added_node);
	}

	previous_node = (*list)->prev;

	previous_node->next = added_node;
	added_node->next = *list;
	added_node->prev = previous_node;
	(*list)->prev = added_node;
	return (added_node);
}
