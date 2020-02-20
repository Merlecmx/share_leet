void BuildHeap(int* heap, int heapsize){
    int i = 0, temp = 0;
    for (i = (heapsize/2) - 1; i >= 0; --i) {
        int leftchildIdx = (2 * i) + 1;
        int rightchildIdx = (2 * i) + 2;
        if (leftchildIdx < heapsize && heap[i] > heap[leftchildIdx]) {//根的值大于左子树时交换
            temp = heap[i];
            heap[i] = heap[leftchildIdx];
            heap[leftchildIdx] = temp;
            if ((2 * leftchildIdx + 1 < heapsize && heap[leftchildIdx] > heap[2 * leftchildIdx + 1]) || (2 * leftchildIdx + 2 < heapsize && heap[leftchildIdx] > heap[2 * leftchildIdx + 2])) {//交换后，判断左子树是否符合小顶堆性质
                BuildHeap(heap, heapsize);
            }
        }
        if (rightchildIdx < heapsize && heap[i] > heap[rightchildIdx]) {//根的值大于右子树
            temp = heap[i];
            heap[i] = heap[rightchildIdx];
            heap[rightchildIdx] = temp;
            if ((2 * rightchildIdx + 1 < heapsize && heap[rightchildIdx] > heap[2 * rightchildIdx + 1]) || (2 * rightchildIdx + 2 < heapsize && heap[rightchildIdx] > heap[2 * rightchildIdx + 2])) {//交换后判断右子树是否符合小顶堆
                BuildHeap(heap, heapsize);
            }
        }
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
