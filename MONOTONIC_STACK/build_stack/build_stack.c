# include <unistd.h>
# include <stdlib.h>



int cmp(int *a, int *b, int size)
{
    int i = 0;
    while(i < size)
    {
        if(a[i] != b[i])
            return 0;
        i++;
    }
        return 1;
}
int in_array(int nb, int *res, int size)
{
    int i = 0;
    while(i < size)
    {
        if(nb == res[i])
            return 1;
        i++;
    }
    return 0;
}
char *ft_strdup(char *str)
{
    int i = 0;
    while(str[i])
        i++;
    char *tab = malloc((i + 1) * sizeof(char));
    if(!tab)
        return NULL;
    i = 0;
    while(str[i])
    {
        tab[i] = str[i];
        i++;
    }
    tab[i] = '\0';
    return tab;
}
char** buildArray(int* target, int targetSize, int n, int* returnSize)
{
    char **tab = malloc((100) * sizeof(char*));
    if(!tab)
        exit(EXIT_FAILURE);

    int *arr = malloc(targetSize * sizeof(int));
    if(!arr)
        exit(EXIT_FAILURE);

    int j = 1;
    int index = 0;
    int index2 = 0;
    while(!cmp(arr, target, targetSize) && j <= n)
    {
        if(in_array(j, target, targetSize))
        {
            arr[index2++] = j;
            tab[index++] = ft_strdup("Push");
        }
        if(!in_array(j, target, targetSize))
        {
            tab[index++] = ft_strdup("Push");
            tab[index++] = ft_strdup("Pop");
        }
        j++;
    }
    tab[index] = NULL;
    *returnSize = index;
    free(arr);
    return tab;
}

int main()
{
    int arr[] = {1,3,4,6,7,8};
    int c = 0;
    char **res = buildArray(arr, 6, 9, &c);
    int i = 0;
    while(i < c)
    {
        int len = 0;
        while(res[i][len])
            len++;
        write(1, res[i], len);
        write(1, "\n", 1);
        free(res[i++]);
    }
    free(res);
    exit(EXIT_SUCCESS);
}