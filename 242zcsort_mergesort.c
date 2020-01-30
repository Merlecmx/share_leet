void Merge(char* sourceArr, char* tempArr, int lowindex, int midindex, int highindex){
    int i = lowindex, j = midindex + 1, k = lowindex;
    while (i != midindex + 1 && j != highindex + 1) {
        if(sourceArr[i] > sourceArr[j]) {
            tempArr[k++] = sourceArr[j++];
        } else {
            tempArr[k++] = sourceArr[i++];
        }
    }
    while (i != midindex + 1) {
        tempArr[k++] = sourceArr[i++];
    }
    while (j != highindex + 1) {
         tempArr[k++] = sourceArr[j++];
    }
    for (i = lowindex; i <= highindex; i++) {
        sourceArr[i] = tempArr[i];
    }
}

void MergeSort(char* sourceArr, char* tempArr, int lowindex, int highindex) {
    int midindex;
    if (lowindex < highindex) {
        midindex = lowindex + (highindex - lowindex) / 2;//避免溢出int
        MergeSort(sourceArr, tempArr, lowindex, midindex);
        MergeSort(sourceArr, tempArr, midindex + 1, highindex);
        Merge(sourceArr, tempArr, lowindex, midindex, highindex);
    }
}

bool isAnagram(char* s, char* t){
    int len_s, len_t;
    len_s = strlen(s);
    len_t = strlen(t);
    if (len_s != len_t) return false;
    char* S = (char*)malloc(sizeof(char) * len_s);
    char* T = (char*)malloc(sizeof(char) * len_t);
    MergeSort(s, S, 0, len_s - 1);
    MergeSort(t, T, 0, len_t - 1);
    free(S);
    free(T);
    return strcmp(s, t) == 0;
}
