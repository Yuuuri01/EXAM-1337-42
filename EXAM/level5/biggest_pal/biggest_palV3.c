# include <unistd.h>

int     get_len(char *str, int left, int right, int len)
{
    while(left >= 0 && right < len && str[left] == str[right])
    {
        left--;
        right++;
    }
    return (right - left - 1);
}
void    biggest_pal(char *str, int *len)
{
    int i = 0;
    int max = 0;
    int length = 0;
    int from = 0;
    while(str[i])
    {
        int len1 = get_len(str, i, i, *len);
        int len2 = get_len(str, i, i + 1, *len);
        if(len1 > len2)
            length = len1;
        else
            length = len2;
        if(length > max)
        {
            max = length;
            from = i - (length - 1) / 2; // start index
        }
        i++;
    }
    int index = 0;
    while(index < max)
    {
        write(1, &str[from + index], 1);
        index++;
    }
}
int main(int ac, char **av)
{
    if(ac == 2)
    {
        int len = 0;
        while(av[1][len])
            len++;
        biggest_pal(av[1], &len);
    }
    write(1, "\n", 1);
}
