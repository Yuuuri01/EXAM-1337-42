int ft_is_sort(int *tab, int length, int(*f)(int, int))
{
    int i;
    int der;

    if(length <= 2)
        return 1;

    i = 0;
    while(i < length - 1 && f(tab[i], tab[i + 1]) == 0)
        i++;
    
    if(i == length - 1)
        return 1;
    
    if(f(tab[i], tab[i + 1]) > 0)
        der = 1;
    else
        der = -1;
    i = 0;
    while(i < length - 1)
    {
        if(der == 1 && f(tab[i], tab[i + 1]) < 0)
            return 0;
        if(der == -1 && f(tab[i], tab[i + 1]) > 0)
            return 0;
        i++;
    }
    return 1;
}