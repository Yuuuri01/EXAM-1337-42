# include "doop.h"


void ft_putchar(char c)
{
    write(1, &c, 1);
}
void ft_putnbr(int res)
{
    if(res == 0)
    {
        ft_putchar('0');
        return;
    }
    if(res < 0)
    {
        ft_putchar('-');
        res = -res;
    }
    if(res > 9)
    {
        ft_putnbr(res / 10);
    }
    ft_putchar((res % 10) + 48);
}