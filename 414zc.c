int thirdMax(int* nums, int numsSize)
{
    long first,second,third;
    first = LONG_MIN;
    second = LONG_MIN;
    third = LONG_MIN;
    for(int i=0; i<numsSize; i++)
    {
        if(nums[i] > first)
        {
            first = nums[i];
        }
    }
    for(int i=0; i<numsSize; i++)
    {
        if(nums[i] > second && nums[i] != first)
        {
            second = nums[i];
        }
    }
    for(int i=0; i<numsSize; i++)
    {
        if(nums[i] > third && nums[i] != first && nums[i] != second)
        {
            third = nums[i];
        }
    }
    if(third != LONG_MIN)
    {
        return third;
    }
    else
    {
        return first;
    }
}
