# include "doop.h"

int main(int ac, char **av)
{
    if(ac != 4)
    {
        write(1, "n", 1);
        return 0;
    }
    if(ac == 4)
    {
        int nb1;
        int nb2;
        char op;
        int res;
        
        nb1 = ft_atoi(av[1]);
        nb2 = ft_atoi(av[3]);
        op = av[2][0];
        if(av[2][1] != '\0' || (op != '+' && op != '-' && op != '*' && op != '/' && op != '%'))
        {
            ft_putnbr(0);
            write(1, "\n", 1);
            return 0;
        }
        
        if(op == '+')
            res = nb1 + nb2;
        else if(op == '*')
        {
            res = nb1 * nb2;
        }
        else if(op == '-')
            res = nb1 - nb2;
        else if(op == '/')
        {
            if(nb2 == 0)
            {
                write(1, "Stop : division by zero\n", 24);
                return 0;
            }
            res = nb1 / nb2;
        }
        else if(op == '%')
        {
            if(nb2 == 0)
            {
                write(1, "Stop : modulo by zero\n", 22);
                return 0;
            }
            res = nb1 % nb2;
        }
        ft_putnbr(res);
        write(1, "\n", 1);
    }
    return 0;
}