// # include <stdlib.h>


// int f(char *s)
// {
//     while(*s)
//     {
//         if(*s >= '0' && *s <= '9')
//             return 1;
//         s++;
//     }
//     return 0;
// }
int ft_count_if(char **tab, int length, int(*f)(char*))
{
    int i;
    int count;


    i = 0;
    count = 0;
    while(i < length)
    {
        if(f(tab[i]))
            count++;
        i++;
    }
    return count;
}