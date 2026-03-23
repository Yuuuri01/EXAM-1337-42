# include <unistd.h>
# include <stdlib.h>


int ft_strlen(char *str)
{
    int i = 0;
    while(str[i])
        i++;
    return i;
}
int ft_strcmp(char *s1, char *s2)
{
    int i = 0;
    while(s1[i] && s2[i])
    {
        if(s1[i] != s2[i])
            return s1[i] - s2[i];
        i++;
    }
    return s1[i] - s2[i];
}
int check_char(char **del, char *tab)
{
    int i = 0;
    while(del[i])
    {
        if(ft_strcmp(del[i], tab) == 0)
        {
            return 0;
        }
        i++;
    }
    return 1;
}
char *copy(char **str, char **del)
{
    int i = 0;
    int len = 0;
    while(str[i])
    {
        len += ft_strlen(str[i++]);
    }
    len += i;

    char *s = malloc((len + 1) * sizeof(char));
    if(!s)
        exit(EXIT_FAILURE);

    i = 0;
    int j;
    int index = 0;
    while(str[i])
    {
        if(check_char(del, str[i]))
        {
            j = 0;
            while(str[i][j])
            {
                s[index++] = str[i][j++];
            }
            s[index++] = ' ';
        }
        else
            s[index++] = '0';
        i++;
    }
    s[index] = '\0';
    return s;
}
int count_words(char *str)
{
    int i = 0;
    int count = 0;
    while(str[i])
    {
        if(str[i] != 32 && str[i] != 9)
        {
            if(i == 0 || (str[i - 1] == 32 || str[i - 1] == 9))
                count++;
        }
        i++;
    }
    return count;
}
int length_string(char *str)
{
    int len = 0;
    while(str[len] && str[len] != '0')
        len++;
    return len;
}
char *copy2(char *str, int len)
{
    int i = 0;
    char *s = malloc((len + 1) * sizeof(char));
    if(!s)
        exit(EXIT_FAILURE);
    while(i < len)
    {
        s[i] = str[i];
        i++;
    }
    s[i] = '\0';
    return s;
}
char **ft_multi_split(char *str, char **delimiters)
{
    int len = count_words(str);

    char **tab1 = malloc((len + 1) * sizeof(char *));
    if(!tab1)
        exit(EXIT_FAILURE);

    int i = 0;
    int access = 1;
    int index = 0;
    while(str[i])
    {
        if((str[i] != 32 && str[i] != 9 ) && access)
        {
            tab1[index++] = &str[i];
            access = 0;
        }
        if(!access && (str[i] == 32 || str[i] == 9))
        {
            str[i] = '\0';
            access = 1;
        }
        i++;
    }
    tab1[index] = NULL;
    char *s = copy(tab1, delimiters);

    i = 0;
    index = 0;
    access = 1;
    int length = 0;
    while(s[i])
    {
        if(s[i] != '0')
        {
            length = length_string(&s[i]);
            tab1[index++] = copy2(&s[i], length);
            i += length;
        }
        i++;
    }
    tab1[index] = NULL;
    free(s);
    return tab1;
}
# include <stdio.h>
int main()
{

    char str[] = "hello this is me i'm not coding";
    char *s[5];
    s[0] = "is";
    s[1] = "i'm";
    s[2] = NULL;
    char  **res = ft_multi_split(str, s);


    int i = 0;
    while(res[i])
    {
        printf("%s\n", res[i]);
        free(res[i++]);
    }
    free(res);
}