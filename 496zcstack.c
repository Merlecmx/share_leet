/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
typedef struct stack {
    int arr[1000];
    int top;
} mystack;
int* nextGreaterElement(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
    int* hashmap = (int*)malloc(sizeof(int) * 10001);
    int* res = (int*)malloc(sizeof(int) * nums1Size);//存放最后结果
    mystack* stack = (mystack*)malloc(sizeof(mystack));
    stack->top = -1;
    int i = 0;
    for (i; i < nums2Size; i++) {
        if(stack->top == -1) {//空栈
            stack->top++;
            stack->arr[stack->top] = nums2[i];
        } else if (stack->arr[stack->top] < nums2[i]) {//当将要比较的数比栈里的全部或部分数大时
            while (stack->arr[stack->top] < nums2[i] && stack->top != -1) {
                hashmap[stack->arr[stack->top]] = nums2[i];//对应数赋值进hashmap
                stack->top--;//将符合题目的值pop
                if (stack->top == -1) {
                    break;
                }
            }
            stack->top++;
            stack->arr[stack->top] = nums2[i];//比较后的大数入栈对应的位置
        } else if (stack->arr[stack->top] > nums2[i]) {//当将要比较的数比栈里的数小时直接入栈
            stack->top++;
            stack->arr[stack->top] = nums2[i];
        }
    }
    while (stack->top != -1) {//栈里剩余的数赋值-1
        hashmap[stack->arr[stack->top]] = -1;
        stack->top--;
    }
    int j = 0;
    for (i = 0; i < nums1Size; i++) {
        res[j++] = hashmap[nums1[i]];
    }
    free(hashmap);
    free(stack);
    *returnSize = nums1Size;
    return res;
}
