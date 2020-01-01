char * reverseStr(char * s, int k) {
    int len = strlen(s);
    int i = 0, j, num = 1;
    while(i < len) {
        if(len-i < k)
            j = len - 1;
        else
            j = i + k - 1;
        while(i < j) {
            char temp;
            temp = s[i];
            s[i] = s[j];
            s[j] = temp;
            i++;
            j--;
        }
        i = 2*k*num;
        num++;
    }
    return s;
}
