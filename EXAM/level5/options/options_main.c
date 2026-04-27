# include "options.h"

int main(int ac, char **av)
{
    if(ac >= 2)
    {
        int i = 31;
        char *str = options(av);
        if(!str)
            return 0;

        while(str[i] && i >= 0)
        {
            write(1, &str[i], 1);
            if(i == 8 || i == 16 || i == 24)
                write(1, " ", 1);
            i--;
        }
        free(str);
        write(1, "\n", 1);
    }
    else
        options_list();
}