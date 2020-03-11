void Heap(int* heap, int i, int index, int heapsize);

void Swap(int* a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void BuildHeap(int* heap, int heapsize){
    int i = 0, temp = 0;
    for (i = (heapsize/2) - 1; i >= 0; --i) {
        int lcIdx = (2 * i) + 1;
        int rcIdx = (2 * i) + 2;
        if (lcIdx < heapsize && heap[i] > heap[lcIdx]) {//根的值大于左子树时交换
            Heap(heap, i, lcIdx, heapsize);
        }
        if (rcIdx < heapsize && heap[i] > heap[rcIdx]) {//根的值大于右子树
            Heap(heap, i, rcIdx, heapsize);
        }
    }
}

void Heap(int* heap, int i, int index, int heapsize){
    Swap(heap + i, heap + index);
    if ((2 * index + 1 < heapsize && heap[index] > heap[2 * index + 1]) || (2 * index + 2 < heapsize && heap[index] > heap[2 * index + 2])) {//交换后，判断子树是否符合小顶堆性质
        BuildHeap(heap, heapsize);
    }
}

int findKthLargest(int* nums, int numsSize, int k){
    int* arr = (int*)malloc(sizeof(int) * k);
    int index = 0;
    for (int i = 0; i < k; ++i) {//前k个数建堆
        arr[index++] = nums[i];
    }
    BuildHeap(arr, k);
    int temp = 0;
    for (int i = k; i < numsSize; ++i) {
        if (nums[i] > arr[0]) {//h剩下的数大于堆顶则替换
            arr[0] = nums[i];
            BuildHeap(arr, k);//维护替换后的堆
        }
    }
    return arr[0];
}
