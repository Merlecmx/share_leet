/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sumEvenAfterQueries(int* A, int ASize, int** queries, int queriesSize, int* queriesColSize, int* returnSize) {
    *returnSize = queriesSize;
    int* arr = (int*)malloc(sizeof(int) * queriesSize);
    int sum = 0;//A����ż����
    for (int i = 0; i < ASize; i++) {
        if (A[i] % 2 == 0) {
            sum += A[i];
        }
    }
    for (int i = 0; i < queriesSize; i++) {
        int val = queries[i][0];;
        int index = queries[i][1];
        if (A[index] % 2 == 0) {//�жϽ�Ҫ�ı��ֵ�ǲ���ż���������ż����ɾ��
            sum -= A[index];
        }
        A[index] += val;
        if (A[index] % 2 == 0) {//�ӹ�val��ֵ��ż�����ͼӵ�sum
            sum += A[index];
        }
        arr[i] = sum;
    }
    return arr;
}
