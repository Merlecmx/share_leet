void Swap(int* a, int* b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
void BubbleSort(int* h, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (h[j] > h[j + 1]) {
                Swap(h + j, h + (j + 1));
            }
        }
    }
}
int heightChecker(int* heights, int heightsSize) {
    int Heights[100] = {0};
    for (int i = 0; i < heightsSize; i++) {
        Heights[i] = heights[i];
    }
    BubbleSort(heights, heightsSize);
    int count = 0;
    for (int i = 0; i < heightsSize; i++) {
        if (heights[i] != Heights[i]) {
            count++;
        }
    }
    return count;
}
