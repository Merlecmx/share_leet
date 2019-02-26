int calPoints(char** ops, int opsSize)
{
    struct stack1
    {
        int array[opsSize];
        int pos;
    };
	int num = 0;
	int i =0;
    typedef struct stack1 stack;
    stack* stack_1 = (stack*)malloc(sizeof(stack));
    memset(stack_1->array,0,opsSize);
    stack_1->pos = 0;
    while(i<opsSize)
    {
        switch(*(*(ops+i)))
        {
            case '+':
                stack_1->array[stack_1->pos]= stack_1->array[stack_1->pos-1]+stack_1->array[stack_1->pos-2];
                stack_1->pos++;
                i++;
                break;
            case 'D':
                stack_1->array[stack_1->pos] = 2*stack_1->array[stack_1->pos-1];
                stack_1->pos++;
                i++;
                break;
            case 'C':
                stack_1->pos--;
                stack_1->array[stack_1->pos]=0;
                i++;
                break;
            default:
                stack_1->array[stack_1->pos] =atoi(*(ops+i));
                stack_1->pos++;
                i++;
                break;
        }
    }
    for(i = 1;i<stack_1->pos;i++)
    {
        stack_1->array[0]+=stack_1->array[i];
    }
    return stack_1->array[0];
}
