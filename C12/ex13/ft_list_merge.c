# include "ft_list.h"


void ft_list_merge(t_list **begin_list1, t_list *begin_list2)
{
    t_list *trave1;

    if(!begin_list1 || !begin_list2)
        return;
    if(!*begin_list1)
    {
        *begin_list1 = begin_list2;
        return;
    }
    trave1 = *begin_list1;
    while(trave1->next)
        trave1 = trave1->next;

    trave1->next = begin_list2;
}