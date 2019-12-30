void moveZeroes(int* nums, int numsSize)
{
    for(int i=0, j=0; i<numsSize; i++)
    {
            if(nums[i] != 0)
            {
                int a;
                a = nums[i];
                nums[i] = nums[j];
                nums[j] = a;
                j++;
            }
    }
    return nums;
}
