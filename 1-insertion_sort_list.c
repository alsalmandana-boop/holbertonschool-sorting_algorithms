 #include "sort.h"

/**
 * swap_nodes - Swaps two adjacent nodes in a doubly linked list
 * @list: Pointer to the head of the doubly linked list
 * @node1: Pointer to the first node to swap
 * @node2: Pointer to the second node to swap
 */
void swap_nodes(listint_t **list, listint_t *node1, listint_t *node2)
{
	node1->next = node2->next;
	if (node2->next)
		node2->next->prev = node1;

	node2->prev = node1->prev;
	if (node1->prev)
		node1->prev->next = node2;
	else
		*list = node2;

	node1->prev = node2;
	node2->next = node1;
}

/**
 * insertion_sort_list - Sorts a doubly linked list of integers in ascending
 *                       order using Insertion sort.
 * @list: Double pointer to the head of the list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *insert;

	if (!list || !*list || !(*list)->next)
		return;

	current = (*list)->next;
	while (current)
	{
		insert = current;
		current = current->next;
		while (insert->prev && insert->n < insert->prev->n)
		{
			swap_nodes(list, insert->prev, insert);
			print_list(*list);
		}
	}
}
