int climbStairs(int n){
    if (n == 1) return 1;
    int* dp = (int*)malloc(sizeof(int) * (n + 1));
    dp[1] = 1;
    dp[2] = 2;
    for (int i = 3; i < n + 1; ++i) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    int sum = dp[n];
    free(dp);
    return sum;
}
