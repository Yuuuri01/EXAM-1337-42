# include <unistd.h>
# include <stdlib.h>


//1 2 3 4 ====> 1 2 3 4 1 2 3 4
// int* getConcatenation(int* nums, int numsSize, int* returnSize)
// {
//     int *ans = malloc((numsSize * 2) * sizeof(int));

//     int i = 0;
//     int index = 0;
//     int j = 0;
//     *returnSize = 0;
//     while(j < (numsSize * 2))
//     {
//         ans[index++] = nums[i];
//         i++;
//         j++;
//         (*returnSize)++;
//         if(i == numsSize)
//             i = 0;
//     }
//     return ans;
// }
int* getConcatenation(int* nums, int numsSize, int* returnSize)
{
    int size = numsSize * 2;
    int *ans = malloc(size * sizeof(int));

    int i = 0;
    int index = 0;
    int val = numsSize;
    while(i <  numsSize)
    {
        ans[index++] = nums[i];
        ans[val++] = nums[i];
        i++;
    }
    *returnSize = size;
    return ans;
}
# include <stdio.h>
int main()
{
    int array[] = {1, 3, 2, 1};
    int n = 4;
    int ret_size = 0;
    int *arr = getConcatenation(array, n, &ret_size);

    int i = 0;
    while(i < ret_size)
    {
        printf("%d", arr[i++]);
    }
    printf("\n");
    free(arr);
}