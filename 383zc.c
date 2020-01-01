bool canConstruct(char * ransomNote, char * magazine) {
    int a[26] = {0};
    int len1 = strlen(ransomNote);
    int len2 = strlen(magazine);
    for(int i=0; i<len2; i++) {
        a[magazine[i] - 'a']++;
    }
    for(int j=0; j<len1; j++) {
        if(--a[ransomNote[j] - 'a'] < 0)
            return false;
    }
    return true;
}
