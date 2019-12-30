int findUnsortedSubarray(int* nums, int numsSize)
{
    int *temp = malloc(sizeof(int)*numsSize);
    for(int i=0; i<numsSize; i++)
    {
        temp[i] = nums[i];
    }
    int compare(const void * a, const void*b)
    {
        return *(int*)a - *(int*)b;
    }
    qsort(temp, numsSize, sizeof(int), compare);
    int i, j;
    i = 0;
    j = numsSize-1;
    while(i < j)
    {
        int count = 1;
        if(nums[i] == temp[i])
        {
            i++;
            count = 0;
        }
        if(nums[j] == temp[j])
        {
            j--;
            count = 0;
        }
        if(count == 1) break;
    }
    if(i >= j)
        return 0;
    return j-i+1;
}
