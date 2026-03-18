# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>



int return_cmp(int nb, int *res, int size)
{
    int i = 0;
    int how = 0;
    while(i < size)
    {
        if(nb > res[i++])
            how++;
    }
    return how;
}
int* smallerNumbersThanCurrent(int* nums, int numsSize, int* returnSize)
{
    int *res = malloc(numsSize * sizeof(int));
    if(!res)
        exit(EXIT_FAILURE);
    int i = 0;
    int index = 0;
    while(i < numsSize)
    {
        int val = return_cmp(nums[i], nums, numsSize);
        res[index++] = val;
        i++;
    }
    *returnSize = index;
    return res;
}
int main()
{
    int arr[] = {7,7,7,7};
    int count = 0;
    int *res = smallerNumbersThanCurrent(arr, 4, &count);
    int i = 0;
    while(i < count) printf("%d ", res[i++]);
    printf("\n");
}