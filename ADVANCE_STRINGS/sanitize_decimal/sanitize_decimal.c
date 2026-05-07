# include <stdlib.h>
# include <unistd.h>

int get_len(char *str)
{
    int i;
    int j;
    int len;
    int one_dot;
    
    one_dot = 1;
    i = 0;
    len = 0;
    while(str[i])//"...abcfd.12."
    {
        if(str[i] >= '0' && str[i] <= '9')
        {
            len++;
        }
        if(len > 0 && one_dot && str[i] == '.')
        {
            len++;
            one_dot = 0;
        }
        i++;
    }
    return len;
}
char    *sanitize_decimal(char *str)
{
    int i;
    int j;
    int one_dot;
    char *new;

    new = malloc(sizeof(char) * (get_len(str) + 1));
    if(!new) return NULL;

    i = 0;
    j = 0;
    one_dot = 1;
    while(str[i])//"...abcfd.12."
    {
        if(str[i] >= '0' && str[i] <= '9')
            new[j++] = str[i];
        else if(j > 0 && one_dot && str[i] == '.')
        {
            new[j++] = '.';
            one_dot = 0;
        }
        i++;
    }
    if(j > 0 && new[j - 1] == '.')
        j--;
    new[j] = '\0';
    return new;
}

int main(int ac, char **av)
{
    if(ac == 2)
    {
        char *str = sanitize_decimal(av[1]);
        if(str)
		{
			int i = 0;
			while(str[i]) i++;
			(write(1, str, i), free(str));
		}
    }
	write(1, "\n", 1);
}