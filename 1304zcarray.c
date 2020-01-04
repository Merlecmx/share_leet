/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sumZero(int n, int* returnSize) {
    *returnSize = n;
    int* answer = (int*)malloc(sizeof(int) * n);
    int sum = 0;
    for (int i = 1; i < n; i++) {
        sum += i;
        answer[i - 1] = i;
    }
    answer[n - 1] = -sum;
    return answer;
}
