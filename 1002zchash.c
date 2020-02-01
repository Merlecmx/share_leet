/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char ** commonChars(char ** A, int ASize, int* returnSize){
    int arr[26] = {0};
    for (char* p = A[0]; *p != '\0'; p++) {//取第一个字符串做标准，保存字母数量
        arr[(*p) - 'a']++;
    }
    for (int i = 1; i < ASize; i++) {
        int temp[26] = {0};
        for (char* p = A[i]; *p != '\0'; p++) {//将后面的字符串每个字母数量保存
           temp[(*p) - 'a']++;
        }
        for (int j = 0; j < 26; j++) {//取对应字母数量最少的保存
            if (arr[j] > temp[j]) {
                arr[j] = temp[j];
            }
        }
    }
    char** res = (char**)malloc(sizeof(char*) * 100);
    int index = 0;
    for (int i = 0; i < 26; i++) {
        if (!arr[i]) continue;
        res[index] = (char*)malloc(sizeof(char) * 2);
        res[index][0] = 'a' + i;
        res[index++][1] = '\0';
        for (arr[i]; arr[i] > 1; arr[i]--, index++) {//数量大于1时，有多少重复的就输出多少
            res[index] = res[index - 1];
        }
    }
    *returnSize = index;
    return res;
}
