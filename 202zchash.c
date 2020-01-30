int ans[800] = {0};
int getsum(int n) {
    int tmp = 0;
    int ans = 0;
    while (n != 0) {
        tmp = n % 10;
        ans += tmp * tmp;
        n = n / 10;
    }
    return ans;
}
bool isHappy(int n) {
    n = getsum(n);
    if(n == 1) return true;
    while (ans[n] != 1) {
        ans[n] = 1;
        n = getsum(n);
        if(n == 1) return true;
    }
    return false;
}
