int findLengthOfLCIS(int* nums, int numsSize)
{
    int count,temp;
    count = 1;
    temp = 0;
    if(numsSize == 0)
    {
        return 0;
    }
    for(int i=1; i<numsSize; i++)
    {
         if(nums[i] > nums[i-1])
         {
             count++;
         }
         else
         {
             if(count > temp)
             {
                 temp = count;
             }
             count = 1;
         }
     }
     return count > temp ? count : temp;
}
