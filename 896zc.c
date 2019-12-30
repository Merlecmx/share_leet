bool isMonotonic(int* A, int ASize)
{
    if(A[0] < A[ASize-1])
    {
        for(int i=1; i<ASize; i++)
        {
            if(A[i-1] > A[i])
            {
                return false;
            }
        }
    }
    else
    {
        for(int j=1; j<ASize; j++)
        {
            if(A[j-1] < A[j])
            {
                return false;
            }
        }
    }
    return true;
}
