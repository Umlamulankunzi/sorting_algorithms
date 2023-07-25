#include "sort.h"



/**
 * swap_node - swaps given node with its previous node in doubly linked list
 * @node: node to swap with previous node
 * @list: pointer to pointer to head of the doubly linked list
 * Return: pointer to the node which was swapped
 */
listint_t *swap_node(listint_t *node, listint_t **list)
{
	/* Get pointers to the previous and current nodes */
	listint_t *prev_node = node->prev;
	listint_t *node_to_swap = node;

	/* Check if input node is the head */
	if (node == *list)
		return (node);

	/* Swap the nodes */
	prev_node->next = node_to_swap->next;
	if (node_to_swap->next)
		node_to_swap->next->prev = prev_node;
	node_to_swap->next = prev_node;
	node_to_swap->prev = prev_node->prev;
	prev_node->prev = node_to_swap;
	if (node_to_swap->prev)
		node_to_swap->prev->next = node_to_swap;
	else
		*list = node_to_swap;

	/* Return pointer to the swapped node */
	return (node_to_swap);
}



/**
 * insertion_sort_list - function that sorts a doubly linked list
 * of integers in ascending order using the Insertion sort algorithm
 * @list: Dobule linked list to sort
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *node;

	if (list == NULL || (*list)->next == NULL)
		return;

	node = (*list)->next;
	while (node)
	{
		while ((node->prev) && (node->prev->n > node->n))
		{
			node = swap_node(node, list);
			print_list(*list);
		}
		node = node->next;
	}
}
