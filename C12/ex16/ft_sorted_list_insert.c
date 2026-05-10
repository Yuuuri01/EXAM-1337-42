# include "ft_list.h"


t_list *ft_create_elem(void *data)
{
    t_list *new;

    new = malloc(sizeof(t_list));
    if(!new)
        return NULL;
    new->data = data;
    new->next = NULL;

    return new;
}
void ft_sorted_list_insert(t_list **begin_list, void *data, int (*cmp)())
{
    t_list *prev;
    t_list *curr;
    t_list *next;
    t_list *new;
    
    if(!begin_list || !cmp)
        return;
    if(!*begin_list)
    {
        new = ft_create_elem(data);
        new->next = *begin_list;
        *begin_list = new;
        return;
    }
    curr = *begin_list;
    if(cmp(data, curr->data) < 0)
    {
        new = ft_create_elem(data);
        new->next = curr;
        *begin_list = new;
        return;
    }
    prev = NULL;
    while(curr)
    {
        next = curr->next;
        if(cmp(curr->data, data) > 0)
        {
            new = ft_create_elem(data);
            prev->next = new;
            new->next = curr;
            return;
        }
        else if(!curr->next && cmp(data, curr->data) > 0)
        {
            new = ft_create_elem(data);
            curr->next = new;
            return;
        }
        else
            prev = curr;
        curr = next;
    }
}