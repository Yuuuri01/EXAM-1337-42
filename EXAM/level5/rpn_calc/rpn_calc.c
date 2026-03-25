# include "ft_rpn_calc.h"


int main(int ac, char **av)
{
    if(ac == 2)
    {
        int res =rpn_calc(av[1]);
        if(!res)
            write(1, "Error\n", 6);
        else
        {
            ft_putnbr(res);
            ft_putchar('\n');
        }
    }
    else
        write(1, "Error\n", 6);
}