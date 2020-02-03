bool divisorGame(int N){
    bool dp[1001];
    dp[1] = false;
    dp[2] = true;
    for ( int i = 3; i <= N; i++) {
        for (int j = 1; j < i; j++ ) {
            if (i % j == 0) {
                dp[i] = !dp[i - j];
                break;
            }
        }
    }
    return dp[N];
}
