void reverseString(char* S, int x, int y);
char * reverseWords(char * s) {
    int i = 0, j = 1;
    int flag = 0;
    char temp = 0;
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
        flag = 0;
    }
    return s;
}
void swap(char* a, char* b);
void reverseString(char* S, int x, int y) {
    while(x < y) {
        swap(&S[x], &S[y]);
        x++;
        y--;
    }
}
void swap(char* a, char* b) {
    char temp1;
    temp1 = *a;
    *a = *b;
    *b = temp1;
}
