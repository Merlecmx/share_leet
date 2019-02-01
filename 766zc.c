bool isToeplitzMatrix(int** matrix, int matrixRowSize, int *matrixColSizes)
{
    for(int i=0; i<matrixRowSize; i++)
    {
        for(int j=0; j<(*matrixColSizes); j++)
        {
            int a = i;
            int b = j;
            while(i+1 < matrixRowSize && j+1 < (*matrixColSizes))
            {
                if(matrix[i][j] != matrix[++i][++j])
                {
                    return false;
                }
            }
            i = a;
            j = b;
        }
    }
    return true;
}
