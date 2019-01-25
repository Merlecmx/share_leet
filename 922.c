int* sortArrayByParityII(int* A, int ASize, int* returnSize) {
   *returnSize = ASize;
   int  *returnArray = malloc(ASize * sizeof(int));
    int a = 0,b = 1;
    for(int i = 0;i<ASize;i++){
        if(A[i]%2==0){
            returnArray[a] = A[i];
            a += 2;
        }else{
            returnArray[b] = A[i];
            b += 2;
        }
    }
    return returnArray;
}
