# include "ft_list.h"


// int cmp(int *a, int *b)
// {
//     return (*a - *b);
// }
void ft_sorted_list_merge(t_list **begin_list1, t_list *begin_list2, int (*cmp)())
{
    t_list *new_head;
    t_list *trav;
    t_list *curr1;
    t_list *curr2;

    if(!begin_list1 || !begin_list2 || !cmp)
        return;
    if(!*begin_list1)
    {
        *begin_list1 = begin_list2;
        return;
    }

    trav = NULL;
    new_head = NULL;
    curr1 = *begin_list1;
    curr2 = begin_list2;
    
    while(curr1 && curr2)
    {
        if(cmp(curr1->data, curr2->data) > 0)
        {
            if(!new_head)
            {
                new_head = curr2;
                trav = new_head;
            }
            else
            {
                trav->next = curr2;
                trav = trav->next;
            }
            curr2 = curr2->next;
        }
        else
        {
            if(!new_head)
            {
                new_head = curr1;
                trav = new_head;
            }
            else
            {
                trav->next = curr1;
                trav = trav->next;
            }
            curr1 = curr1->next;
        }
    }
    if(trav)
        trav->next = (curr1) ? curr1 : curr2;
    *begin_list1 = new_head;
}
// void print_list(t_list *head)
// {
//     if(!head) return;
//     printf("%d ", *(int *)head->data);
//     print_list(head->next);
// }
// int main()
// {
//     t_list *head1;
//     t_list *head2;

//     t_list *node1 = malloc(sizeof(t_list));
//     t_list *node2 = malloc(sizeof(t_list));
//     t_list *node3 = malloc(sizeof(t_list));

//     t_list *node4 = malloc(sizeof(t_list));
//     t_list *node5 = malloc(sizeof(t_list));
//     t_list *node6 = malloc(sizeof(t_list));

//     int a = 6;
//     int b = 7;
//     int c = 8;

//     int d = 1;
//     int e = 2;
//     int f = 3;

//     head1 = node1;
//     node1->data = &a;
//     node1->next = node2;

//     node2->data = &b;
//     node2->next = node3;

//     node3->data = &c;
//     node3->next = NULL;

//     //////////////////
//     head2 = node4;
//     node4->data = &d;
//     node4->next = node5;

//     node5->data = &e;
//     node5->next = node6;

//     node6->data = &f;
//     node6->next = NULL;

//     print_list(head1);
//     print_list(head2);
//     printf("\n-------\n");
//     ft_sorted_list_merge(&head1, head2, cmp);
//     print_list(head1);
//     printf("\n");
// }