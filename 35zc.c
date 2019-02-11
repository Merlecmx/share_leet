int searchInsert(int* nums, int numsSize, int target)
{
    for(int i=0; i<numsSize; i++)
    {
        if(nums[i] == target)
        {
            return i;
        }
    }
    for(int i=0; i<numsSize; i++)
    {
        if(nums[0] > target)
        {
            return 0;
        }else if(nums[numsSize - 1] < target)
        {
            return numsSize;
        }else if(nums[i] < target && target < nums[i+1])
        {
            return i+1;
        }
    }
    return 0;
}
