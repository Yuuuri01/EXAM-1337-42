# include <stdio.h>



int findMaxConsecutiveOnes(int* nums, int numsSize) 
{
    int count = 0;
    int i = 0;
    int max = 0;
    while(i < numsSize)
    {
        if(nums[i] == 0)
            count = 0;
        else
            count++;
        
        if(max < count)
            max = count;
        i++;
    }
    return max;
}
int main()
{
    int arr[] = {1,0,1,1,0,1};
    printf("%d\n", findMaxConsecutiveOnes(arr, 6));
}