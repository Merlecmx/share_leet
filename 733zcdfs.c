/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
void dfs(int** image, int r, int c, int color, int newColor, int imageSize, int* imageColSize){
    if (image[r][c] == color) {
        image[r][c] = newColor;
        if (r >= 1) dfs(image, r - 1, c, color, newColor, imageSize, imageColSize);
        if (r + 1 < imageSize) dfs(image, r + 1, c, color, newColor, imageSize, imageColSize);
        if (c >= 1) dfs(image, r, c - 1, color, newColor, imageSize, imageColSize);
        if (c + 1 < *imageColSize) dfs(image, r, c + 1, color, newColor, imageSize, imageColSize);
    }
}

int** floodFill(int** image, int imageSize, int* imageColSize, int sr, int sc, int newColor, int* returnSize, int** returnColumnSizes){
    int color = image[sr][sc];
    if (color != newColor) dfs(image, sr, sc, color, newColor, imageSize, imageColSize);
    int** res = (int**)malloc(sizeof(int*) * imageSize);
    *returnColumnSizes = (int*)malloc(sizeof(int) * imageSize);
    for (int i = 0; i < imageSize; i++) {
        res[i] = (int *)malloc(sizeof(int) * (*imageColSize));
        memcpy(res[i], image[i], sizeof(int) * (*imageColSize));
        *(*returnColumnSizes + i) = *imageColSize;
    }
    *returnSize = imageSize;
    return res;
}
