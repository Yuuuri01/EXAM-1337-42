# include "ft_list.h"



// [1][-->] [2][-->] [3][-->] [4][-->] [5][-->] [6][NULL]
int get_len(t_list *node)
{
    t_list *curr;

    curr = node;
    int len = 0;
    while(curr)
    {
        curr = curr->next;
        len++;
    }
    return len;
}
void ft_list_reverse_fun(t_list *begin_list)
{
    t_list *curr;
    curr = begin_list;
    int len = get_len(curr);
    t_list *arr[len];
    int i;

    curr = begin_list;
    i = 0;
    while(curr)
    {
        arr[i++] = curr;
        curr = curr->next;
    }

    void *tmp;
    int left = 0;
    int right = len - 1;
    while(left < right)
    {
        tmp = arr[left]->data;
        arr[left]->data = arr[right]->data;
        arr[right]->data = tmp;

        left++;
        right--;
    }
}
// void print_list(t_list *prev)
// {
//     if(prev == NULL)
//         return;

//     printf("%d ", *(int *)prev->data);
//     print_list(prev->next);
// }
// int main()
// {
//     t_list *head;

//     t_list *node1 = malloc(sizeof(t_list));
//     t_list *node2 = malloc(sizeof(t_list));
//     t_list *node3 = malloc(sizeof(t_list));
//     t_list *node4 = malloc(sizeof(t_list));
//     t_list *node5 = malloc(sizeof(t_list));
//     t_list *node6 = malloc(sizeof(t_list));

//     int a = 1;
//     int b = 2;
//     int c = 3;
//     int d = 4;
//     int e = 5;
//     int f = 6;

//     node1->data = &a;
//     node1->next = node2;

//     node2->data = &b;
//     node2->next = node3;

//     node3->data = &c;
//     node3->next = node4;

//     node4->data = &d;
//     node4->next = node5;

//     node5->data = &e;
//     node5->next = node6;

//     node6->data = &f;
//     node6->next = NULL;

//     head = node1;

//     printf("before\n");
//     print_list(head);
//     ft_list_reverse_fun(head);
//     printf("\nafter\n");
//     print_list(head);
//     printf("\n");
// }