int Partion(char* s, int low, int high) {
    char temp = s[low];
    while (low < high) {
        while (low < high && s[high] >= temp) {
            high--;
        }
        s[low] = s[high];
        while (low < high && s[low] <= temp) {
            low++;
        }
        s[high] = s[low];
    }
    s[low] = temp;
    return low;
}
void QuickSort(char* s, int low, int high) {
    int index = Partion(s, low, high);
    if (low < high) {
        QuickSort(s, low, index - 1);
        QuickSort(s, index + 1, high);
    }
}
bool isAnagram(char * s, char * t){
    int len_s, len_t;
    len_s = strlen(s);
    len_t = strlen(t);
    if (len_s != len_t) return false;
    QuickSort(s, 0, len_s - 1);
    QuickSort(t, 0, len_t - 1);
    return strcmp(s, t) == 0;
}
