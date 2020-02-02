int Cmp(const void *a, const void *b){
    return *(int*)a - *(int*)b;
}

int lastStoneWeight(int* stones, int stonesSize){
    for (int i = 0; i < stonesSize - 1; ++i) {
        qsort(stones, stonesSize, sizeof(int), Cmp);
        stones[stonesSize - 1] = stones[stonesSize - 1] - stones[stonesSize - 2];
        stones[stonesSize - 2] = 0;
    }
    return stones[stonesSize - 1];
}
