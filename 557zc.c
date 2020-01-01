void reverseString(char* S, int x, int y);
void swap(char* a, char* b);
char * reverseWords(char * s) {
    int i = 0, j = 1;
    int flag = 0;
    while(j < strlen(s)) {
        while(s[j] != '\0') {
            if(s[j] == ' ')
                break;
            j++;
        }
        flag = j + 1;
        reverseString(s, i, j-1);
        i = flag;
        j = flag + 1;
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
