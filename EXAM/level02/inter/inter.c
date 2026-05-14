# include <unistd.h>


int main(int ac, char **av)
{
    if(ac == 3)
    {
        char tab[256] = {0};
        
        while(*av[2])
            tab[(unsigned char)*av[2]++] = 1;
    
        while(*av[1])
        {
            if(tab[(unsigned char)*av[1]])
            {
                write(1, &(*av[1]), 1);
                tab[(unsigned char)*av[1]] = 0;   
            }
            av[1]++;
        }
        write(1, "\n", 1);
    }
}
