# include "lib_tail.h"
# include <stdio.h>

void ft_tail(char *file, char *program)
{
    int i;
    int fd;
    int total;
    int start;
    int count;
    char *buff = malloc(30000);
    int size_buff;
    if(!buff)
        return;

    // int size;

    fd = open(file, O_RDONLY);
    if(fd == -1)
    {
        ft_putstr(program);
        write(2, ": ", 2);
        ft_putstr("cannot open '");
        ft_putstr(basename(file));
        ft_putstr("' for reading: ");
        ft_putstr(strerror(errno));
        write(1, "\n", 1);
        return;
    }
    total = 0;
    size_buff = 30000;
    while (read(fd, buff + total, 1) > 0)
    {
        if(total >= size_buff) // 31024
        {
            size_buff += 1024;
            buff = malloc(size_buff);
        }
        total++;
    }
    count = 0;
    //back to 10
    i = total - 1;
    while (i >= 0)
    {
        if (buff[i] == '\n')
            count++;
        if (count == 10)
            break;
        i--;
    }

    //start point   
    if (i < 0)
        start = 0;
    else
        start = i + 1;

    write(1, buff + start, total - start);
}
