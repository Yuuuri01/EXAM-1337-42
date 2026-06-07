# include <unistd.h>



void	print_bits(unsigned char octet)
{
    int i = 128;
    while(i)
    {
        if(octet / i)
        {
            write(1, "1", 1);
            octet -= i;
        }
        else{
            write(1, "0", 1);
        }
        i /= 2;
    }
}
int main(int ac, char **av)
{
    if(ac == 2)
    {
        int nb = atoi(av[1]);
        print_bits(nb);
    }
    write(1, "\n", 1);
    return 0;
}