bool isToeplitzMatrix(int** matrix, int matrixRowSize, int *matrixColSizes)
{
    for(int i=0; i<matrixRowSize; i++)
    {
        for(int j=0; j<(*matrixColSizes); j++)
        {
            int a = i;
            int b = j;
            while(a+1 < matrixRowSize && b+1 < (*matrixColSizes))
            {
                if(matrix[a][b] != matrix[++a][++b])
                {
                    return false;
                }
            }
        }
    }
    return true;
}
