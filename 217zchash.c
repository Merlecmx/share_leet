int cmp(const void *a, const void *b)
{
    return *(int*)a - *(int*)b;
}

bool containsDuplicate(int* nums, int numsSize){
    if ((nums == NULL) || (numsSize == 0)) {
        return false;
    }
    qsort(nums, numsSize, sizeof(int), cmp);// 快排求出原数组中最大、最小整数
    int min, max;
    min = nums[0];
    max = nums[numsSize - 1];
    int *hashArray = NULL;
    int hashSize;
    if (min < 0) {
        hashSize = max + 1 - min;
        hashArray = (int*)calloc(hashSize, sizeof(int));
        for (int i = 0; i < numsSize; i++) {
            hashArray[nums[i] - min]++;
            if (hashArray[nums[i] - min] >= 2) {
                free(hashArray);
                return true;
            }
        }
    } else {
        hashSize = max + 1;
        hashArray = (int*)calloc(hashSize, sizeof(int));
        for (int i = 0; i < numsSize; i++) {
            hashArray[nums[i]]++;
            if (hashArray[nums[i]] >= 2) {
                free(hashArray);
                return true;
            }
        }
    }
    free(hashArray);
    return false;
}
