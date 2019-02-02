int findMaxConsecutiveOnes(int* nums, int numsSize)
{
    int count = 0;
    int max = 0;
    for(int i=0; i<numsSize; i++)
    {
        if(nums[i] == 1)
        {
            count++;
        }
        max = max > count ? max : count;
        count = nums[i] == 0 ? 0 : count;
    }
    return max;
}
