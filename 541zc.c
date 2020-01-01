void reverseString(char* S, int x, int y);
void swap(char* a, char* b);
char * reverseStr(char * s, int k) {
    int len = strlen(s);
    int i = 0, j = 0, num = 1;
    while(i < len) {
        if(len-i < k)
            j = len - 1;
        else
            j = i + k - 1;
        reverseString(s, i, j);
        i = 2*k*num;
        num++;
    }
    return s;
}
void reverseString(char* S, int x, int y) {
    while(x < y) {
        swap(&S[x], &S[y]);
        x++;
        y--;
    }
}
void swap(char* a, char* b) {
    char temp1 = *a;
    *a = *b;
    *b = temp1;
}
