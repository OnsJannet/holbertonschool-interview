#include "lists.h"

/**
 * recursive_palindrome- checks if a singly linked list is a palindrome.
 *
 * @left: left side
 * @right: right side
 * Return: 0 if it is not a palindrome 1 if it is a palindrome.
 */

int recursive_palindrome(listint_t **left, listint_t *right)

{


	if (right == NULL)
		return (1);


	int ispalindrome = recursive_palindrome(left, right->next) &&
	(right->n == (*left)->n);

	if (ispalindrome == 0)
		return (0);




	*left = (*left)->next;

	return (ispalindrome);
}

/**
 * is_palindrome - checks if a singly linked list is a palindrome.
 * @head: Double pointer to head of list
 * Return: 0 if it is not a palindrome 1 if it is a palindrome.
 */

int is_palindrome(listint_t **head)
{
	return (recursive_palindrome(head, *head));

}
