bool checkRecord(char * s) {
    char len = strlen(s);
    int a = 0, l = 0;
    while(*s != '\0') {
        if(*s == 'A')
            a++;
        if(*s == 'L')
            l++;
        else
            l = 0;
        if(a > 1 || l > 2)
            return false;
        s++;
    }
    return true;
}
