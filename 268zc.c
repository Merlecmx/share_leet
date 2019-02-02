
int missingNumber(int* nums, int numsSize)
{
    int numssum = 0;
    for(int i=0; i<numsSize; i++)
    {
        numsSize += i;
        numssum += nums[i];
    }
    return numsSize  - numssum;
}
