
int missingNumber(int* nums, int numsSize)
{
    int sum = numsSize;
    int numssum = 0;
    for(int i=0; i<numsSize; i++)
    {
        sum += i;
        numssum += nums[i];
    }
    return sum - numssum;
}
