#include "sort.h"

/**
 * swap - swaps nodes in a list
 *
 * @m: first node
 * @n: second node
 *
 * Return: 0
 */

void swap(listint_t *m, listint_t *n)
{
	if (m->prev)
		m->prev->next = n;
	if (n->next)
		n->next->prev = m;
	m->next = n->next;
	n->prev = m->prev;
	m->prev = n;
	n->next = m;
}


/**
 * insertion_sort_list - sorts a doubly linked list of
 * integers in ascending order using the Insertion sort algorithm
 *
 * @list: a linked list
*/
void insertion_sort_list(listint_t **list)
{
	listint_t *i, *j;

	if (!list || !*list)
		return;
	i = (*list)->next;
	while (i)
	{
		j = i;
		i = i->next;
		while (j && j->prev)
		{
			if (j->prev->n > j->n)
			{
				swap(j->prev, j);
				if (!j->prev)
					*list = j;
				print_list((listint_t *)*list);
			}
			else
				j = j->prev;
		}
	}
}
