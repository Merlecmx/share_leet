typedef struct Trie {
    struct Trie* ch[26];
    bool is_end;
}Trie;

char * replaceWords(char** dict, int dictSize, char* sentence){
    Trie* pool = (Trie*)calloc(100000 , sizeof(Trie));
    int psize = 0;
    Trie* root = &pool[psize++];
    int index = 0;
    for (int i = 0; i < dictSize; ++i) {
        int len_d = strlen(dict[i]);
        Trie* obj = root;
        for (int j = 0; j < len_d; ++j) {
            index = dict[i][j] - 'a';
            if (obj->ch[index] == NULL) {
                obj->ch[index] = &pool[psize++];
            }
            obj = obj->ch[index];
        }
        obj->is_end = true;
    }
    int len_s = strlen(sentence);
    char* res = (char*)calloc(sizeof(char) , (len_s + 1));
    int l = 0, r = 0, res_index = 0;//r用来标记空格位置
    while (r < len_s) {
        if (sentence[r] != ' ') {
            r++;
            continue;
        }
        Trie* obj = root;
        for (int i = l; i < r; ++i) {
            if (obj != NULL) {
                if (obj->is_end == true) {
                    break;
                }
                index = sentence[i] - 'a';
                obj = obj->ch[index];
            }
            res[res_index++] = sentence[i];
        }
        res[res_index++] = sentence[r++];
        l = r;
    }
    Trie* obj = root;
    for (int i = l; i < r; ++i) {//最后一个单词单独处理
        if (obj != NULL) {
            if (obj->is_end == true) {
                break;
            }
            index = sentence[i] - 'a';
            obj = obj->ch[index];
        }
        res[res_index++] = sentence[i];
    }
    res[res_index++] = '\0';
    free(pool);
    return res;
}
