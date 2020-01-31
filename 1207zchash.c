bool uniqueOccurrences(int* arr, int arrSize){
    int hash1[10000] = {0};
    int hash2[10000] = {0};
    for (int i = 0; i < arrSize; i++) {
        if (arr[i] < 0) {
            hash1[arr[i] * -1]++;//hash1存放数组中每个数的数量
        } else {
            hash1[arr[i] + 1000]++;
        }
    }
    for (int i = 0; i < 10000; i++) {
        if (hash1[i] > 0) {
            hash2[hash1[i]]++;//hash2存放hash1中每个数的数量
        }
        if (hash2[hash1[i]] > 1) {//当hash1中有相同的数
            return false;
        }
    }
    return true;
}
