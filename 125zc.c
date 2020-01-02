int sum(char *p);
void save(char *v, char *e, int a);
int sum(char *p) {
    int len = strlen(p);
    int i = 0;
    int count = 0;
    while (p[i] != '\0') {
        if ((p[i] <'0' || p[i] > '9') && (p[i] < 'a' || p[i] > 'z') && (p[i] < 'A' || p[i] > 'Z')) {//统计无效字符数
            count++;
        }
        i++;
    }
    return len - count;
}
void save(char *v, char *e, int a) {
    int tmp = 0;
    int i = 0;
    while (e[i] != '\0' && tmp < a) {
        if ((e[i] >= '0' && e[i] <= '9') || (e[i] >= 'a' && e[i] <= 'z')) {
            v[tmp] = e[i];
            tmp++;
        } else if (e[i] >= 'A' && e[i] <= 'Z') {
            v[tmp] = e[i] - 'A' + 'a';
            tmp++;
        }
        i++;
    }
}
bool isPalindrome(char *s) {
    int len = strlen(s);
    int num = sum(s);//统计有效字符数
    if (num == 0) return true;
    char *flag = (char*)malloc(num * sizeof(char));//用于存放有效字符的数组
    save(flag , s, num);//将s里的有效字符放入flag
    for (int j = 0; j <= num/2; j++) {
        if (flag[j] != flag[num - 1 - j]) return false;
    }
    return true;
}
