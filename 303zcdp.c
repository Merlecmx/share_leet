typedef int NumArray;

NumArray* numArrayCreate(int* nums, int numsSize) {
    NumArray* obj = (NumArray*)calloc(sizeof(NumArray), numsSize);
    for (int i = 0; i < numsSize; ++i) {
        obj[i] = nums[i];
    }
    return obj;
}

int numArraySumRange(NumArray* obj, int i, int j) {
    int sum = 0;
    for (i; i <= j; ++i) {
        sum += obj[i];
    }
    return sum;
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
