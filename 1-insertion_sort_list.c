#include "sort.h"

/**
 * swap - swaps numbers in the array
 * @ptr1: pointer to a node
 * @ptr2: pointer to a node
 * Return: pointer to the current node
 */

listint_t *swap(listint_t **ptr1, listint_t **ptr2)
{
    listint_t *tmpVar;

    tmpVar = (*ptr1)->next;
    if (*ptr2 != NULL)
    {
        (*ptr2)->next = tmpVar;
    }
    if (tmpVar != NULL)
    {
        tmpVar->prev = *ptr2;
    }
    if (*ptr1 != NULL)
    {
        (*ptr1)->next = *ptr2;
        (*ptr1)->prev = (*ptr2)->prev;
    }
    if ((*ptr2)->prev != NULL)
    {
        (*ptr2)->prev->next = *ptr1;
    }
    ((*ptr2)->prev) = *ptr1;
    return (*ptr1);
}

/**
 * insertion_sort_list - sorts a doubly linked list of
 * integers in ascending order
 * @list: doubly linked list
 */

void insertion_sort_list(listint_t **list)
{
    listint_t *ptr1;
    listint_t *ptr2;


    if (list == NULL || *list == NULL || (*list)->next == NULL)
        return;

    ptr2 = *list;
    ptr1 = (*list)->next;

    while (ptr1 != NULL)
    {
        if (ptr2 != NULL &&  ptr1->n < ptr2->n)
        {

            ptr1 = swap(&ptr1, &ptr2);
            ptr2 = ptr1->prev;
            if (ptr2 == NULL)
                *list = ptr1;
            print_list(*list);

            while (ptr2 != NULL && ptr1->n < ptr2->n)
            {
                ptr1 = swap(&ptr1, &ptr2);
                ptr2 = ptr1->prev;
                if (ptr2 == NULL)
                    *list = ptr1;
                print_list(*list);
            }
        }
        else
        {
            ptr2 = ptr1;
            ptr1 = ptr2->next;
        }
    }
}
