# include <unistd.h>



// int cmp(char *s1, char *s2)
// {
//     while(*s1 && *s2)
//     {
//         if(*s1 != *s2)
//             return (*s1 - *s2);
//         s1++;
//         s2++;
//     }
//     if(*s1 == '\0' && *s2 == '\0')
//         return 0;
//     return (*s1 - *s2);
// }
void swap(char **a, char **b)
{
    char *tmp;

    tmp = *a;
    *a = *b;
    *b = tmp;
}
void ft_advanced_sort_string_tab(char **tab, int(*cmp)(char *, char *))
{
    int i;
    int j;
    if(!tab || !cmp)
        return;
    
    i = 0;
    while(tab[i])
    {
        j = i + 1;
        while(tab[j])
        {
            if(cmp(tab[i], tab[j]) > 0)
            {
                swap(&tab[i], &tab[j]);
            }
            j++;
        }
        i++;
    }
}
//----main-----//