int Max(int a, int b){
    return a > b ? a : b;
}

int rob(int* nums, int numsSize){
    int prevMax = 0, currMax = 0;
    for (int i = 0; i < numsSize; ++i) {
        int temp = currMax;
        currMax = Max(prevMax + nums[i], currMax);
        prevMax = temp;
    }
    return currMax;
}
