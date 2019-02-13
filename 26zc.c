int removeDuplicates(int* nums, int numsSize)
{
    if(numsSize < 2)
        return numsSize;
    int i = 1;
    for(int j=0; j<numsSize-1; j++)
    {
        if(nums[j]!=nums[j+1])
        {
            nums[i] = nums[j+1];
            i++;
        }
    }
    return i;
}
