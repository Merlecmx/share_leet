int** generate(int numRows, int** columnSizes)
{
    int i,j;
    int** Array = (int**)malloc(sizeof(int*)*numRows);
     *columnSizes =(int*)malloc(numRows*sizeof(int*));
    for(i=0; i<numRows; i++)
    {
        (*columnSizes)[i] = i + 1;
        Array[i] = (int *)malloc(sizeof(int*)*(*columnSizes)[i]);
        Array[i][0] = 1;
        for(j=1; j<i+1; j++)
       {
          Array[i][j] = Array[i-1][j-1] + Array[i-1][j];
       }
    }
    return Array;
}
