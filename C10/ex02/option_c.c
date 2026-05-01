# include "lib_tail.h"


void handle_option(char *file, char *program, char *av2, int *valid)
{
    int n_bytes = ft_atoi(av2);
    if(!n_bytes)
    {
        *valid = 0;
        return;
    }
    int bytes;
    int start;
    int size;
    int total;
    char *buff;
    int fd;

    fd = open(file, O_RDONLY);
    if(fd == -1)
    {
        ft_putstr(program);
        write(1, ": ", 2);
        ft_putstr("cannot open '");
        ft_putstr(basename(file));
        ft_putstr("' for reading: ");
        ft_putstr(strerror(errno));
        return;
    }
    total = 0;
    size = 300000;
    buff = malloc(size);
    if(!buff)
        return;
    while((bytes = read(fd, buff + total, 1)) > 0)
    {
        total += bytes;
        if(total >= size)
        {
            size *= 2;
            buff = malloc(size);
            if(!buff)
                return;
        }
    }
    start = total - n_bytes;
    if(start < 0)
    {
        start = 0;
        n_bytes = total;
    }
    write(1, buff + start, n_bytes);
    free(buff);
    close(fd);
}
