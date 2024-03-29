typedef struct stack {
    int array[1000];
    int pos;
}mystack;
int calPoints(char** ops, int opsSize) {
	int num = 0;
	int i = 0;
    mystack* stack = (mystack*)malloc(sizeof(mystack) * 1);
    stack->pos = 0;
    while (i < opsSize) {
        switch (*(ops[i])) {
            case '+':
                stack->array[stack->pos] = stack->array[stack->pos - 1] + stack->array[stack->pos - 2];
                stack->pos++;
                i++;
                break;
            case 'D':
                stack->array[stack->pos] = 2 * stack->array[stack->pos - 1];
                stack->pos++;
                i++;
                break;
            case 'C':
                stack->pos--;
                stack->array[stack->pos] = 0;
                i++;
                break;
            default:
                stack->array[stack->pos] = atoi(ops[i]);
                stack->pos++;
                i++;
                break;
        }
    }
    for (i = 1; i < stack->pos; i++) {
        stack->array[0] += stack->array[i];
    }
    int p = stack->array[0];
    free (stack);
    return p;
}
