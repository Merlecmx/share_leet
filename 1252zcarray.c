int oddCells(int n, int m, int** indices, int indicesSize, int* indicesColSize) {
    int row[50] = {0};
    int col[50] = {0};
    for (int i = 0; i < indicesSize; i++) {
        row[indices[i][0]]++;
        col[indices[i][1]]++;
    }
    int sum = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if((row[i] + col[j]) % 2) {
                sum++;
            }
        }
    }
    return sum;
}
