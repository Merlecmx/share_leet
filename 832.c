
int** flipAndInvertImage(int** A, int ARowSize, int *AColSizes, int** columnSizes, int* returnSize)
{
    int **Arr = malloc(ARowRizes*sizeof(int*));
    *columnSizes = malloc(ARowSize * sizeof(int));
    *returnSize = ARowSize;
    for (int i=0; i<ARowSize; i++)
    {
        (*columnSizes)[i] = AColSizes[i];
         Arr[i] = (int*)malloc(AColSizes[i]*sizeof(int)) ;
        for(int h=0; h<AColSizes[i]; h++)
        {

            Arr[i][h] = !A[i][AColSizes[i]-1-h] ;
        }
    }
    return Arr;
}
