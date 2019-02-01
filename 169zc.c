int majorityElement(int* nums, int numsSize)
{
    for (int i=0; i<numsSize; i++)
    {
        for (int j=i+1; j<numsSize; j++)
        {
            if (nums[j] < nums[i])
            {
                int a;
                a = nums[i];
                nums[i] = nums[j];
                nums[j] = a;
            }
        }
    }
    return nums[numsSize/2];
}
