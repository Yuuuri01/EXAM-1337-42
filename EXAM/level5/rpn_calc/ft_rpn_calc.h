# include <unistd.h>
# include <stdlib.h>

void ft_putchar(char c)
{
    write(1, &c, 1);
}
void ft_putnbr(int nb)
{
    if(nb < 0)
    {
        ft_putchar('-');
        nb = -nb;
    }
    if(nb > 9)
        ft_putnbr(nb / 10);
    ft_putchar((nb % 10) + 48);    
}
int check_is_op(char *str)
{

    if(str[1] != '\0')
        return 1;
    else if(str[0] != '+' && str[0] != '-' && str[0] != '/' && str[0] != '*')
        return 1;
    return 0;
}
int ft_atoi(char *str)
{
    int res = 0;
    int sign = 1;
    int i = 0;
    while(str[i] == 32 || str[i] == 9)
        i++;
    while(str[i] == '-' || str[i] == '+')
    {
        if(str[i] == '-')
        {
            sign *= -1;
        }
        i++;
    }
    while(str[i] >= '0' && str[i] <= '9')
    {
        res = res * 10 + str[i] - 48;
        i++;
    }
    return  res * sign;
}
int count_words(char *str)
{
    int i = 0;
    int count = 0;
    while(str[i])
    {
        if(str[i] != 32 && str[i] != 9)
        {
            if(i == 0 || (str[i - 1] == 32 || str[i - 1] == 9))
                count++;
        }
        i++;
    }
    return count;
}
char **split(char *str, int *size)
{
    int i = count_words(str);
    *size = i;
    char **res = malloc((i + 1) * sizeof(char*));
    if(!res)
        exit(EXIT_FAILURE);
    i = 0;
    int access = 1;
    int index = 0;
    while(str[i])
    {
        if((str[i] != 32 && str[i] != 9) && access)
        {
            res[index++] = &str[i];
            access = 0; 
        }
        if(!access && (str[i] == 32 || str[i] == 9))
        {
            str[i] = '\0';
            access = 1;
        }
        i++;
    }
    res[index] = NULL;
    i = 0;
    int len1 = 0;
    int len2 = 0;
    while(res[i])
    {
        if(check_is_op(res[i]))
            len1++;
        else
            len2++;
        i++;    
    }
    if((len1 != len2 + 1) || !check_is_op(res[0]))
    {
        free(res);
        return NULL;
    }
    return res;
}
void  calc_rpn(int *tab, int *size, char *op, int *valid)
{
    if(*size < 2)
        *valid = 0;
    else
        *valid = 1;

    int nb1 = tab[*size - 2];
    int nb2 = tab[*size - 1];

    int res = 0;
    if(op[0] == '+')
        res = nb1 + nb2;
    if(op[0] == '-')
        res = nb1 - nb2;
    if(op[0] == '/')
        res = nb1 / nb2;
    if(op[0] == '%')
        res = nb1 % nb2;
    if(op[0] == '*')
        res = nb1 * nb2;

    tab[*size - 2] = res;
    (*size)--;

}
int  rpn_calc(char *str)
{
    int size = 0;
    char **res = split(str, &size);
    if(!res)
    {
        return 0;
    }
    int *tab = malloc(size * sizeof(int));
    if(!tab)
        exit(EXIT_FAILURE);

    int i = 0;
    int index = 0;
    int nb;
    while(res[i])
    {
        if(check_is_op(res[i]))
        {
            tab[index++] = ft_atoi(res[i]);
        }
        else if(res[i])
        {
            int valid = 1;
            calc_rpn(tab, &index, res[i], &valid);
            if(!valid)
            {
                free(tab);
                free(res);
                return 0;
            }
        }
        i++;
    }
    nb = tab[0];
    i = 0;
    free(res);
    free(tab);
    return nb;
}
