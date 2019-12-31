bool buddyStrings(char * A, char * B) {
    int lenA = strlen(A), lenB = strlen(B);
    int count = 0;
    if(lenA != lenB)
        return 0;
    if(strcmp(A,B) == 0) {
        for(int i=0; i<lenA-1; i++) {
            for(int j=i+1; j<lenA; j++) {
                if(A[i] == B[j])
                    return 1;
            }
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
        return 0;
    if(A[temp1] == B[temp2] && A[temp2] == B[temp1])
        return 1;
    return 0;
}
