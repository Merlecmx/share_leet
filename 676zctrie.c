typedef struct Trie{
    struct Trie* ch[26];
    bool is_end;
} MagicDictionary;

/** Initialize your data structure here. */

MagicDictionary* magicDictionaryCreate() {
    MagicDictionary* trie = (MagicDictionary*)calloc(sizeof(MagicDictionary) , 1);
    return trie;
}

/** Build a dictionary through a list of words */
void magicDictionaryBuildDict(MagicDictionary* obj, char ** dict, int dictSize) {
    int index = 0;
    MagicDictionary* p;
    for (int i = 0; i < dictSize; ++i) {
        p = obj;
        int len = strlen(dict[i]);
        for (int j = 0; j < len; ++j) {
            index = dict[i][j] - 'a';
            if (p->ch[index] == NULL) {
                p->ch[index] = magicDictionaryCreate();
            }
            p = p->ch[index];
        }
        p->is_end = true;;
    }
}

bool Search(MagicDictionary* obj, char* word) {
    int index = 0;
    int len = strlen(word);
    for (int i = 0; i < len; ++i) {
        index = word[i] - 'a';
        if (obj->ch[index] == NULL) {
            return false;
        }
        obj = obj->ch[index];
    }
    return obj->is_end;
}

/** Returns if there is any word in the trie that equals to the given word after modifying exactly one character */
bool magicDictionarySearch(MagicDictionary* obj, char * word) {
    int index = 0;
    int len = strlen(word);
    for (int i = 0; i < len; ++i) {
        for (int j = 0; j < 26; ++j) {
            if (obj->ch[j] && j != word[i] - 'a') {
                if (Search(obj->ch[j], word + i + 1)) {
                    return true;
                }
            }
        }
        if (obj->ch[word[i] - 'a'] != NULL) {
            obj = obj->ch[word[i] - 'a'];
        } else {
            break;
        }
    }
    return false;
}

void magicDictionaryFree(MagicDictionary* obj) {
    if(obj == NULL) return;
    for (int i = 0; i < 26; ++i) {
        if (obj->ch[i]) magicDictionaryFree(obj->ch[i]);
    }
    free(obj);
}

/**
 * Your MagicDictionary struct will be instantiated and called as such:
 * MagicDictionary* obj = magicDictionaryCreate();
 * magicDictionaryBuildDict(obj, dict, dictSize);

 * bool param_2 = magicDictionarySearch(obj, word);

 * magicDictionaryFree(obj);
*/
