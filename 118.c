int** generate(int numRows, int** columnSizes)
{
    int i,j;
    int** array = (int**)malloc(sizeof(int*)*numRows);
     *columnSizes =(int*)malloc(numRows*sizeof(int*));
    for(i=0; i<numRows; i++)
    {
        (*columnSizes)[i] = i + 1;
        array[i] = (int *)malloc(sizeof(int*)*(*columnSizes)[i]);
        array[i][0] = 1;
        for(j=1; j<i+1; j++)
       {
          array[i][j] = array[i-1][j-1] + array[i-1][j];
       }
    }
    return array;
}
