# include <unistd.h>
# include <stdio.h>


int check_flage(char *s)
{
    int i;

    if(s[0] == '-')
    {
        i = 1;
        while(s[i])
        {
            if(s[i] == 'h')
                return -1;
            i++;
        }
        return 1;
    }
    return 0;
}
int set_position(char c)
{
    int i;
    char alpha[] = "abcdefghijklmnopqrstuvwxyz";
    i = 0;
    while(alpha[i])
    {
        if(c == alpha[i])
            return i;
        i++;
    }
    return -1;
}

void options(char **av)
{
    int i;
    int j;
    int val;
    int type;
    int valid;
    
    i = 0;
    type = 0;
    while(av[i])
    {
        valid = check_flage(av[i]);
        if(valid == -1)
        {
            write(1, "options: abcdefghijklmnopqrstuvwxyz\n", 36);
            return;
        }
        if(valid == 0)
        {
            write(1, "Invalid Option\n", 15);
            return;
        }
        j = 1;
        while(av[i][j])
        {
            val = set_position(av[i][j]);
            if(val != -1)
            {
                type |= (1 << val);
            }
            else
            {
                write(1, "Invalid Option\n", 15);
                return;
            }
            j++;
        }
        i++;
    }
    i = 31;
    while(i >= 0)
    {
        if(type >> i & 1)
            write(1, "1", 1);
        else
            write(1, "0", 1);
        if(i % 8 == 0 && i != 0)
            write(1, " ", 1);
        i--;
    }
    write(1, "\n", 1);
}
int main(int ac, char **av)
{
    if(ac >= 2)
    {
        options(av + 1);
    }
    else
        write(1, "options: abcdefghijklmnopqrstuvwxyz\n", 36);
}