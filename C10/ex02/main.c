# include "lib_tail.h"


int main(int ac, char **av)
{

    if(ac == 1)
    {
        error();
        return 0;
    }
    else if(ac > 2 && (av[1][0] == '-' && av[1][1] == 'c') && !(av[2][0] >= '0' && av[2][0] <= '9'))
    {
        ft_putstr(av[0]);
        ft_putstr(": invalid number of bytes: '");
        ft_putstr(av[2]);
        write(1, "'\n", 2);
        return 0;
    }
    else if(ac >= 2 && av[1][0] == '-' && av[1][1] != 'c')
    {
        ft_putstr(av[0]);
        ft_putstr(": illegal option -");
        ft_putstr(av[1]);
        write(2, "\n", 1);
        return 0;
    }
    else if(ac >= 3 && (av[1][0] == '-' && av[1][1] == 'c'))
    {
        int i;
        int valid;
        int print;
        print = 1;
        if(ac == 4)
            print = 0;
        i = 3;
        while(av[i])
        {
            if(print)
            {
                print_banner(av[i]);
            }
            valid = 1;
            handle_option(av[i], av[0], av[2], &valid);
            write(1, "\n", 1);
            if(!valid)
                return 0;
            i++;
        }
        return 0;
    }
    else if(ac == 2 && (av[1][0] == '-' && av[1][1] == 'c'))
    {
        ft_putstr(av[0]);
        ft_putstr(": option requires an argument");
        write(2, "\n", 1);
        return 0;
    }
    else if(ac == 3 && (av[1][0] == '-' && av[1][1] == 'c'))
    {
        error();
        return 0;
    }
    else if(ac >= 2)
    {
        if(av[1][0] == '-')
        {
            ft_putstr(av[0]);
            ft_putstr(": option requires an argument");
            write(2, "\n", 1);
            return 0;
        }
        int print;
        int i;

        //header access
        print = 1;
        if(ac == 2)
            print = 0;

        i = 1;
        while(av[i])
        {
            if(print)
            {
                print_banner(av[i]);
            }
            ft_tail(av[i], av[0]);
            write(1, "\n", 1);
            i++;
        }
        return 0;
    }
}
