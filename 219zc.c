bool containsNearbyDuplicate(int* nums, int numsSize, int k)
{
        for(int i=0; i<numsSize; i++)
        {
            for(int j=numsSize-1; j>i; j--)
            {
                if(nums[i] == nums[j] && (j-i) <= k)
                {
                    return true;
                }
            }
        }
        return false;
}
