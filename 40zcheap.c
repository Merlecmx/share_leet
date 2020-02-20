/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#define leftchildIdx(i) (2 * (i) + 1)
void Swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void HeapSort(int* arr, int i, int n){
    int child;
    int temp;
    for (temp = arr[i]; leftchildIdx(i) < n; i = child) {
        child = leftchildIdx(i);
        if (child != n - 1 && arr[child + 1] > arr[child]) {
            child++;
        }
        if (temp < arr[child]) {
            arr[i] = arr[child];
        } else {
            break;
        }
    }
    arr[i] = temp;
}

int* getLeastNumbers(int* arr, int arrSize, int k, int* returnSize){
    int i = 0;
    for (i = arrSize / 2; i >= 0; --i) {
        HeapSort(arr, i, arrSize);//buidheap
    }
    for (i = arrSize - 1; i > 0; --i) {
        Swap(arr, arr + i);//delete max,把最大值放在最后
        HeapSort(arr, 0, i);//维护前n-1的堆
    }
    int* res = (int*)malloc(sizeof(int) * k);
    int index = 0;
    for (i = 0; i < k; ++i) {
        res[index++] = arr[i];
    }
    *returnSize = index;
    return res;
}
