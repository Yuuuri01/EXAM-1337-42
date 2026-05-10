# include "ft_list.h"


void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)(), void (*free_fct)(void *))
{
    t_list *prev;
    t_list *next;
    t_list *curr;

    if(!begin_list || !*begin_list)
        return;
    curr = *begin_list;
    prev = NULL;
    while(curr)
    {
        next = curr->next;
        if(cmp(curr->data, data_ref) == 0)
        {
            if(prev == NULL)//if first node->data == data_ref
                *begin_list = curr->next;//change head
            else
                prev->next = curr->next;//link prev with next
            free_fct(curr->data);
            free(curr);
        }
        else
            prev = curr;
        curr = next;
    }
}