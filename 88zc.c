void merge(int* nums1, int m, int* nums2, int n)
{
    for(int i=0; i<n; i++)
    {
        nums1[m+i] = nums2[i];
    }
    BubbleSort(nums1,(m+n));
}
void BubbleSort(int *arr,int size)
{
    for(int i=0; i<size-1; i++)
    {
        for(int j=0; j<size-1-i; j++)
        {
            if(arr[j] > arr[j+1])
            {
                int temp;
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}
