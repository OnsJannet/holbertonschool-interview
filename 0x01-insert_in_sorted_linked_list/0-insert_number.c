#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * insert_node - insert node into position
 * @head: head of linked list
 * @number: value
 * Return: Pointer to the new node
 */

listint_t *insert_node(listint_t **head, int number)
{
	listint_t *current;
	listint_t *newNode;

	newNode = malloc(sizeof(*newNode));
	if (!newNode)
		return (NULL);
	newNode->n = number;

	/* special case for the head end*/
	if (*head == NULL || (*head)->n >= newNode->n)
	{
		newNode->next = *head;
		*head = newNode;
		return (newNode);
	}

	/* locate the node before the point of insertion*/
	for (current = *head; current != NULL; current = current->next)
	{
		if (current->next == NULL || current->next->n > newNode->n)
		{

			newNode->next = current->next;
			current->next = newNode;
			break;
		}
	}

	return (newNode);
}
