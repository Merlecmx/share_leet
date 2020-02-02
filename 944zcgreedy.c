int minDeletionSize(char ** A, int ASize){
    int count = 0;
    int col = strlen(A[0]);
    for (int c = 0; c < col; ++c) {
        for (int r = 0; r < ASize - 1; ++r) {
            if (A[r][c] > A[r+1][c]) {
                count++;
                break;
            }
        }
    }
    return count;
}
