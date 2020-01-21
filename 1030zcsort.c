/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int a_r0;
int a_c0;
int cmp(const void* a, const void* b) {
    return ((abs((*((int**)a))[0] - a_r0) + abs((*((int**)a))[1] - a_c0)) - (abs((*((int**)b))[0] - a_r0) + abs((*((int**)b))[1] - a_c0)));
 }
int** allCellsDistOrder(int R, int C, int r0, int c0, int* returnSize, int** returnColumnSizes){
    int** arr = (int**)malloc(sizeof(int*) * (R * C));
    int* columnSize = (int*)malloc(sizeof(int) * (R * C));
    for (int i = 0; i < (R * C); i++) {
        arr[i] = (int*)malloc(sizeof(int) * 2);
        columnSize[i] = 2;
    }
    int index = 0;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {//把坐标放入数组
            arr[index][0] = i;
            arr[index++][1] = j;
        }
    }
    a_r0 = r0;
    a_c0 = c0;
    qsort(arr, R * C, sizeof(arr[0]), cmp);//排序
    *returnSize = R * C;
    *returnColumnSizes = columnSize;
    return arr;
}
