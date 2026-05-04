# include <unistd.h>

void swap(char **s1, char **s2)
{
    char *tmp;

    tmp = *s1;
    *s1 = *s2;
    *s2 = tmp;
}
int ft_strcump(char *s1, char *s2)
{
    while(*s1 && *s2)
    {
        if(*s1 != *s2)
            return (*s1 - *s2);
        s1++;
        s2++;
    }
    if(*s1 == '\0' && *s2 == '\0')
        return 0;
    
    return (*s1 - *s2);
}
void ft_sort_string_tab(char **tab)
{
    int i;
    int j;
    if(!tab)
        return;

    i = 0;
    while(tab[i])
    {
        j = i + 1;
        while(tab[j])
        {
            if(ft_strcump(tab[i], tab[j]) < 0)
            {
                swap(&tab[i], &tab[j]);
            }
            j++;
        }
        i++;
    }
}
