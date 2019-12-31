int findLUSlength(char * a, char * b) {
    if(strcmp(a,b) == 0)
        return -1;
    else
        return (strlen(a) > strlen(b) ? strlen(a) : strlen(b));
}
