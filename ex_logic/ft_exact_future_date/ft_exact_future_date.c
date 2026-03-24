# include <unistd.h>
# include <stdlib.h>


long long ft_atoi(char *str)
{
    long long res = 0;
    int i = 0;
    while(str[i] == 32 || str[i] == 9)
        i++;
    while(str[i] >= '0' && str[i] <= '9')
    {
        res = res * 10 + str[i] - 48;
        i++;
    }
    return res;
}
char *ft_itoa(int nb, int *returnsize)
{
    
    if(nb < 0)
        exit(EXIT_FAILURE);
    
    int tmp = nb;
    int size;
    int i;

    size = 0;
    while(tmp)
    {
        tmp /= 10;
        size++;
    }
    *returnsize = size;

    char *str = malloc((size + 1) * sizeof(char));

    str[size] = '\0';
    i = size - 1;
    
    while(nb)
    {
        str[i--] = (nb % 10) + 48;
        nb /= 10;
    }
    return str;
}
int days(int year, int month)
{
    if (month == 2)
    {   // check leap year
        if((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
        {
            return 29;
        }
        else
            return 28;
    }
    if (month == 4 || month == 6 || month == 9 || month == 11)
        return 30;
    return 31;
}
void calcule_d_y_m(int *day, int *month, int *year, long long *add)
{
    int days_month;

    while (*add > 0)
    {
        days_month = days(*year, *month);
        if (*add > (days_month - *day))
        {
            *add -= (days_month - *day + 1);
            *day = 1;
            (*month)++;
            
            if (*month > 12)
            {
                *month = 1;
                (*year)++;
            }
        }
        else
        {
            *day += *add;
            *add = 0;
        }
    }
}
char *ft_exact_future_date(int day, int month, int year, long long add)
{
    int size_y = 0;
    int size_m = 0;
    int size_d = 0;
    
    calcule_d_y_m(&day, &month, &year, &add);

    char *y = ft_itoa(year, &size_y);
    char *m = ft_itoa(month, &size_m);
    char *d = ft_itoa(day, &size_d);

    char *final = malloc((size_d + size_m + size_y + 4) * sizeof(char));

    int i = 0;
    int j = 0;
    while(i < size_d)
    {
        if(size_d == 1)
        {
            final[j++] = '0';
        }
        final[j++] = d[i];
        i++;
        if(i == size_d)
        {
            final[j++] = '/';
        }
    }
    i = 0;
    while(i < size_m)
    {
        if(size_m == 1)
        {
            final[j++] = '0';
        }
        final[j++] = m[i++];
        if(i == size_m)
        {
            final[j++] = '/';
        }
    }
    i = 0;
    while(i < size_y)
    {
        final[j++] = y[i++];
    }
    final[j] = '\0';

    free(y);
    free(m);
    free(d);
    return final;
}
int main(int ac, char **av)
{
    if(ac == 5)
    {
        long long days = ft_atoi(av[1]);
        long long month = ft_atoi(av[2]);
        long long years = ft_atoi(av[3]);
        long long add = ft_atoi(av[4]);

        char *res = ft_exact_future_date(days, month, years, add);
        int i = 0;
        while(res[i])
            i++;
        write(1, res, i);

        free(res);
    }
    write(1, "\n", 1);
}