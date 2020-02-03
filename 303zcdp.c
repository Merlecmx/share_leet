typedef int  NumArray;

NumArray* numArrayCreate(int* nums, int numsSize) {
    for (int i = 1; i < numsSize; ++i) {
        nums[i] += nums[i - 1];
    }
    return nums;
}

int numArraySumRange(NumArray* obj, int i, int j) {
    if (i == 0) return obj[j];
    return obj[j] - obj[i - 1];
}

void numArrayFree(NumArray* obj) {
    return;
}

/**
 * Your NumArray struct will be instantiated and called as such:
 * NumArray* obj = numArrayCreate(nums, numsSize);
 * int param_1 = numArraySumRange(obj, i, j);

 * numArrayFree(obj);
*/
