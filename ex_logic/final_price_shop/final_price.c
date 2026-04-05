# include <stdio.h>
# include <stdlib.h>


int* finalPrices(int* prices, int pricesSize, int* returnSize)
{
    int *res = malloc(pricesSize * sizeof(int));
    if(!res)
        exit(EXIT_FAILURE);

    int i = 0;
    int index = 0;
    int ark = 1;
    int j;
    while(i < pricesSize)
    {
        ark = 1;
        j = i + 1;
        while(j < pricesSize)
        {
            if(prices[i] >= prices[j])
            {
                res[index++] = prices[i] - prices[j]; //[8,4,6,2,3]
                ark = 0;
                break;
            }
            j++;
        }
        if(ark)
        {
            res[index++] = prices[i];
        }
        i++;
    }
    *returnSize = index;
    return res;
}
int main()
{
    int arr[] = {10, 1, 1, 6};
    int size = 4;
    int resize = 0;
    int *new = finalPrices(arr, size, &resize);
    int i = 0;
    while(i < resize)
    {
        printf("%d ", new[i++]);
    }
    printf("\n");
}