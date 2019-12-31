bool detectCapitalUse(char * word) {
    int count = 0, sum;
    char flag = *word;
    sum = strlen(word);
    while (*word != NULL) {
        if (*word >= 'A' && *word <= 'Z')
            count++;
        word++;
    }
    if (flag >= 'A' && flag <= 'Z' && count == 1)
        return true;
    else if (count == 0)
        return true;
    else if (count == sum)
        return true;
    return false;
}
