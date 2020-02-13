/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char check_valid(char c){//判断大小写以及数字
    if (c >= 'a' && c <= 'z') return 'a';
    if (c >= 'A' && c <= 'Z') return 'A';
    return '0';
}

void rec(char* s, int len, int index, char** res, int *res_index){
    int j;
    if (index < 0) return;
    rec(s, len, index-1, res, res_index);
    if (check_valid(s[index]) == '0') {
        //index位为数字，s中字符放到index位置
        for (j = 0; j < *res_index; j++){
            res[j][index] = s[index];
            res[j][index+1] = '\0';
        }
        return;
    } else {//index位为字母，复制两倍，为新增加的分配内存，并复制index位置之前的字符串，在index位置输入对应大小写
        for (j = 0; j < *res_index; j++){
            res[(*res_index) + j] = (char*)malloc(sizeof(char) * (len + 1));
            memcpy(res[(*res_index) + j], res[j], index);
            res[j][index] = s[index];
            res[(*res_index) + j][index] = (check_valid(s[index]) == 'a' ? (s[index] - 'a' + 'A') : (s[index] - 'A' + 'a'));
            res[(*res_index) + j][index+1] = '\0';
            res[j][index + 1] = '\0';
        }
        (*res_index) *= 2;
    }
}

char** letterCasePermutation(char* S, int* returnSize){
    int len = strlen(S);
    char** res = (char**)malloc(sizeof(char) * 65535);
    int res_index = 1;
    res[0] = (char*)malloc(sizeof(char) * (len + 1));
    res[0][0] = '\0';
    rec(S, len, len - 1, res, &res_index);
    *returnSize = res_index;
    return res;
}
