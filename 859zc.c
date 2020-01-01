bool buddyStrings(char * A, char * B) {
    int lenA = strlen(A), lenB = strlen(B);
    int count = 0;
    if(lenA != lenB)
        return false;
    int ar[26] = {0};
    if(strcmp(A,B) == 0) {
        for(int i=0; i<lenA; i++) {
            ar[A[i] - 'a']++;
            if(ar[A[i] - 'a'] == 2)
                return true;
        }
    }
    int sum = 0;
    int temp1 = -1, temp2 = -1;
    for(int i=0; i<lenA; i++) {
        if(A[i] != B[i]) {
            sum++;
            if(sum == 1)
                temp1 = i;
            if(sum == 2)
                temp2 = i;
        }
    }
    if(sum != 2)
        return false;
    if(A[temp1] == B[temp2] && A[temp2] == B[temp1])
        return true;
    return false;
}
