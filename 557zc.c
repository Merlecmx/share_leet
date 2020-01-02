void ReverseString(char *S, int x, int y);
void Swap(char *a, char *b);
char *reverseWords(char *s) {
    int i = 0;
    int j = 1;
    int flag = 0;
    while (j < strlen(s)) {
        while (s[j]) {
            if( s[j] == ' ')
                break;
            j++;
        }
        flag = j + 1;
        ReverseString(s, i, j-1);
        i = flag;
        j = flag + 1;
    }
    return s;
}
void RverseString(char *S, int x, int y) {
    while (x < y) {
        Swap(S + i, S + i);
        x++;
        y--;
    }
}
void Swap(char *a, char *b) {
    char temp1 = *a;
    *a = *b;
    *b = temp1;
}
