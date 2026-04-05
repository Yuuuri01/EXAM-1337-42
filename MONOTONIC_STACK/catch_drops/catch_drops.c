# include <stdlib.h>

int min_nbr(int nb1, int nb2)
{
    return (nb1 > nb2) ? nb2 : nb1;
}
int catch_the_drops(int *heights, int size)
{
    int *res_left = malloc(size * sizeof(int));
    int *res_right = malloc(size * sizeof(int));
    if(!res_right || !res_left)
        exit(EXIT_FAILURE);
    
    
    int i = 0;
    int j = size - 1;
    int max1 = heights[i];
    int max2 = heights[j];
    while(i < size && j >= 0)
    {
        if(heights[i] > max1)
        {
            max1 = heights[i];
        }
        res_left[i++] = max1;
        if(heights[j] > max2)
        {
            max2 = heights[j];
        }
        res_right[j--] = max2;
    }
    i = 0;
    int water = 0;
    while(i < size)
    {
        water += min_nbr(res_left[i], res_right[i]) - heights[i];
        i++;
    }
    free(res_left);
    free(res_right);
    return water;
}
int main()
{
    int res[] = {0, 1, 2, 3, 4};
    int nb = catch_the_drops(res, 5);
    printf("%d\n", nb);
}