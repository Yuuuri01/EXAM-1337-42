# include <unistd.h>
# include <stdio.h>



int get_type_len(char *str, int left, int right, int len)
{
    while(left >= 0 && right < len && str[left] == str[right])
    {
        left--;
        right++;
    }
    return (right - left - 1);
}
void biggest_pall(char *str, int len)
{
    int from;
    int max = 0;
    int max_final = 0;
    int i = 0;
    while(str[i])
    {
        int len1 = get_type_len(str, i, i, len);
        int len2 = get_type_len(str, i, i + 1, len);
        max = (len1 > len2) ? len1 : len2;
        if(max >= max_final)
        {
            max_final = max;
            from = i - (max - 1) / 2;
        }
        i++;
    }
    int index = 0;
    while(index < max_final)
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
        biggest_pall(av[1], len);
    }
    write(1, "\n", 1);
}