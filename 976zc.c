
int largestPerimeter(int* A, int ASize)
{
    for(int i=0; i<ASize-1;i++)
    {
        for(int j=0; j<ASize-1-i; j++)
        {
            if(A[j] > A[j+1])
            {
                int temp;
                temp = A[j];
                A[j] = A[j+1];
                A[j+1] =temp;
            }
        }
    }
    int max = 0;
    for(int a=ASize-1; a>1; a--)
    {
        if(A[a] < (A[a-1] + A[a-2]))
        {
            max = A[a] + A[a-1] + A[a-2];
            return max;
        }
    }
    return 0;
}
