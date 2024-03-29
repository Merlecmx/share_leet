bool isValid(char *s) {
    if (s == NULL) {
        return false;
    }
    int i = 0;
    int j = 0;
    char ch[10000];
    if (s[0] == ']' || s[0] =='}' || s[0] == ')') {
        return false;
    }
    while (s[i] != '\0') {
        switch (s[i]) {
        case '{' : {
            ch[j] = '{';
            break;
        }
        case '(' : {
            ch[j] = '(';
            break;
        }
        case '[' : {
            ch[j] = '[';
            break;
        }
        case ']' : {
            if (j == 0) {
                return false;
            } else if (ch[j-1] == '[') {
                j = j-2;
            } else {
                return false;
            }
            break;
        }
        case '}' : {
            if (j == 0) {
                return false;
            } else if (ch[j-1] == '{') {
                j = j-2;
            } else {
                return false;
            }
            break;
        }
        case ')' : {
            if (j == 0) {
                return false;
            } else if (ch[j-1] == '(') {
                j = j-2;
            } else {
                return false;
            }
            break;
        }
        }
        i++;
        j++;
    }
    return j == 0;
}
