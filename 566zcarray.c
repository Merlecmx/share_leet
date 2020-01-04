/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** matrixReshape(int** nums, int numsSize, int* numsColSize, int r, int c, int* returnSize, int** returnColumnSizes) {
    if(numsSize * (*numsColSize) != r * c) {
        *returnSize = numsSize;
        *returnColumnSizes = numsColSize;
        return nums;
    }
    int** arr = (int**)malloc(sizeof(int*) * r);
    *returnColumnSizes = (int*)malloc(sizeof(int) * r);
    for (int i = 0; i < r; i++) {
        arr[i] = (int*)malloc(sizeof(int) * c);
        (*returnColumnSizes)[i] = c;
    }
    int row = 0;
    int col = 0;
    for (int i= 0; i < numsSize; i++) {
        for (int j = 0; j < *numsColSize; j++) {
            arr[row][col] = nums[i][j];
            if (col == c - 1) {
                row++;
                col = 0;
            } else {
                col++;
            }
        }
    }
    *returnSize = r;
    return arr;
}
