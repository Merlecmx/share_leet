/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
void InsertSort(int* A, int ASize) {
    A[0] = A[0] * A[0];
    int j = 0;
    for (int i = 1; i < ASize; i++) {
        int temp = A[i] * A[i];
        for (j = i - 1; j >= 0; j--) {
            if (temp < A[j]) {
                A[j + 1] = A[j];
            } else {
                break;
            }
        }
        A[j + 1] = temp;
    }
}
int* sortedSquares(int* A, int ASize, int* returnSize) {
    *returnSize = ASize;
    if (ASize == 0) return A;
    InsertSort(A, ASize);
    return A;
}
