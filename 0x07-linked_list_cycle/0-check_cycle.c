#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * check_cycle - Check if a singly linked list is a cycle
 * @list: The pointer to the list's head
 * Return: 0 if has no cycle, 1 if any other case
 */

int check_cycle(listint_t *list)
{
	listint_t *ptr_1 = list, *ptr_2 = list;

	while (ptr_1 && ptr_2 && ptr_2->next)
	{
		ptr_1 = ptr_1->next;
		ptr_2 = ptr_2->next->next;

		/* If ptr_1 and ptr_2 meet at some point then there is a loop */
		if (ptr_1 == ptr_2)
		{

			/* Return 1 to indicate that loop is found */
			return (1);
		}
	}

	/* Return 0 to indeciate that ther is no loop*/
	return (0);
}
