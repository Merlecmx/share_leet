int singleNumber(int* nums, int numsSize){
    if (numsSize == 1) return nums[0];
    int a = 0;
    for (int i = 0; i < numsSize; i++) {
        a ^= nums[i];
    }
    return a;
}
