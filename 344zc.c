void swap(char* a, char* b);
void reverseString(char* s, int sSize) {
    int i = 0, j = sSize - 1;
    for(i = 0; i < j; i++, j--) {
        swap(&s[i], &s[j]);
    }
}
void swap(char* a, char* b) {
    char temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
