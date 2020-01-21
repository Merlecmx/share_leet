typedef struct stack {
    char arr[20000];
    int pos;
} mystack;
char * removeDuplicates(char * S){
    int len = strlen(S);
    if (len == 0) return S;
    mystack* stack = (mystack*)malloc(sizeof(mystack) * 1);
    char* remove = (char*)malloc(sizeof(char) * (len + 1));
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
    for (i; i <= stack->pos; i++, j++) {
        remove[j] = stack->arr[i];
    }
    remove[j] = '\0';
    free(stack);
    return remove;
}
