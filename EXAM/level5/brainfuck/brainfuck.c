# include <unistd.h>

char *escape_from_brackets_left(char *s)
{
    int index = 1;
    while(index > 0)
    {
        s--;
        if(*s == ']')
            index++;
        else if(*s == '[')
            index--;
    }
    return s;
}
char *escape_from_brackets_right(char *s)
{
    int index = 1;
    while(index > 0)
    {
        s++;
        if(*s == '[')
            index++;
        else if(*s == ']')
            index--;
    }
    return s;
}
void brainfuck(char *s)
{
    unsigned char arr[2048] = {0};
    unsigned char *p = arr;
    
    while(*s)
    {
        if(*s == '+')
            (*p)++;
        else if(*s == '-')
            (*p)--;
        else if(*s == '>')
            p++;
        else if(*s == '<')
            p--;
        else if(*s == '.')
            write(1, p, 1);
        else if(*s == '[')
        {
            if(*p == 0)
                s = escape_from_brackets_right(s);
        }
        else if(*s == ']')
        {
            if(*p != 0)
                s = escape_from_brackets_left(s);
        }
        s++;
    }
}
int main(int ac, char **av)
{
    if(ac == 2)
    {
        brainfuck(av[1]);
    }
}

// index = 1;
// while(index > 0)
// {
//     s--;
//     if(*s == ']')
//         index++;
//     else if(*s == '[')
//         index--;
// }

//- '>' increment the pointer ;
// - '<' decrement the pointer ;
// - '+' increment the pointed byte ;
// - '-' decrement the pointed byte ;
// - '.' print the pointed byte on standard output ;
// - '[' go to the matching ']' if the pointed byte is 0 (while start) ;
// - ']' go to the matching '[' if the pointed byte is not 0 (while end).


    // int main()
    // {
    //     char *s = "[++++++++++++++++++[+++++++++++]+++++++++]escape success!";
    //     escape_from_brackets(s);
    //     write(1, "\n", 1);
    // }
// }