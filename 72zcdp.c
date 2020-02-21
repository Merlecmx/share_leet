int FindMin(int a, int b){
    return a < b ? a : b;
}

int minDistance(char * word1, char * word2){
    int len_word1 = strlen(word1);
    int len_word2 = strlen(word2);
    int d[len_word1 + 1][len_word2 + 1];
    for (int i = 0; i <= len_word1; ++i) {
        d[i][0] = i;
    }
    for (int j = 0; j <= len_word2; ++j) {
        d[0][j] = j;
    }
    for (int i = 1; i <= len_word1; ++i) {
        for (int j = 1; j <= len_word2; ++j) {
            if (word1[i - 1] == word2[j - 1]) {
                d[i][j] = d[i - 1][j - 1];
            } else {
                int leftup = d[i - 1][j - 1];
                int left = d[i][j - 1];
                int up = d[i - 1][j];
                d[i][j] = FindMin(leftup, FindMin(left, up)) + 1;
            }
        }
    }
    return d[len_word1][len_word2];
}
