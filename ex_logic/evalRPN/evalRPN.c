# include <unistd.h>
# include <stdlib.h>

void ft_putchar(char c)
{
    write(1, &c, 1);
}
int ft_strlen(char *str)
{
    int len = 0;
    while(str[len])
        len++;
    return len;
}
void ft_putnbr(int nb)
{
    if(nb == 0)
        ft_putchar('0');
    if(nb > 9)
        ft_putnbr(nb / 10);
    ft_putchar((nb % 10) + 48);
}
int check_op(char *tokens)
{
    if(tokens[1] != '\0')
        return 1;
    
    else if(tokens[0] != '+' && tokens[0] != '-' && tokens[0] != '/' && tokens[0] != '*')
        return 1;
    return 0;
}
int ft_atoi(char *str)
{
    int i = 0;
    int res = 0;
    int sign = 1;
    while(str[i] == 32 || str[i] == 9 || str[i] == 13)
    {
        i++;
    }
    while(str[i] == 45 || str[i] == 43)
    {
        if(str[i] == 45)
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
    return res * sign;
}
char *ft_strdup(char *str)
{
    int len = ft_strlen(str);
    char *tab = malloc((len + 1) * sizeof(char));
    if(!tab)
        return NULL;

    int i = 0;
    while(str[i])
    {
        tab[i] = str[i];
        i++;
    }
    tab[i] = '\0';
    return tab;
}
void  op_calc(int *num, int *size, char *op)
{
    if(*size < 2)
        return 0;
    int nb1 = num[*size - 2];
    int nb2 = num[*size - 1];
    int res = 0;

    if(op[0] == '+')
    {
        res = nb1 + nb2;
    }
    if(op[0] == '-')
    {
        res = nb1 - nb2;
    }
    if(op[0] == '/')
    {
        if(nb2 == 0)
            return 0;
        res = nb1 / nb2;
    }
    if(op[0] == '*')
    {
        res = nb1 * nb2;
        
    }
    num[*size - 2] = res;

    (*size)--;
}
int evalRPN(char** tokens, int tokensSize)
{
    int *stack = calloc(tokensSize, sizeof(int));
    if(!stack)
        exit(EXIT_FAILURE);
    int i = 0;
    int j = 0;
    while(i < tokensSize)
    {
        if(tokens[i] && check_op(tokens[i]))
        {
            stack[j] = ft_atoi(tokens[i]);
            j++;
        }
        else if(tokens[i])
            op_calc(stack, &j, tokens[i]);
        i++;
    }
    int nb = stack[0];
    free(stack);
    return nb;
}
int main()
{
    // char *str[6];
    // int tokensize = 6; //2","1","+","3","
    // str[0] = ft_strdup("2");
    // str[1] = ft_strdup("1");
    // str[2] = ft_strdup("+");
    // str[3] = ft_strdup("3");
    // str[4] = ft_strdup("*");
    // str[5] = NULL;

    char *str[14];
    int tokensize = 14;
    str[0] = ft_strdup("10");
    str[1] = ft_strdup("6");
    str[2] = ft_strdup("9");
    str[3] = ft_strdup("3");
    str[4] = ft_strdup("+");
    str[5] = ft_strdup("-11");
    str[6] = ft_strdup("*");
    str[7] = ft_strdup("/");
    str[8] = ft_strdup("*");
    str[9] = ft_strdup("17");
    str[10] = ft_strdup("+");
    str[11] = ft_strdup("5");
    str[12] = ft_strdup("+");
    str[13] = NULL;

    //print_result
    
    ft_putnbr(evalRPN(str, tokensize));
    ft_putchar('\n');
    //

    int i = 0;
    while(i < tokensize)
    {
        free(str[i++]);
    }
}