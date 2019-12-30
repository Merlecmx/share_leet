char * toLowerCase(char * str) {
    char *answer = str;
    while(*str) {
        if(*str >= 'A' && *str <= 'Z') {
            *str = *str - 'A' + 'a';
        }
        str++;
    }
    return answer;
}
