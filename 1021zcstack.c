typedef struct stack {
    int pos;
    int arr[10000];
} mystack;
char * removeOuterParentheses(char* S) {
    int len = strlen(S);
    int i = 0, k = 0;
    if (len == 0) return false;
    mystack* stack = (mystack*)malloc(sizeof(mystack) * 1);
    char* res = (char*)malloc(sizeof(char) * (len + 1));//预留\0的位置
    stack->pos = -1;
    for (i; i < len; i++) {
        if (S[i] == ')') {
            stack->pos--;
        }
        if (stack->pos != -1) {//栈为空时最外层')'不保存
            res[k++] = S[i];
        }
        if (S[i] == '(') {//第一个'('不保存
            stack->pos++;
            stack->arr[stack->pos] = '(';
        }
    }
    res[k] = '\0';
    free(stack);
    return res;
}
