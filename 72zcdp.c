int FindMin(int a, int b){
    return a < b ? a : b;
}

int minDistance(char * word1, char * word2){
    int len_word1 = strlen(word1);
    int len_word2 = strlen(word2);
    int** dp = (int**)malloc(sizeof(int*) * (len_word1 + 1));
    for (int i = 0; i < len_word1 + 1; ++i) {
        dp[i] = (int*)calloc(sizeof(int) , (len_word2 + 1));
    }
    for (int i = 0; i <= len_word1; ++i) {
        dp[i][0] = i;
    }
    for (int j = 0; j <= len_word2; ++j) {
        dp[0][j] = j;
    }
    for (int i = 1; i <= len_word1; ++i) {
        for (int j = 1; j <= len_word2; ++j) {
            if (word1[i - 1] == word2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            } else {
                dp[i][j] = FindMin(dp[i - 1][j - 1], FindMin(dp[i][j - 1], dp[i - 1][j])) + 1;
            }
        }
    }
    return dp[len_word1][len_word2];
}
