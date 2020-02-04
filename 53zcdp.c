int Max(int a, int b){
    return a > b ? a : b;
}

int maxSubArray(int* nums, int numsSize){
    int curr_sum = nums[0], max_sum = nums[0];
    for (int i = 1; i < numsSize; i++){
        curr_sum = Max(nums[i], curr_sum + nums[i]);
        max_sum = Max(curr_sum, max_sum);
    }
    return max_sum;
}
