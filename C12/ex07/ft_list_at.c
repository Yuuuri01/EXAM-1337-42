# include "ft_list.h"


t_list *ft_list_at(t_list *begin_list, unsigned int nbr)
{
    t_list *trave;
    unsigned int i;
    if(!begin_list)
        return NULL;

    trave = begin_list;
    i = 0;
    while(trave)
    {
        if(i == nbr)
            return trave;
        trave = trave->next;
        i++;
    }
    return NULL;
}