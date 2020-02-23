void Next(char* T, int* next){
    int i = 1;
    next[i] = 0;
    int j = 0;
    int len_T = strlen(T);
    while (i < len_T) {
        if (j == 0 || T[i - 1] == T[j - 1]) {
            i++;
            j++;
            if (T[i - 1] != T[j - 1]) {
                next[i] = j;
            } else {
                next[i] = next[j];
            }
        } else {
            j = next[j];
        }
    }
}

int strStr(char *haystack, char *needle) {
    if (!haystack || !needle) return -1;
    int len_n = strlen(needle);
    if (len_n == 0) return 0;
    int len_h = strlen(haystack);
    int* next = (int*)calloc(sizeof(int) , len_n + 1);
    Next(needle, next);
    int i = 1, j = 1;
    while (i <= len_h && j <= len_n) {
        if (j == 0 || haystack[i - 1] == needle[j - 1]) {
            i++;
            j++;
        } else {
            j = next[j];
        }
    }
    if (j > len_n) {
        return i - len_n - 1;
    }
    free(next);
    return -1;
}
