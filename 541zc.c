void ReverseString(char *S, int x, int y);
void Swap(char *a, char *b);
char *reverseStr(char *s, int k) {
    int len = strlen(s);
    int i = 0;
    int j = 0;
    int num = 1;
    while (i < len) {
        if (len-i < k) {
            j = len - 1;
        } else {
            j = i + k - 1;
        }
        ReverseString(s, i, j);
        i = 2 * k * num;
        num++;
    }
    return s;
}
void ReverseString(char *S, int x, int y) {
    while (x < y) {
        Swap(S + x, S + y);
        x++;
        y--;
    }
}
void Swap(char *a, char *b) {
    char temp1 = *a;
    *a = *b;
    *b = temp1;
}
