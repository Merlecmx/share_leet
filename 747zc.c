int dominantIndex(int* nums, int numsSize)
{
    if(numsSize <= 1)
    {
        return 0;
    }
    else
    {
        int FirstMax,SecondMax,index;
        FirstMax = nums[0] > nums[1] ? nums[0] : nums[1];
        index = nums[0] > nums[1] ? 0 : 1;
        SecondMax = nums[0] >= nums[1] ? nums[1] : nums[0];
        for(int i=2; i<numsSize; i++)
        {
            if(nums[i] > SecondMax)
            {
                if(nums[i] > FirstMax)
                {
                    SecondMax = FirstMax;
                    FirstMax = nums[i];
                    index = i;
                }
                else
                {
                    SecondMax = nums[i];
                }
            }
        }
        return FirstMax >= SecondMax*2 ? index : -1;
    }
}
