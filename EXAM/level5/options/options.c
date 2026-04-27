# include "options.h"

int check_option(char *av)
{
    int i;

    i = 0;
    while(av[i])
    {
        if(av[0] != '-')
            return -1;
        if(av[i + 1] && (av[i] == '-' && av[i + 1] == 'h'))
            return 0;
        i++;
    }
    return 1;
}
int set_position(char c)
{
    char base[] = "abcdefghijklmnopqrstuvwxyz";
    int i;
    
    i = 0;
    while(base[i])
    {
        if(base[i] == c)
            return i;
        i++;
    }
    return -1;
}
char *make_option(char *str, char **av)
{
    int i;
    int j;

    i = 0;/// start from 1 bcs 0 ==> '-'
    while(av[i])
    {
        if(check_option(av[i]) == -1)
        {
            return (write(2, "Invalid Option!\n", 17), NULL);
        }
        if(!check_option(av[i]))
        {
            return (options_list(), NULL);
        }
        j = 1;
        while(av[i][j])
        {
            int val = set_position(av[i][j]);
            if(val != -1)
            {
                str[val] = '1';
            }
            else
                return (write(2, "Invalid Option!\n", 17), NULL);
            j++;
        }
        i++;
    }
    return str;
}
char *options(char **av)
{
    char *str;
    char *send;
    int i;

    str = malloc((32 + 1) * sizeof(char));
    if(!str)
        return NULL;
    i = 0;
    while(i < 32)
    {
        str[i++] = '0';
    }
    str[i] = '\0';
    send = make_option(str, av + 1);
    if(!send)
    {
        free(str);
        return NULL;
    }
    return send;
}
