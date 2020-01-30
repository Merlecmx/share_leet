int singleNumber(int* nums, int numsSize){
    int hash[50000] = {0};
    for (int i = 0; i < numsSize; i++) {
        hash[nums[i] + 25000]++;
    }
    for (int i = 0; i < 50000; i++) {
        if (hash[i] == 1) return i - 25000;
    }
    return 0;
}
