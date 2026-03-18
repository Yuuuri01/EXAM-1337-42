# include <unistd.h>
# include <stdlib.h>

////SILUTION 1////////////
// int *copy(int *res, int n, int size)
// {
//     int *array = malloc(n * sizeof(int));

//     int i = 0;
//     while(n < size)
//     {
//         array[i] = res[n++];
//         i++;
//     }
//     return array;
// }
// int* shuffle(int* nums, int numsSize, int n, int* returnSize)
// {
//     int *res = malloc(numsSize * sizeof(int));
//     int *arr = copy(nums, n, numsSize);

//     int i = 0;
//     int j = 0;
//     int count = 0;
//     int index = 0;
//     while(count < numsSize)
//     {
//         if(count % 2 == 0)
//         {
//             res[index++] = nums[i++];
//         }
//         else
//             res[index++] = arr[j++];
//         count++;
//     }
//     free(arr);
//     *returnSize = count;
//     return res;
// }


void ft_putchar(char c)
{
    write(1, &c, 1);
}
void ft_putnbr(int nb)
{
    if(nb == 0)
        ft_putchar('0');
    if(nb > 9)
        ft_putnbr(nb / 10);
    ft_putchar((nb % 10) + 48);
}
///SOLUTION 2/////
int* shuffle(int* nums, int numsSize, int n, int* returnSize)
{
    int *res = malloc(numsSize * sizeof(int));

    int i = n;
    int j = 0;
    int index = 0;
    while(i < numsSize)
    {
        res[index++] = nums[j++];
        res[index++] = nums[i++];
    }
    *returnSize = numsSize;
    return res;
}
int main()
{
    int arr[] = {1,2,3,4,4,3,2,1};
    int count = 0;
    int *res = shuffle(arr, 8, 4, &count);
    int i = 0;
    while(i < count)
    {
        ft_putnbr(res[i++]);
        if(i != count)
            ft_putchar(' ');
    }
    ft_putchar('\n');
}