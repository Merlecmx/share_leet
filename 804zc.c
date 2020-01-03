int uniqueMorseRepresentations(char **words, int wordsSize) {
    int i = 0, j , flag = 0, count = 0;
    char coal[wordsSize + 1][100];
    char code[26][5] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
    for (i = 0; i < wordsSize; i++) {
        for (j = 0; j < strlen(words[i]); j++) {
            strcat(coal[i], code[words[i][j] - 97]);
        }
        if (i > 0) {
            for (j = 0; j < i; j++) {
                if(strcmp(coal[i] , coal[j]) == 0) {
                    flag = 1;
                    continue;
                }
            }
        }
        if(flag == 0) count++;
        flag = 0;
        j = 0;
    }
    return count;
}
