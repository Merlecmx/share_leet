bool isAnagram(char * s, char * t){
    int len_s, len_t;
    len_s = strlen(s);
    len_t = strlen(t);
    if (len_s != len_t) return false;
    int hash[26] = {0};
    for (int i = 0; i < len_s; i++) {//统计两个字符串相等字符的数量，数量相等时，哈希表对应位置为0
        hash[s[i] - 'a']++;
        hash[t[i] - 'a']--;
    }
    for(int i = 0; i < 26; i++) {
        if (hash[i] != 0) return false;
    }
    return true;
}
