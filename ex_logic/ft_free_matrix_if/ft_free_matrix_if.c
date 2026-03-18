# include <unistd.h>
# include <stdlib.h>

int ft_strlen(char *str)
{
    int i = 0;
    while(str[i])
        i++;

    return i;
}
char *ft_strdup(char *str)
{
    int len = ft_strlen(str);
    char *tab = malloc((len + 1) * sizeof(char));
    if(!tab)
        return NULL;
    int i = 0;
    while(str[i])
    {
        tab[i] = str[i];
        i++;
    }
    tab[i] = '\0';
    return tab;
}
int check_vowel(char c)
{
    char *base = "AEIOUaeiou";
    int i = 0;
    while(base[i])
    {
        if(c == base[i])
            return 0;
        i++;
    }
    return 1;
}
void ft_free_matrix_if(char **strs)
{
    int i = 0;
    int j = 0;
    int back = 0;
    while(strs[i])
    {
        if(!check_vowel(strs[i][j]))
        {
            free(strs[i]);
            int k = i;
            while(strs[k])
            {
                strs[k] = strs[k + 1];
                k++;
            }
            strs[k] = NULL;
            back = 1;
        }
        else
        {
            back = 0;
        }
        i++;
        if(back)
            i -= 1;
    }
    i = 0;
    while(strs[i])
    {
        int len = ft_strlen(strs[i]);
        write(1, strs[i], len);
        free(strs[i++]);    
        write(1, "\n", 1);
    }
    free(strs);
}
/*
int main()
{
    //---array of pointers-----//
    //char *str[7];

    //---pointer to pointer-----//
    char **str = malloc((6 + 1) * sizeof(char*));
    if(!str)
        exit(EXIT_FAILURE);
    str[0] = ft_strdup("hello");
    str[1] = ft_strdup("alc");
    str[2] = ft_strdup("Christopher");
    str[3] = ft_strdup("konstantinos");
    str[4] = ft_strdup("carthage");
    str[5] = ft_strdup("All");
    str[6] = NULL;
    
    int i = 0;
    printf("----------WORDS-------------\n");
    while(str[i])
    {
        printf("%s\n", str[i++]);
    }
    printf("----AFTER-REMOVING-WORDS------\n");
    ft_free_matrix_if(str);
    printf("-------------------------------\n");
}
*/