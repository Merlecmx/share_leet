typedef int NumArray;

NumArray* numArrayCreate(int* nums, int numsSize) {
    if (numsSize == 0) return NULL;
    NumArray* obj = (NumArray*)calloc(sizeof(NumArray), numsSize);
    obj[0] = nums[0];
    for (int i = 1; i < numsSize; ++i) {
        obj[i] = nums[i] + obj[i - 1];
    }
    return obj;
}

int numArraySumRange(NumArray* obj, int i, int j) {
    if (i == 0) return obj[j];
    return obj[j] - obj[i - 1];
}

void numArrayFree(NumArray* obj) {
    if (obj);
    free(obj);
}

/**
 * Your NumArray struct will be instantiated and called as such:
 * NumArray* obj = numArrayCreate(nums, numsSize);
 * int param_1 = numArraySumRange(obj, i, j);

 * numArrayFree(obj);
*/
