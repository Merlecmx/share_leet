int sum(char *p);
void save(char *v, char *e, int a);
int sum(char *p) {
    int len = strlen(p);
    int i = 0;
    int count = 0;
    while (p[i] != '\0') {
        if ((p[i] <'0' || p[i] > '9') && (p[i] < 'a' || p[i] > 'z') && (p[i] < 'A' || p[i] > 'Z')) {//ͳ����Ч�ַ���
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
    int num = sum(s);//ͳ����Ч�ַ���
    if (num == 0) return true;
    char *flag = (char*)malloc(num * sizeof(char));//���ڴ����Ч�ַ�������
    save(flag , s, num);//��s�����Ч�ַ�����flag
    for (int j = 0; j <= num/2; j++) {
        if (flag[j] != flag[num - 1 - j]) return false;
    }
    return true;
}
