
int* sortArrayByParity(int* A, int ASize, int* returnSize){
    *returnSize = ASize;
    int a = 0,b = ASize-1;
    int* returnarray = malloc(ASize * sizeof(int));
    for(int i = 0;i<ASize;i++){
        if(A[i]%2==0){
            returnarray[a] = A[i];
            a++;
        }else{
            returnarray[b] = A[i];
        b--;
        }
    }
    return returnarray;
}
