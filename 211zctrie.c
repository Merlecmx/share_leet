typedef struct Trie {
    struct Trie* ch[26];
    bool is_end;
} WordDictionary;

/** Initialize your data structure here. */

WordDictionary* wordDictionaryCreate() {
    WordDictionary* trie = (WordDictionary*)calloc(sizeof(WordDictionary) , 1);
    return trie;
}

/** Adds a word into the data structure. */
void wordDictionaryAddWord(WordDictionary* obj, char* word) {
    if (obj == NULL) return;
    int len = strlen(word);
    int index = 0;
    for (int i = 0; i < len; ++i) {
        index = word[i] - 'a';
        if (obj->ch[index] == NULL) {
            obj->ch[index] = wordDictionaryCreate();
        }
        obj = obj->ch[index];
    }
    obj->is_end = true;
}

/** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
bool wordDictionarySearch(WordDictionary* obj, char* word) {
    if (obj == NULL) return false;
    int len = strlen(word);
    int index = 0;
    for (int i = 0; i < len; ++i) {
        index = word[i] - 'a';
        if (word[i] == '.') {
            for (int j = 0; j < 26; ++j) {
                if (obj->ch[j] != NULL) {
                    if (wordDictionarySearch(obj->ch[j], word + i + 1)){
                        return true;
                    }
                }
            }
            return false;
        }
        if (obj->ch[index] == NULL) {
            return false;
        }
        obj = obj->ch[index];
    }
    return obj->is_end;
}

void wordDictionaryFree(WordDictionary* obj) {
    for (int i = 0; i < 26; ++i) {
        if (obj->ch[i]) free(obj->ch[i]);
    }
    free(obj);
}

/**
 * Your WordDictionary struct will be instantiated and called as such:
 * WordDictionary* obj = wordDictionaryCreate();
 * wordDictionaryAddWord(obj, word);

 * bool param_2 = wordDictionarySearch(obj, word);

 * wordDictionaryFree(obj);
*/
