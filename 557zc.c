char * reverseWords(char * s) {
    int i = 0, j = 1;
    int flag = 0;
    char temp = 0;
    while(j < strlen(s)) {
        while(s[j] != '\0') {
            if(s[j] == '\0' || s[j] == ' ')
                break;
            j++;
        }
        flag = j + 1;
        while(i < j-1) {
            temp = s[i];
            s[i] = s[j-1];
            s[j-1] = temp;
            i++;
            j--;
        }
        i = flag;
        j = flag + 1;
        flag = 0;
    }
    return s;
}
