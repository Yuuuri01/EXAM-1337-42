# include <unistd.h>
# include <stdlib.h>



char    *ft_evenodd(char *str)
{
    int len = 0;
    while(str[len])
        len++;

    char *res = malloc((len + 1) * sizeof(char));
    if(!res)
        exit(EXIT_FAILURE);

    int i = 0;
    int j = 0;
    int index = 0;
    while(str[i])
    {
        if(j % 2 == 0)
        {
            if(str[i] >= 'a' && str[i] <= 'z')
                res[index++] = (str[i] - 32);
            else
                res[index++] = (str[i]);
        }
        if(j % 2 != 0)
        {
            if(str[i] >= 'A' && str[i] <= 'Z')
                res[index++] = (str[i] + 32);
            else
                res[index++] = str[i];
        }
        if(str[i] == 32 || str[i] == 9)
        {
            j = -1;
        }
        i++;
        j++;
    }
    res[index] = '\0';
    return res;
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
        free(res);
    }
    write(1, "\n", 1);
}