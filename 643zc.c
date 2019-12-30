double findMaxAverage(int* nums, int numsSize, int k)
{
    int sum = 0;
    for(int i=0; i<k; i++)
    {
        sum += nums[i];
    }
    double maxAverage = (double)sum / k;
    for(int i=k; i<numsSize; i++)
    {
        sum = sum + (nums[i] - nums[i-k]);
        double Average = (double)sum / k;
        if(Average > maxAverage)
        {
            maxAverage = Average;
        }
    }
    return maxAverage;
}
