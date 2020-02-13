typedef struct Trie {
    struct Trie* ch[26];
    bool is_end;
} Trie;

/** Initialize your data structure here. */

Trie* trieCreate() {
    Trie* trie = (Trie*)calloc(sizeof(Trie) , 1);
    return trie;
}

/** Inserts a word into the trie. */
void trieInsert(Trie* obj, char* word) {
    if (obj == NULL) return;
    int len = strlen(word);
    int index;
    for (int i = 0; i < len; ++i) {
        index = word[i] - 'a';
        if (obj->ch[index] == NULL) {
            obj->ch[index] = trieCreate();
        }
        obj = obj->ch[index];
    }
    obj->is_end = true;
}

/** Returns if the word is in the trie. */
bool trieSearch(Trie* obj, char* word) {
    if (obj == NULL) return false;
    int len = strlen(word);
    int index = 0;
    for (int i = 0; i < len; ++i) {
        index = word[i] - 'a';
        if (obj->ch[index] == NULL) {
            return false;
        }
        obj = obj->ch[index];
    }
    return obj->is_end;
}

/** Returns if there is any word in the trie that starts with the given prefix. */
bool trieStartsWith(Trie* obj, char* prefix) {
    if (obj == NULL) return false;
    int len = strlen(prefix);
    int index = 0;
    for (int i = 0; i < len; ++i) {
        index = prefix[i] - 'a';
        if (obj->ch[index] == NULL) {
            return false;
        }
        obj = obj->ch[index];
    }
    return true;
}

void trieFree(Trie* obj) {
    for (int i = 0; i < 26; ++i) {
        if (obj->ch[i]) free(obj->ch[i]);
    }
    free(obj);
}

/**
 * Your Trie struct will be instantiated and called as such:
 * Trie* obj = trieCreate();
 * trieInsert(obj, word);

 * bool param_2 = trieSearch(obj, word);

 * bool param_3 = trieStartsWith(obj, prefix);

 * trieFree(obj);
*/
