typedef struct {
    int* heaparr;//堆数组
    int maxsize;//最大容量
    int size;//当前容量
} KthLargest;

void Swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void InHeap(int* size, int* heaparr, int val) {
    heaparr[(*size)++] = val;
    int currentIdx = (*size) - 1;
    while (currentIdx > 0) {//循环结束条件为不存在父节点或者父节点与当前节点不冲突
        if (heaparr[(currentIdx - 1) / 2] > heaparr[currentIdx]){//父节点的值大于当前节点值
            Swap(&(heaparr[(currentIdx - 1) / 2]), &(heaparr[currentIdx]));
        }
        currentIdx = (currentIdx - 1) / 2;//往上移动
    }
}

void OutHeap(int* size, int* heaparr){
    int ptrTemp;
    heaparr[0] = heaparr[(*size) - 1];
    ptrTemp = 0;
    while (2 * ptrTemp + 1 < (*size) - 1) {
        if (2 * ptrTemp + 2 < (*size) - 1) {
if (heaparr[2 * ptrTemp + 2] > heaparr[ptrTemp] && heaparr[2 * ptrTemp + 1] > heaparr[ptrTemp]) {
                break;
            } else if (heaparr[2 * ptrTemp + 1] < heaparr[2 * ptrTemp + 2]) {
                Swap(&heaparr[2 * ptrTemp + 1], &heaparr[ptrTemp]);
                ptrTemp = 2 * ptrTemp + 1;
            } else {
                Swap(&heaparr[2 * ptrTemp + 2], &heaparr[ptrTemp]);
                ptrTemp = 2 * ptrTemp + 2;
            }
        } else {
            if (heaparr[2 * ptrTemp + 1] < heaparr[ptrTemp]) {
                Swap(&heaparr[2 * ptrTemp + 1], &heaparr[ptrTemp]);
                ptrTemp = 2 * ptrTemp + 1;
            } else {
                break;
            }
        }
    }
    (*size)--;
}

KthLargest* kthLargestCreate(int k, int* nums, int numsSize) {
    KthLargest* p = (KthLargest*)malloc(sizeof(KthLargest));
    p->heaparr = (int*)malloc(sizeof(int) * k);
    p->size = 0;
    p->maxsize = k;
    for (int i = 0; i < numsSize; ++i) {
        if (p->size < p->maxsize) {
            InHeap(&(p->size), p->heaparr, nums[i]);
        } else {
            if (nums[i] > p->heaparr[0]) {//插入值大于堆顶值
                OutHeap(&(p->size), p->heaparr);
                InHeap(&(p->size), p->heaparr, nums[i]);
            }
        }
    }
    return p;
}

int kthLargestAdd(KthLargest* obj, int val) {
    if (obj->size < obj->maxsize) {
        InHeap(&(obj->size), obj->heaparr, val);
    } else {
        if (val > obj->heaparr[0]) {
            OutHeap(&(obj->size), obj->heaparr);
            InHeap(&(obj->size), obj->heaparr, val);
        }
    }
    return obj->heaparr[0];
}

void kthLargestFree(KthLargest* obj) {
    free(obj->heaparr);
    free(obj);
}

/**
 * Your KthLargest struct will be instantiated and called as such:
 * KthLargest* obj = kthLargestCreate(k, nums, numsSize);
 * int param_1 = kthLargestAdd(obj, val);

 * kthLargestFree(obj);
*/
