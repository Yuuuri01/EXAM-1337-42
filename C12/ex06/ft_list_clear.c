# include <stdio.h>
# include "ft_list.h"


// char *ft_strdup(char *str)
// {
//     int len = 0;
//     char *send;

//     while(str[len]) len++;

//     char *new = malloc((len + 1) * sizeof(char));
//     if(!new)
//         return NULL;

//     send = new;
//     while(*str)
//     {
//         *new = *str;
//         new++;
//         str++;
//     }
//     *new = '\0';
//     return send;
// }
// void free_fct(void *data)
// {
//     free(data);
// }
void ft_list_clear(t_list *begin_list, void (*free_fct)(void *))
{
    t_list *trave;
    if(!begin_list)
        return;
    trave = begin_list;
    while(begin_list)
    {
        trave = begin_list;
        begin_list = begin_list->next;
        free_fct(trave->data);
        free(trave);
    }
}