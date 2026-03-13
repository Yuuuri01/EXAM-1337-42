# include <unistd.h>
# include <stdlib.h>


int len_of(int nb)
{
    int size = 0;
    while(nb)
    {
        nb /= 10;
        size++;
    }
    return size;
}
int count_char(char c, char *str, int index)
{
    int i = index;
    int con = 0;
    int exit = 0;
    while(str[i])
    {
        if(c == str[i])
            con++;
        if(c != str[i])
            return con;
        i++;
    }
    return con;
}
char *ft_compress_str(char *str)
{
    int i = 0;
    while(str[i])
    {
        i++;
    }
    char *res = malloc((i + 1) * sizeof(char));
        if(!res)
            exit(EXIT_FAILURE);
    i = 0;
    int index = 0;
    int val = 0;
    int begin = 0;
    while(str[i])
    {
        val = count_char(str[i], str, begin);
        begin += val;
        if(val > 9)
        {
            res[index++] = str[i];
            int len = len_of(val);
            int j = (len - 1) + index;
            int nb = val;
            while(nb)
            {
                res[j--] = nb % 10 + 48;
                nb /= 10;
            }
            index += len;
        }
        else if(val <= 9)
        {
            res[index++] = str[i];
            res[index++] = val + 48;
        }
        i += val;
    }
    res[index] = '\0';
    return res;
}
int main(int ac, char **av)
{
    if(ac == 2)
    {
        char *res = ft_compress_str(av[1]);
        int i = 0;
        while(res[i])
            i++;
        
        write(1, res, i);
        free(res);
    }
    write(1, "\n", 1);
    exit(EXIT_SUCCESS);
}
