#include "sort.h"

/**
 * swap_nodes - swaps the positions of two nodes in a doubly linked list
 * @head: pointer to the pointer of the head of the list
 * @node1: pointer to the first node to swap
 * @node2: pointer to the second node to swap
 */
void swap_nodes(listint_t **head, listint_t *node1, listint_t *node2)
{
	listint_t *prev, *next;

	prev = node1->prev;
	next = node2->next;

	if (prev != NULL)
		prev->next = node2;
	else
		*head = node2;
	node1->prev = node2;
	node1->next = next;
	node2->prev = prev;
	node2->next = node1;
	if (next != NULL)
		next->prev = node1;
}

/**
 * cocktail_sort_list - sorts a doubly linked list of integers in ascending
 *                      order using the Cocktail Sort algorithm
 * @list: pointer to the pointer of the head of the list
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *head;
	int flag = 0;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	do {
		for (head = *list; head->next != NULL; head = head->next)
		{
			if (head->n > head->next->n)
			{
				swap_nodes(list, head, head->next);
				print_list(*list);
				flag = 1;
				head = head->prev;
			}
		}
		if (flag == 0)
			break;
		flag = 0;
		for (; head->prev != NULL; head = head->prev)
		{
			if (head->n < head->prev->n)
			{
				swap_nodes(list, head->prev, head);
				print_list(*list);
				flag = 1;
				head = head->next;
			}
		}
	} while (flag == 1);
}
