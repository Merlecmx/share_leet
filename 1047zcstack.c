char * removeDuplicates(char * S){
    int len = strlen(S);
    if (len == 0) return S;
    typedef struct stack {
        char* arr[len];
        int pos;
    }Stack;
    Stack* stack = malloc(sizeof(Stack));
    if (stack == NULL) return false;//判断内存申请是否成功
    char* remove = malloc(sizeof(char) * (len + 1));
    stack->pos = -1;
    while (*S) {
        if (stack->pos == -1 || stack->arr[stack->pos] != *S) {
            stack->pos++;
            stack->arr[stack->pos] = *S;
        } else {
            stack->pos--;
        }
        S++;
    }
    int i = 0, j = 0;
    for (i; i <= stack->pos; i++,j++) {
        remove[j] = stack->arr[i];
    }
    remove[j] = '\0';
    free(stack);
    return remove;
}
