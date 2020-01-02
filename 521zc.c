int findLUSlength(char *a, char *b) {
    int lena = strlen(a);
    int lenb = strlen(b);
    if (strcmp(a,b) == 0) {
        return -1;
    } else {
        return lena > lenb ? lena : lenb;
    }
}
