int Cmp(const void* a, const void* b){
    return *(int*)a - *(int*)b;
}

int findContentChildren(int* g, int gSize, int* s, int sSize){
    qsort(g, gSize, sizeof(int), Cmp);
    qsort(s, sSize, sizeof(int), Cmp);
    int i = 0, j = 0, count = 0;
    while (i < gSize && j < sSize) {
        if (s[j] >= g[i]) {
            j++;
            i++;
            count++;
        } else {
            j++;
        }
    }
    return count;
}
