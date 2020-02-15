int Cmp(const void* a, const void* b){
    return *(int*)a - *(int*)b;
}

int twoCitySchedCost(int** costs, int costsSize, int* costsColSize){
    int* arr = (int*)malloc(sizeof(int) * costsSize);
    int index = 0, sum = 0, flagA = 0, flagB = 0;
    for (int i = 0; i < costsSize; ++i) {
        arr[index++] = costs[i][0] - costs[i][1];
        sum += costs[i][1];
    }
    qsort(arr, index, sizeof(int), Cmp);
    int midsize = costsSize / 2;
    for (int i = 0; i < midsize; ++i) {
        sum += arr[i];
    }
    free(arr);
    return sum;
}
