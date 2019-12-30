bool judgeCircle(char * moves) {
    int count1 = 0, count2 = 0;
    int i = 0;
    while(moves[i] != '\0') {
        for(i = 0; i < strlen(moves); i++) {
            if(moves[i] == 'R')
                count1++;
            if(moves[i] == 'L')
                count1--;
            if(moves[i] == 'U')
                count2++;
            if(moves[i] == 'D')
                count2--;
        }
    }
    if(count1 == 0 && count2 == 0)
        return 1;
    return 0;
}
