typedef struct {
    int *arr;
    int top;
} MyQueue;

/** Initialize your data structure here. */
MyQueue* myQueueCreate(int maxSize) {
    MyQueue *queue = (MyQueue *)malloc(sizeof(MyQueue));
    queue->arr = (int *)malloc(sizeof(int) * maxSize);
    queue->top = -1;
    return queue;
}

/** Push element x to the back of queue. */
void myQueuePush(MyQueue* obj, int x) {
    int tmp = obj->top;
    if (obj->top == -1) {
        obj->arr[0] = x;
        obj->top++;
    } else {
        while (obj->top != -1) {
            obj->arr[obj->top+1] = obj->arr[obj->top];
            obj->top--;
        }
        obj->arr[0] = x;
        obj->top = tmp+1;
    }
}

/** Removes the element from in front of queue and returns that element. */
int myQueuePop(MyQueue* obj) {
    if (-1 == obj->top) return 0;
    return obj->arr[obj->top--];
}

/** Get the front element. */
int myQueuePeek(MyQueue* obj) {
    if (obj->top == -1) return 0;
    return obj->arr[obj->top];
}

/** Returns whether the queue is empty. */
bool myQueueEmpty(MyQueue* obj) {
    return obj->top == -1 ? 1 : 0;
}

void myQueueFree(MyQueue* obj) {
    if(obj) free(obj);
}
