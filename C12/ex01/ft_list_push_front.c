# include "ft_list.h"
# include <stdio.h>

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
void ft_list_push_front(t_list **begin_list, void *data)
{
    t_list *new;

    if(!begin_list)
        return;

    new =  ft_create_elem(data);
    if(!new)
        return;
    new->next = *begin_list;

    *begin_list = new;
}
// void print(t_list *boobs)
// {
//     while(boobs)
//     {
//         printf("%d ", *(int *)boobs->data);
//         boobs = boobs->next;
//     }
//     printf("\n");
// }
// int main()
// {
//     t_list *head = NULL;

//     t_list *node1 = malloc(sizeof(t_list));
//     t_list *node2 = malloc(sizeof(t_list));

//     int a = 10;
//     int b = 20;
//     int c = 42;

//     head = node1;
//     node1->data = &a;
//     node1->next = node2;

//     node2->data = &b;
//     node2->next = NULL;

//     ft_list_push_front(&head, &c);
//     print(head);

//     t_list *new;
//     while(head)
//     {
//         new = head;
//         head = head->next;
//         free(new);
//     }
// }