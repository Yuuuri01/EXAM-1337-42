# include "ft_list.h"
# include <stdio.h>


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
void print_list(t_list *mlawi)
{
    while (mlawi)
    {
        printf("%d ", *(int *)mlawi->data);
        mlawi = mlawi->next;
    }
    printf("\n");
}
int main()
{
    t_list *head;

    t_list *node1 = malloc(sizeof(t_list));
    t_list *node2 = malloc(sizeof(t_list));

    int a = 100;
    int b = 232;
    int c = 4242;
    head = node1;

    node1->data = &a;
    node1->next = node2;

    node2->data = &b;
    node2->next = NULL;

    ft_list_push_back(&head, &c);
    print_list(head);
}