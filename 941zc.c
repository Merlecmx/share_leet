bool validMountainArray(int* A, int ASize)
{
    if(ASize < 3)
        return false;
    int maxindex = -1;
    int maxA = INT_MIN;
    for(int i=0; i<ASize; i++)
    {
        if(A[i] >= maxA)
        {
            maxA = A[i];
            maxindex = i;
        }
    }
    if(maxindex == 0 || maxindex == ASize-1)
    {
        return false;
    }
    for(int i=0; i<maxindex; i++)
    {
        if(A[i] >= A[i+1])
        {
            return false;
        }
    }
    for(int i=maxindex; i<ASize-1; i++)
    {
        if(A[i] <= A[i+1])
        {
            return false;
        }
    }
    return true;
}
