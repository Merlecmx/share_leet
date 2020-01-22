/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* relativeSortArray(int* arr1, int arr1Size, int* arr2, int arr2Size, int* returnSize){
    int bucket[1001] = {0};
    int* arr = (int*)malloc(sizeof(int) * arr1Size);
    for (int i = 0; i < arr1Size; i++) {//统计数量并排序
        bucket[arr1[i]]++;
    }
    int index = 0;
    for (int i = 0; i < arr2Size; i++) {//与arr2相同的数按对应位置排序
        while (bucket[arr2[i]] > 0) {
            bucket[arr2[i]]--;
            arr[index++] = arr2[i];
        }
    }
    for (int i = 0; i < 1001; i++) {//剩余数排序
        while (bucket[i] > 0) {
            arr[index++] = i;
            bucket[i]--;
        }
    }
    *returnSize = arr1Size;
    return arr;
}
