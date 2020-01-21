/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
//1哈希表
int* intersection(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize){
    int arrSize = nums1Size > nums2Size ? nums2Size : nums1Size;
    int* arr = (int*)malloc(sizeof(int) * arrSize);
    int hash[1000] = {0};
    int size = 0;
    for (int i = 0; i < nums1Size; i++) {
        hash[nums1[i]] = 1;
    }
    for (int j = 0; j < nums2Size; j++) {
        if (hash[nums2[j]] == 1) {
            arr[size++] = nums2[j];
            hash[nums2[j]] = 0;
        }
    }
    *returnSize = size;
    return arr;
}
//2暴力循环
int* intersection(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize){
    int arrSize = nums1Size > nums2Size ? nums2Size : nums1Size;
    int* arr = (int*)malloc(sizeof(int) * arrSize);
    int size = 0;
    for (int i = 0; i < nums1Size; i++) {
        for (int j = 0; j < nums2Size; j++) {
            if (nums1[i] == nums2[j]) {
                int flag = 0;
                for (int k = 0; k < size; k++) {
                    if (arr[k] == nums1[i]) {
                        flag = 1;
                    }
                }
                if (!flag) {
                    arr[size++] = nums2[j];
                }
            }
        }
    }
    *returnSize = size;
    return arr;
}
