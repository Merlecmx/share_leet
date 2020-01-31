typedef struct hash {
    int data;
    int index;
} myhash;

int cmp(const void* a, const void* b) {
    return (((myhash*)a)->data < ((myhash*)b)->data) ? -1 : 1;
}

bool containsNearbyDuplicate(int* nums, int numsSize, int k){
    if (numsSize < 2 || nums == NULL) {
        return false;
    }
    myhash* hashArray = (myhash*)malloc(sizeof(myhash) * numsSize);
    for (int i = 0; i < numsSize; i++) {
        (&hashArray[i])->data = nums[i];
        (&hashArray[i])->index = i;
    }
    qsort(hashArray, numsSize, sizeof(myhash), cmp);
    int i = 0;
    myhash cmphash = hashArray[i];
    for (i = 1; i < numsSize; i++) {
        if ((&cmphash)->data == (&hashArray[i])->data && abs((&cmphash)->index - (&hashArray[i])->index) <= k) {
            return true;
        }
        cmphash = hashArray[i];
    }
    return false;
}
