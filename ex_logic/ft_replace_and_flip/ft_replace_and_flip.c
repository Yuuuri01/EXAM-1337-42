# include <unistd.h>
# include <stdlib.h>


int blank(char c)
{
    if(c == 32 || c == 9)
        return 1;
    return 0;
}
char *convert(char *str)
{
    int i = 0;
    while(str[i])
    {
        if(str[i] >= 'a' && str[i] <= 'z')
            str[i] -= 32;
        else if(str[i] >= 'A' && str[i] <= 'Z')
            str[i] += 32;

        i++;
    }
    return str;
}
char *ft_itoa(int nb)
{
    int tmp = nb;
    int size = 0;
    while(tmp)
    {
        tmp /= 10;
        size++;
    }
    char *tab = malloc((size + 2) * sizeof(char));
        if(!tab)
            exit(EXIT_FAILURE);
        
    tab[size++] = ' ';
    tab[size] = '\0';
    int i = size - 2;
    while(nb)
    {
        tab[i--] = nb % 10 + 48;
        nb /= 10;
    }
    return tab;
}
int ft_strcump(char *s1, char *s2)
{
    int i = 0;
    while(s1[i] || s2[i])
    {
        if(blank(s1[i]) && blank(s2[i]))
            return 0;
        if(s1[i] != s2[i])
            return (s1[i] - s2[i]);
        i++;
    }
    return 0;
}
int count_words(char *str)
{
    int i = 0;
    int w = 0;
    while(str[i])
    {
        if(!blank(str[i]))
        {
            if(i == 0 || blank(str[i - 1]))
                w++;
        }
        i++;
    }
    return w;
}
int length_string(char *str)
{
    int i = 0;
    while(str[i] && !blank(str[i]))
        i++;
    while(str[i] && blank(str[i]))
        i++;

    return i;
}
char *ft_own_strdup(char *str, int length)
{
    char *tab = malloc((length + 1) * sizeof(char));
        if(!tab)
            exit(EXIT_FAILURE);
    int j = 0;
    while(j < length)
    {
        tab[j] = str[j];
        j++;
    }
    tab[j] = '\0';
    return tab;
}
char *spliting(char *str)
{
    int words_c = count_words(str);
    char **tab = malloc((words_c + 3) * sizeof(char *));
        if(!tab)
            exit(EXIT_FAILURE);
    int index = 0;
    int length = 0;
    int i = 0;
    while(str[i])
    {
        if(!blank(str[i]))
        {
            length = length_string(&str[i]);
            tab[index++] = ft_own_strdup(&str[i], length);
            i += length;
        }
        else
            i++;
    }
    tab[index++] = ft_own_strdup("\\n", 3);
    tab[index++] = "\n";
    tab[index] = NULL;
    int len = i + 5;
    //---------------------------------------------------------------------//

    if(words_c > 5)
    {
        length = length_string(tab[1]);
        char *copy_1 = ft_own_strdup(tab[1], length);
        length = length_string(tab[5]);
        char *copy_5 = ft_own_strdup(convert(tab[5]), length);
        i = 0;
        while(tab[i])
        {
            if(!ft_strcump(copy_1, tab[i]) == 1)
            {
                free(tab[i]);
                length = length_string(copy_5);
                tab[i] = ft_own_strdup(copy_5, length);
            }
            i++;
        }
        free(tab[5]);
        length = length_string(copy_1);
        tab[5] = ft_own_strdup(copy_1, length);
        free(copy_1);
        free(copy_5);
    }
    //------------------------------------------------------------------------------|
    char *size = ft_itoa(words_c + 2);
    int j = words_c + 1;
    j /= 2;
    i = words_c;

    while (i >= j)
    {
        tab[i + 1] = tab[i];
        i--;
    }
    length = length_string(size);
    tab[j] = ft_own_strdup(size, length);
    free(size);
//-----------------------------------------------------------------------|
    char *final = malloc((len + 1) * sizeof(char));
        if(!final)
            exit(EXIT_FAILURE);
    i = 0;
    index = 0;
    while(tab[i])
    {
        j = 0;
        while(tab[i][j])
        {
            final[index++] = tab[i][j++];
        }
        free(tab[i]);
        i++;
    }
    free(tab);
    final[index] = '\0';
    return final;
}
# include <stdio.h>
/*
int main()
{
    char str[] = "Run   go  go fast   and lO jump go   here";
    char *res = spliting(str);
        printf("%s\n", res);
        free(res);
}
*/
