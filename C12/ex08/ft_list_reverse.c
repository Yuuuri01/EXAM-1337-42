# include "ft_list.h"
# include <stdio.h>

void ft_list_reverse(t_list **begin_list)
{
    t_list *curr;
    t_list *next;
    t_list *prev;

    prev = NULL;
    curr = *begin_list;
    while(curr)//A -> B -> C -> NULL
    {
        next = curr->next;// B / C / NULL
        curr->next = prev; // A-NULL-B-C-NULL | B-A-NULL+C-NULL | C-B-A-NULL
        prev = curr; // A -> B -> C
        curr = next;
    }
    *begin_list = prev;
}
void print_list(t_list *nd)
{
    while(nd)
    {
        printf("%d\n", *(int *)nd->data);
        nd = nd->next;
    }
}
int main()
{
    t_list *head;

    t_list *node1 = malloc(sizeof(t_list));
    t_list *node2 = malloc(sizeof(t_list));
    t_list *node3 = malloc(sizeof(t_list));

    int a = 10;
    int b = 20;
    int c = 42;

    node1->data = &a;
    node1->next = node2;

    node2->data = &b;
    node2->next = node3;

    node3->data = &c;
    node3->next = NULL;

    head = node1;
    print_list(head);
    printf("--reverse----\n");
    ft_list_reverse(&head);
    print_list(head);
}