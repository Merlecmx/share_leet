int arrayPairSum(int* nums, int numsSize)
{
    int a;
    int sums = 0;
    int i = 0;
    for (i=0; i<numsSize; i++)
    {
        for (int j=i+1; j<numsSize; j++)
        {
            if (nums[j] < nums[i])
            {
                a = nums[i];
                nums[i] = nums[j];
                nums[j] = a;
            }
         }
     }

      for (int b=0; b<numsSize; b=b+2)
      {
         sums += nums[b];
      }
      return sums;
 }
