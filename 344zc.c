void Swap(char *a, char *b);
void reverseString(char *s, int sSize) {
    int i = 0;
    int j = sSize - 1;
    for (i = 0; i < j; i++, j--) {
        Swap(s + i, s + j);
    }
}
void Swap(char *a, char *b) {
    char temp = *a;
    *a = *b;
    *b = temp;
}
