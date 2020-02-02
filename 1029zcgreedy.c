int Cmp(const void* a, const void* b){
    return *(int*)a - *(int*)b;
}

int twoCitySchedCost(int** costs, int costsSize, int* costsColSize){
    int* arr = (int*)malloc(sizeof(int) * costsSize);
    int index = 0, sum = 0, flagA = 0, flagB = 0;
    for (int i = 0; i < costsSize; ++i) {
        arr[index++] = costs[i][0] - costs[i][1];
    }
    qsort(arr, index, sizeof(int), Cmp);
    int midindex = costsSize / 2;
    int tempA = arr[midindex - 1];
    int tempB = arr[midindex];
    for (int i = 0; i < costsSize; ++i) {
        int temp = costs[i][0] - costs[i][1];
        if (temp < tempA) {
            sum += costs[i][0];
            flagA++;
        } else if (temp > tempB) {
            sum += costs[i][1];
            flagB++;
        }
    }
    for (int i = 0; i < costsSize; ++i) {
        int temp = costs[i][0] - costs[i][1];
        if (temp == tempA) {
            if (flagA < midindex) {//在当前值与中间值相等时，判断去A的人是否已经够了
                sum += costs[i][0];
                flagA++;
            } else {
                sum += costs[i][1];
                flagB++;
            }
        } else if (temp == tempB) {
            if (flagB < midindex) {
                sum += costs[i][1];
                flagB++;
            } else {
                sum += costs[i][0];
                flagA++;
            }
        }
    }
    return sum;
}
