bool isSubsequence(char * s, char * t){
    int i = 0, j = 0;
    for (i, j; s[i] != 0 && t[j] != 0; j++) {
        if (s[i] == t[j]) {
            i++;
        }
    }
    return i == strlen(s);
}
