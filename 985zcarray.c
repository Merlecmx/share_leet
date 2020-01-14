/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sumEvenAfterQueries(int* A, int ASize, int** queries, int queriesSize, int* queriesColSize, int* returnSize) {
    *returnSize = queriesSize;
    int* arr = (int*)malloc(sizeof(int) * queriesSize);
    int sum = 0;//A数组偶数和
    for (int i = 0; i < ASize; i++) {
        if (A[i] % 2 == 0) {
            sum += A[i];
        }
    }
    for (int i = 0; i < queriesSize; i++) {
        int val = queries[i][0];;
        int index = queries[i][1];
        if (A[index] % 2 == 0) {//判断将要改变的值是不是偶数，如果是偶数就删除
            sum -= A[index];
        }
        A[index] += val;
        if (A[index] % 2 == 0) {//加过val的值是偶数，就加到sum
            sum += A[index];
        }
        arr[i] = sum;
    }
    return arr;
}
