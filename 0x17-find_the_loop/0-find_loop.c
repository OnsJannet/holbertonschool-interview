#include "lists.h"

/**
* find_listint_loop - Finds a loop in a linked list
*
* @head: Head of list
*
* Return: The address of the node where the loop starts,
* or NULL if there is no loop
*/

listint_t *find_listint_loop(listint_t *head)
{
	listint_t *first = head, *second = head;

	while (first && second && second->next)
	{
		first = first->next;
		second = second->next->next;

		if (first == second)
		{
			first = head;

			while (first != second)
			{

				first = first->next;
				second = second->next;
			}
			return (first);
		}
	}
	return (NULL);
}
