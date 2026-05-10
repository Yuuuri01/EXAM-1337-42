# include "ft_list.h"


t_list *create_elm(void *data)
{
    t_list *new;
    new = malloc(sizeof(t_list));
    if(!new)
        return NULL;
    new->data = (char *)data;
    new->next = NULL;
    return new;
}
void push_back(t_list **head, void *data)
{
    t_list *trave;
    t_list *new;

    new = create_elm(data);
    if(!*head)
    {
        *head = new;
        return;
    }
    trave = *head;
    while(trave->next)
    {
        trave = trave->next;
    }
    trave->next = new;
}
t_list *ft_list_push_strs(int size, char **strs)
{
    t_list *head;
    int i;

    head = NULL;
    i = 1;
    while(i < size)
    {
        push_back(&head, strs[i]);
        i++;
    }
    push_back(&head, strs[0]);
    return head;
}