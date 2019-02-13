int maximumProduct(int* nums, int numsSize)
{
    for(int i=0; i<numsSize-1; i++)
    {
        for(int j=0; j<numsSize-1-i; j++)
        {
            if(nums[j] > nums[j+1])
            {
                int temp;
                temp = nums[j];
                nums[j] = nums[j+1];
                nums[j+1] = temp;
            }
        }
    }
    int max1 = (nums[0] * nums[1] * nums[numsSize-1]);
    int max2 = (nums[numsSize-1] * nums[numsSize-2] * nums[numsSize-3]);
    return max1 > max2 ? max1 : max2;
}
