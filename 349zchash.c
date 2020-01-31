

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* intersection(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize){
    int *res = (int*)malloc(sizeof(int));
    int hash[1000] = {0};
    for (int i = 0; i < nums1Size; i++) {
        hash[nums1[i]] = 1;
    }
    int length = 0;
    for (int i = 0; i < nums2Size; i++) {
        if (hash[nums2[i]] == 1) {
            res = (int*)realloc(res, ++length * sizeof(int));
            res[length - 1] = nums2[i];
            hash[nums2[i]] = 0;
        }
    }
    *returnSize = length;
    return res;
}

