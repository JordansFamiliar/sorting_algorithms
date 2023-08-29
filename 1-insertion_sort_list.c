#include "sort.h"

/**
 * insertion_sort_list - A function that sorts a doubly linked list of
 * integers in ascending order ising the Insertion sort algorithm.
 * @list: Pointer to the head of the doubly linked list
 * Return: void
 */
void insertion_sort_list(listint_t **list)
{
        listint_t *node = *list, *comp_node;

        while (node != NULL)
        {
                comp_node = node->prev;
                if (comp_node != NULL && node->n < comp_node->n)
                {
                        node->prev = comp_node->prev;
                        if (comp_node->prev != NULL)
                                comp_node->prev->next = node;
                        else
                                *list = node;
                        comp_node->next = node->next;
                        if (node->next != NULL)
                                node->next->prev = comp_node;
                        node->next = comp_node;
                        comp_node->prev = node;
                        print_list(*list);
                        node = *list;
                        continue;
                }
                node = node->next;
        }
}
