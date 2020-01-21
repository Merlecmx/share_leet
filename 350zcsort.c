/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
//插排
void InsertSort(int* nums, int size) {
    int i, j , temp;
    for (i = 1; i < size; i++) {
        temp = nums[i];
        for(j = i; j > 0 && nums[j - 1] >= temp; j--) {
            nums[j] = nums[j - 1];
        }
        nums[j] = temp;
    }
}
int* intersect(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize){
    InsertSort(nums1, nums1Size);
    InsertSort(nums2, nums2Size);
    int i = 0, j = 0, index = 0;
    while(i < nums1Size && j < nums2Size) {
        if (nums1[i] < nums2[j]) {
            i++;
        } else if (nums1[i] > nums2[j]) {
            j++;
        } else {
            nums1[index++] = nums1[i];
            i++;
            j++;
        }
    }
    int* arr = (int*)malloc(sizeof(int) * index);
    for (int i = 0; i < index; i++) {
        arr[i] = nums1[i];
    }
    *returnSize = index;
    return arr;
}
//快排
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int cmp(const void* a, const void* b) {
    if (*(int*)a > *(int*)b) {
        return 1;
    } else if (*(int*)a < *(int*)b) {
        return -1;
    } else if (*(int*)a == *(int*)b) {
        return 0;
    }
    return 0;
}
int* intersect(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize){
    qsort(nums1, nums1Size, sizeof(nums1[0]), cmp);
    qsort(nums2, nums2Size, sizeof(nums2[0]), cmp);
    int i = 0, j = 0, index = 0;
    while(i < nums1Size && j < nums2Size) {
        if (nums1[i] < nums2[j]) {
            i++;
        } else if (nums1[i] > nums2[j]) {
            j++;
        } else {
            nums1[index++] = nums1[i];
            i++;
            j++;
        }
    }
    int* arr = (int*)malloc(sizeof(int) * index);
    for (int i = 0; i < index; i++) {
        arr[i] = nums1[i];
    }
    *returnSize = index;
    return arr;
}
