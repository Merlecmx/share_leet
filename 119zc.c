int* getRow(int rowIndex, int* returnSize)
{
    *returnSize = rowIndex + 1;
    int* num = malloc(sizeof(int)*(rowIndex + 1));;
    for(int i=0; i<=rowIndex; i++)
    {
        for(int j = i; j>=0; j--)
        {
            if(j == 0 || j == i)
            {
                num[j] = 1;
            }
            else
            {
                num[j] = num[j] + num[j-1];
            }
        }
    }
    return num;
}
