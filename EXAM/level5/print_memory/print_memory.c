# include <unistd.h>


void print_hex(int nb)
{
    char hex[] = "0123456789abcdef";
    write(1, &(hex[nb / 16]), 1);
    write(1, &(hex[nb % 16]), 1);
}
void line(unsigned char *ptr, size_t *index, size_t size)
{
    size_t j = 0;
    while(j < 16)
    {
        if(*index + j < size)
            print_hex(ptr[j + *index]);
        else
            write(1, "  ", 2);
        j++;
        if((j % 4 == 0 || j % 2 == 0) && j != 0)
            write(1, " ", 1);
    }
}
void	print_memory(const void *addr, size_t size)
{
    size_t      i;
    size_t      j;
    unsigned char *ptr;
    
    ptr = (unsigned char *)addr;
    i = 0;
    while(i < size)
    {
        line(ptr, &i, size);
        j = 0;
        while(j < 16 && i + j < size)
        {
            if(ptr[i + j] >= 32 && ptr[i + j] <= 126)
                write(1, &ptr[i + j], 1);
            else
                write(1, ".", 1);
            j++;
        }
        write(1, "\n", 1);
        i += 16;
    }
}