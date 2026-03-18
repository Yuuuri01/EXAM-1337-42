# include <unistd.h>


char    *ft_evenodd(char *str)
{
    int i = 0;
    int j = 0;
    while(str[i])
    {
        if(j % 2 == 0)
        {
            if(str[i] >= 'a' && str[i] <= 'z')
                str[i] -= 32;
        }
        if(str[i] == 32 || str[i] == 9)
        {
            j = -1;
        }
        if(j % 2 != 0)
        {
            if(str[i] >= 'A' && str[i] <= 'Z')
                str[i] += 32;
        }
        i++;
        j++;
    }    
    return str;
}
int main(int ac, char **av)
{
    if(ac == 2)
    {
        char *res = ft_evenodd(av[1]);
        int i = 0;
        while(res[i])
            i++;
        write(1, res, i);
    }
    write(1, "\n", 1);
}