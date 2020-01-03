int strStr(char *haystack, char *needle) {
    int lenh = strlen(haystack);
    int lenn = strlen(needle);
    for (int i = 0; i < lenh - lenn +1; i++) {
        int j = 0;
        for (j; j < lenn; j++) {
            if (haystack[i + j] != needle[j]) break;
        }
        if (j == lenn) return i;
    }
    return -1;
}
