int numUniqueEmails(char **emails, int emailsSize) {
    int i = 0, j = 0, num = 0, count = 1, flag = 0, k;
    char *p = NULL;
    char a[100] = {0};
    for (i = 0; i < emailsSize; i++) {
        while (emails[i][j] != '@') {
            if (emails[i][j] == '.') {
                p = &emails[i][j+1];
                strcpy(a, p);
                emails[i][j] = '\0';
                strcat(emails[i], a);
            }
            if (emails[i][j] == '+') {
                p = &emails[i][j+1];
                strcpy(a, p);
                emails[i][j] = '\0';
                while (a[num] != '@')
                    num++;
                strcat(emails[i], &a[num]);
                num = 0;
                break;
            }
            j++;
        }
        j = 0;
        if (i > 0) {
            for (k = i - 1; k >= 0; k--) {
                if (strcmp(emails[i], emails[k]) == 0) {
                    flag = 1;
                    break;
                }
            }
            if (flag == 0)
                count++;
        }
        flag = 0;
    }
    return count;
}
