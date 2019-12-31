char * reverseOnlyLetters(char * S) {
    int i = 0, j = strlen(S) - 1;
    char temp;
    while(i < j) {
        if(isalpha(S[i]) == 0) {
            i++;
            continue;
        }
        if(isalpha(S[j]) == 0) {
            j--;
            continue;
        }
        temp = S[i];
        S[i] = S[j];
        S[j] = temp;
        i++;
        j--;
    }
    return S;
}
