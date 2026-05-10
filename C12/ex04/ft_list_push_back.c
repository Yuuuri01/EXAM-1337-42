# include "ft_list.h"


t_list *ft_create_elm(void *data)
{
    t_list *new;
    new = malloc(sizeof(t_list));
    if(!new)
        return NULL;

    new->data = data;
    new->next = NULL;
    return new;   
}
void ft_list_push_back(t_list **begin_list, void *data)
{
    t_list *last;
    t_list *node;
    
    if(!begin_list)
        return;
    last = ft_create_elm(data);    
    if(!*begin_list)
    {
        *begin_list = last;
        return;
    }

    node = *begin_list;
    while(node->next)
    {
        node = node->next;
    }
    node->next = last;
}
