int findNumbers(int *nums, int numsSize) {
    int count = 0;
    int anser = 0;
    for (int i = 0; i < numsSize; i++) {
        count = 0;
        while (nums[i] > 0) {
            nums[i] /= 10;
            count++;
        }
        if (count % 2 == 0) {
            anser++;
        }
    }
    return anser;
}
