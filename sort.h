#ifndef SORT_H
#define SORT_H

#include <stdlib.h>


/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;


void bubble_sort(int *array, size_t size);
void print_array(const int *array, size_t size);
void print_list(const listint_t *list);
void insertion_sort_list(listint_t **list);
listint_t *swap_node(listint_t *node, listint_t **list);
void selection_sort(int *array, size_t size);
void quicksort(int *array, ssize_t first, ssize_t last, size_t size);
void quick_sort(int *array, size_t size);
ssize_t lomuto_partition(int *array, ssize_t first, ssize_t last, size_t size);
void swap_ints(int *array, ssize_t index1, ssize_t index2);
void swap_elements(int *array, int index1, int index2);
void shell_sort(int *array, size_t size);
void swap_nodes(listint_t **head, listint_t *node1, listint_t *node2);
void cocktail_sort_list(listint_t **list);
void counting_sort(int *array, size_t size);

#endif  /* SORT_H */
