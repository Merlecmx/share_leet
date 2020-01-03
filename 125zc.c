void save(char *v, char *p, int *num) {
    int i = 0;
    int count = 0;
    int tmp = 0;
    for (i = 0; p[i]; i++) {
        if ((p[i] >= '0' && p[i] <= '9') || (p[i] >= 'a' && p[i] <= 'z')) {
            v[tmp] = p[i];
            tmp++;
            count++;
        } else if (p[i] >= 'A' && p[i] <= 'Z') {
            v[tmp] = p[i] - 'A' + 'a';
            tmp++;
            count++;
        }
        *num = count;
    }
}
bool isPalindrome(char *s) {
    int len = strlen(s);
    char *flag = (char*)malloc(len * sizeof(char));//���ڴ����Ч�ַ�������
    save(flag , s, &len);//��s�����Ч�ַ�����flag
    if (len == 0) return true;
    for (int j = 0; j <= len/2; j++) {
        if (flag[j] != flag[len - 1 - j]) return false;
    }
    free (flag);
    return true;
}
