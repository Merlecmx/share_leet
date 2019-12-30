int maxSubArray(int* nums, int numsSize)
{
    int sum;
    sum = 0;
    int res = INT_MIN;
    for(int i=0; i<numsSize; i++)
    {
        if(sum >= 0)
        {
            sum += nums[i];

        }else
        {
            sum = nums[i];
        }
        res = (sum > res) ? sum : res;
    }
    return res;
}
