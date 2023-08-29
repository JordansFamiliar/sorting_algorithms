#include "sort.h"

/**
 * swap - a function that swaps two nodes of a doubly linked
 * list.
 * @list: pointer to a linked list.
 * @node: a pointer to a node.
 * @next: pointer to the next node.
 * Return: void.
 */
void swap(listint_t **list, listint_t **node, listint_t **next)
{
	if ((*next)->next != NULL)
		(*next)->next->prev = *node;
	if ((*node)->prev != NULL)
		(*node)->prev->next = *next;
	if ((*node)->prev == NULL)
		*list = *next;
	(*node)->next = (*next)->next;
	(*next)->prev = (*node)->prev;
	(*node)->prev = *next;
	(*next)->next = *node;
	print_list(*list);
}
/**
 * forward - a function that orders a linked list from
 * head to tail.
 * @list: pointer to a linked list
 * Return: 1 if a swap has been performed, otherwise 0.
 */
int forward(listint_t **list)
{
	listint_t *node, *next;
	int change = 0;

	node = *list;
	while (node->next != NULL)
	{
		next = node->next;
		if (node->n > next->n)
		{
			swap(list, &node, &next);
			change = 1;
		}
		node = next;
	}
	return (change);
}
/**
 * back - a function that sorts a linked list from
 * tail to head.
 * @list: a pointer to the head.
 * @node: a pointer to the end of the list.
 * Return: 1 if changed, 0 otherwise.
 */
int back(listint_t **list, listint_t *node)
{
	listint_t *prev;
	int change = 0;

	while (node->prev != NULL)
	{
		prev = node->prev;
		if (node->n < prev->n)
		{
			swap(list, &prev, &node);
			change = 1;
		}
		node = prev;
	}
	return (change);
}
/**
 * cocktail_sort_list - a function that sorts a doubly linked
 * list of integersin ascending order using the Cocktail
 * shaker sort algorithm.
 * @list: A pointer to the list
 * Return: void
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *node;
	int swapped = 0;

	if (*list == NULL || (*list)->next == NULL)
		return;
	while (1)
	{
		node = *list;
		swapped = forward(list);
		if (swapped == 0)
			break;
		while (node->next != NULL)
			node = node->next;
		swapped = back(list, node);
		if (swapped == 0)
			break;
	}
}
