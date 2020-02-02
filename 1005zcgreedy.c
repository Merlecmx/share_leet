int largestSumAfterKNegations(int* A, int ASize, int K){
    int* hash = (int*)calloc(sizeof(int), 201);
    for (int i = 0; i < ASize; ++i) {
        hash[A[i] + 100]++;
    }
    int i = 0;
    while (K > 0) {
        while (hash[i] == 0) {//找出原数组最小值
            i++;
        }
        hash[i]--;//最小值取反，就少一个
        hash[200 - i]++;//最小值取反的后的值加一个
        if (i > 100) {
            i = 200 - i;//最小值的下标大于100时，此时最小值为正数，取反后变为负数，找出新的最小值下标
        }
        K--;
    }
    int sum = 0;
    for (int j = i; j < 201; ++j) {
        sum += (j - 100) * hash[j];//hash里存放的是对应值的数量
    }
    return sum;
}
