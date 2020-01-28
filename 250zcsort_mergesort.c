/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
void Merge(int* sourceArr, int* tempArr, int lowindex, int midindex, int highindex){
    int i = lowindex, j = midindex + 1, k = lowindex;
    while (i != midindex + 1 && j != highindex + 1) {
        if(sourceArr[i] > sourceArr[j]) {
            tempArr[k++] = sourceArr[j++];
        } else {
            tempArr[k++] = sourceArr[i++];
        }
    }
    while (i != midindex + 1) {
        tempArr[k++] = sourceArr[i++];
    }
    while (j != highindex + 1) {
         tempArr[k++] = sourceArr[j++];
    }
    for (i = lowindex; i <= highindex; i++) {
        sourceArr[i] = tempArr[i];
    }
}

void MergeSort(int* sourceArr, int* tempArr, int lowindex, int highindex) {
    int midindex;
    if (lowindex < highindex) {
        midindex = lowindex + (highindex - lowindex) / 2;
        MergeSort(sourceArr, tempArr, lowindex, midindex);
        MergeSort(sourceArr, tempArr, midindex + 1, highindex);
        Merge(sourceArr, tempArr, lowindex, midindex, highindex);
    }
}

int* intersect(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize){
    int* nums11 = (int*)malloc(sizeof(int) * nums1Size);
    int* nums22 = (int*)malloc(sizeof(int) * nums2Size);
    MergeSort(nums1, nums11, 0, nums1Size - 1);
    MergeSort(nums2, nums22, 0, nums2Size - 1);
    int i = 0, j = 0, index = 0;
    while(i < nums1Size && j < nums2Size) {
        if (nums1[i] < nums2[j]) {
            i++;
        } else if (nums1[i] > nums2[j]) {
            j++;
        } else {
            nums1[index++] = nums1[i];
            i++;
            j++;
        }
    }
    int* arr = (int*)malloc(sizeof(int) * index);
    for (int i = 0; i < index; i++) {
        arr[i] = nums1[i];
    }
    *returnSize = index;
    free(nums11);
    free(nums22);
    return arr;
}
