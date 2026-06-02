# include <unistd.h>
# include <stdio.h>


int is_open(char c)
{
    return (c == '{' || c == '(' || c == '[');
}
int is_close(char c)
{
    return (c == '}' || c == ')' || c == ']');
}
int close_tag(char c1, char c2)
{
    if(c1 == '{' && c2 == '}')
        return 1;
    else if(c1 == '(' && c2 == ')')
        return 1;
    else if(c1 == '[' && c2 == ']')
        return 1;
    else
        return 0;
}
int brackets(char *str)
{
    char stack[1024];
    int j = -1;
    while(*str)
    {
        if(is_open(*str))
            stack[++j] = *str;
        else if(j >= 0 && is_close(*str))
        {
            if(close_tag(stack[j], *str))
                j--;
            else
                return 0;
        }
        str++;
    }
    return (j == -1);
}
int main(int ac, char **av)
{
    if(ac >= 2)
    {
        int i = 1;
        while(av[i])
        {
            if(!brackets(av[i]))
            {
                write(1, "error", 5);
            }
            else
                write(1, "OK", 2);
            write(1, "\n", 1);
            i++;
        }
    }
    else
        write(1, "\n", 1);
}
