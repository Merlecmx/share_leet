int balancedStringSplit(char * s){
    int flag = 0, count = 0;
    for (int i = 0; s[i] != 0; ++i) {
        if (s[i] == 'R') flag++;
        if (s[i] == 'L') flag--;
        if (flag == 0) count++;
    }
    return count;
}
