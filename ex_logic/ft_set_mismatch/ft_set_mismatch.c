# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>


int checkint(int nb, int *res, int size)
{
    int i = 0;
    int count = 0;
    while(i < size)
    {
        if(nb == res[i])
            count++;
        i++;
    }
    return count;
}
int check_in_array(int nb, int *res, int size)
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
int find_missing(int *nums, int size)
{
    int i = 0;
    int j = 1;
    while(i < size)
    {
        if(j != nums[i] && check_in_array(j, nums, size))
            return j;
        j++;
        i++;
    }
    return 0;

}
int* findErrorNums(int* nums, int numsSize, int* returnSize)
{
    int *res = malloc(numsSize * sizeof(int));
    int i = 0;
    int index = 0;
    int j = 0;
    int index2 = 0;
    while(i < numsSize)
    {
        j = checkint(nums[i], nums, numsSize);
        if(j > 1 && check_in_array(nums[i], res, index))
        {    
            res[index++] = nums[i];
            int nb = find_missing(nums, numsSize);
            if(nb > 0)
                res[index++] = nb;
        }
        i++;
    }
    *returnSize = index;
    return res;
}
int main()
{
    int array[] = {3, 3, 2};
    int count = 0;
    int *res = findErrorNums(array, 3, &count);
    int i = 0;
    while(i < count)
    {
        printf("%d ", res[i++]);
    }
    printf("\n");
    free(res);
}