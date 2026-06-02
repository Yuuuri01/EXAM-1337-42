# include "list.h"
# include <stdio.h>
# include <stdlib.h>

int        cycle_detector(const t_list *list)
{
    t_list *slow;
    t_list *fast;
    
    if(!list)
        return 0;
    slow = (t_list *)list;
    fast = (t_list *)list->next;


    while(fast && fast->next)
    {
        if(fast == slow)
            return 1;
        fast = fast->next->next;
        slow = slow->next;
    }
    return 0;
}
int main()
{
    t_list *head;

    t_list *node1 = malloc(sizeof(t_list));
    t_list *node2 = malloc(sizeof(t_list));
    t_list *node3 = malloc(sizeof(t_list));
    
    int a = 10;
    int b = 20;
    int c = 30;

    node1->data = a;
    node1->next = node2;

    node2->data = b;
    node2->next = node3;

    node3->data = c;
    node3->next = node1;

    head = node1;

    if(cycle_detector(head))
        printf("is cycle\n");
    else
        printf("not cycle\n");
}