int* fairCandySwap(int* A, int ASize, int* B, int BSize, int* returnSize)
{
    int sumA = 0;
    int sumB = 0;
    int number = 0;
    int * arr = malloc(sizeof(int) * 2);
    *returnSize = 2;
    for (int i=0; i<ASize; i++)
    {
        sumA += A[i];
    }
    for (int i=0; i<BSize; i++)
    {
        sumB += B[i];
    }

    if (sumA == sumB)
    {
        arr[0] = A[0];
        arr[1] = A[0];
        return arr;
    }

    int average = (sumA+sumB) / 2;

    if (sumA > sumB)
    {
        number = sumA - average;
        for (int i=0; i<ASize; i++)
        {
            for (int j=0; j<BSize; j++)
            {
                if (A[i]-number == B[j])
                {
                    arr[0] = A[i];
                    arr[1] = B[j];
                    return arr;
                }
            }
        }
    }
    else
    {
        number = average - sumA;
        for (int i=0; i<ASize; i++)
        {
            for (int j=0; j<BSize; j++)
            {
                if (A[i]+number == B[j])
                {
                   arr[0] = A[i];
                   arr[1] = B[j];
                    return arr;
                }
            }
        }
    }

    return 0;

}
