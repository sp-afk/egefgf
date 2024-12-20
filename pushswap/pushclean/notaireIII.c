#include "psutiles.h"


int cmpt_small(t_dlist *list)
{

    int min = list->data;
    int index = 0;
    int min_index = 0;
    t_dlist *current = list;

    while (current)
    {
        if (current->data < min)
        {
            min = current->data;
            min_index = index;
        }
        current = current->next;
        index++;
    }

    return min_index;
}

int cmpt_big(t_dlist *list)
{
    int max = list->data;
    int index = 0;
    int max_index = 0;
    t_dlist *current = list;

    while (current)
    {
        if (current->data > max)
        {
            max = current->data;
            max_index = index;
        }
        current = current->next;
        index++;
    }

    return max_index;
}

int small(t_dlist *list)
{
    int min = list->data;
    int index = 0;
    t_dlist *current = list;

    while (current)
    {
        if (current->data < min)
        {
            min = current->data;
        }
        current = current->next;
        index++;
    }

    return min;
}

int big(t_dlist *list)
{
    int max = list->data;
    int index = 0;
    t_dlist *current = list;

    while (current)
    {
        if (current->data > max)
        {
            max = current->data;
        }
        current = current->next;
        index++;
    }

    return max;
}
