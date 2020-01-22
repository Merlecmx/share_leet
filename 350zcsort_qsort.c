/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int Partion (int* nums, int low, int high) {
    int temp = nums[low];
    while (low < high) {
        while (low < high && nums[high] >= temp) {
            high--;
        }
        nums[low] = nums[high];
        while (low < high && nums[low] <= temp) {
            low++;
        }
        nums[high] = nums[low];
    }
    nums[low] = temp;
    return low;
}
void QSort(int* nums, int low, int high) {
    if (low < high) {
        int flag = Partion(nums, low, high);
        QSort(nums, low, flag - 1);
        QSort(nums, flag + 1, high);
    }
}
int* intersect(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize){
    QSort(nums1, 0, nums1Size - 1);
    QSort(nums2, 0, nums2Size - 1);
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
