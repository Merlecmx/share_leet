int* nextGreaterElement(int* findNums, int findNumsSize, int* nums, int numsSize, int* returnSize){
    int* a = (int*)malloc(sizeof(int) * findNumsSize);
    memset(a,-1,findNumsSize * sizeof(int));
    *returnSize = findNumsSize;
    for (int i = 0; i < findNumsSize; i++) {
        int mark = 0;
        for (int j = 0;j < numsSize;j++) {
            if (findNums[i] == nums[j]) mark = 1;
            if (findNums[i] < nums[j] && mark == 1) {
                a[i] = nums[j];
                break;
            }
        }
    }
    return a;
}
