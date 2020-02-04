char* longestPalindrome(char * s){
    int len = strlen(s);
    int low = 0, high = 0;
    int dp[1000][1000] = {0};
    for (int i = 0; i < len; ++i) {
        dp[i][i] = 1;//单字符是回文串
    }
    for (int r = 1; r < len; ++r) {
        for (int l = 0; l < r; ++l) {
            if (s[r] == s[l] && (r - l == 1 || dp[l + 1][r - 1])) {//两边相等中间为回文串，则当前字符串是回文串
                dp[l][r] = 1;
                if (r - l > high - low) {//存放最长回文串
                    low = l;
                    high = r;
                }
            } else {
                dp[l][r] = 0;
            }
        }
    }
    char* res = (char*)malloc(sizeof(char) * (high - low + 2));
    int index = 0;
    while (low <= high) {
        res[index++] = s[low++];
    }
    res[index] = '\0';
    return res;
}
