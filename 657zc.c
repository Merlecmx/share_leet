bool judgeCircle(char * moves) {
    int count1 = 0, count2 = 0;
    int i = 0;
    while(*moves != '\0') {
        if(*moves == 'R')
            count1++;
        if(*moves == 'L')
            count1--;
        if(*moves == 'U')
            count2++;
        if(*moves == 'D')
            count2--;
        moves++;
    }
    return !count1 && !count2;
}
