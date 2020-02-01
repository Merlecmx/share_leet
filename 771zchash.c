int numJewelsInStones(char * J, char * S){
    int hash[58] = {0};
    for (int i = 0; J[i] != 0; i++) {
        hash[J[i] - 'A']++;
    }
    int count = 0;
    for (int i = 0; S[i] != 0; i++) {
        if (hash[S[i] - 'A'] > 0) {
            count++;
        }
    }
    return count;
}
