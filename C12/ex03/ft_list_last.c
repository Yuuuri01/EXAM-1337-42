# include "ft_list.h"


t_list *ft_list_last(t_list *begin_list)
{
    if(!begin_list)
        return NULL;
    while(begin_list->next)
        begin_list = begin_list->next;

    return begin_list;
}
// void print_list(t_list *begine)
// {
//     while(begine)
//     {
//         printf("%d ", *(int *)begine->data);
//         begine = begine->next;
//     }
//     printf("\n");
// }
// int main()
// {
//     t_list *head;
//     t_list *node1 = malloc(sizeof(t_list));
//     t_list *node2 = malloc(sizeof(t_list));
//     t_list *node3 = malloc(sizeof(t_list));
//     if(!node1 || !node2 || !node3)
//         return 0;

//     int a = 20;
//     int b = 40;
//     int c = 42;
    
//     node1->data = &a;
//     node1->next = node2;

//     node2->data = &b;
//     node2->next = node3;

//     node3->data = &c;
//     node3->next = NULL;

//     head = node1;
//     t_list *lst = ft_list_last(head);
//     print_list(lst);

// }