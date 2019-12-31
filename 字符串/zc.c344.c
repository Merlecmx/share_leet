void reverseString(char* s, int sSize) {
    int i = 0, j = sSize - 1;
    char temp = 0;
    for(i = 0; i < j; i++) {
        temp = s[i];
        s[i] = s[j];
        s[j] = temp;
        j--;
    }
    return s;
}
