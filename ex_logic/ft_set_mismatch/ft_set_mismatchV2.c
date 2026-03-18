# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>



int count_dup(int *res, int nb, int size)
{
    int  i = 0;
    int count = 0;
    while(i < size)
    {
        if(res[i] == nb)
            count++;
        i++;
    }
    return count;
}
int is_in_array(int *res, int nb, int size)
{
    int i = 0;
    while(i < size)
    {
        if(nb == res[i])
            return 0;
        i++;
    }
    return 1;
}
int* findErrorNums(int* nums, int numsSize, int* returnSize)
{
    int *res = malloc(numsSize * sizeof(int));
    
    int i = 0;
    int index = 0;
    int j = 0;
    int k = 0;
    while(i < numsSize)
    {
        j = count_dup(nums, nums[i], numsSize);
        if(j > 1 && is_in_array(res, nums[i], index))
        {
            res[index++] = nums[i];
            int nb = 1;
            while(k < numsSize)
            {
                if(nb != nums[k] && is_in_array(nums, nb, numsSize))
                {
                    res[index++] = nb;
                    break;
                }
                nb++;
                k++;
            }
        }
        i++;
    }
    *returnSize = index;
    return res;
}
int main()
{
    //int arr[] = {2, 2};
    //int arr1[] = {3, 3, 2};
    //int arr2[] = {1, 2, 2, 4};
    int arr3[] = {1, 2, 3, 4, 5, 6, 6, 7};

    int count = 0;

    int *res = findErrorNums(arr3, 8, &count);
    
    int i = 0;
    while(i < count)
    {
        printf("%d ", res[i++]);
    }
    printf("\n");

}