int MaxValue(int* nums, int numsSize) {
    int max = nums[0];
    for (int i = 1; i < numsSize; i++) {
        if (max < nums[i]) {
            max = nums[i];
        }
    }
    return max;
}

int MinValue(int* nums, int numsSize) {
    int min = nums[0];
    for (int i = 1; i < numsSize; i++) {
        if (min > nums[i]) {
            min = nums[i];
        }
    }
    return min;
}

bool containsDuplicate(int* nums, int numsSize) {
    if (nums == NULL || numsSize == 0) return false;
    int max = MaxValue(nums, numsSize);
    int min = MinValue(nums, numsSize);
    int hashSize = max + 1 - min;
    int* hashArray = (int*)calloc(hashSize, sizeof(int));
    for (int i = 0; i < numsSize; i++) {
        hashArray[nums[i] - min]++;
        if (hashArray[nums[i] - min] >= 2) {
            free(hashArray);
            return true;
        }
    }
    free(hashArray);
    return false;
}
