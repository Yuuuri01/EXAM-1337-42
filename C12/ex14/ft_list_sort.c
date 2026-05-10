# include "ft_list.h"



// int cmp(void *a, void *b)
// {
//     return (*(int *)a - *(int *)b);
// }
void ft_list_sort(t_list **begin_list, int (*cmp)())
{
    t_list *curr;
    void *tmp;
    int access = 1;
    if(!begin_list || !*begin_list || !cmp)
        return ;

    while(access)
    {
        access = 0;
        curr = *begin_list; // 7 1 2 3 
        while(curr->next) // A B C D // 7 1 5 2 // 1 5 2 7 // 1 2 5 7
        {
            if(cmp(curr->data, curr->next->data) > 0)
            {
                tmp = curr->data;
                curr->data = curr->next->data;
                curr->next->data = tmp;
                access = 1;
            }
            curr = curr->next;
        }
    }
}
