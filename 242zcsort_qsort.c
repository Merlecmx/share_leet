int Partion(char* s, int low, int high) {
    char temp = s[low];
    while (low < high) {
        while (low < high && (s[high] - 'a') >= (temp - 'a')) {
            high--;
        }
        s[low] = s[high];
        while (low < high && (s[low] - 'a') <= (temp - 'a')) {
            low++;
        }
        s[high] = s[low];
    }
    s[low] = temp;
    return low;
}
void QuickSort(char* s, int low, int high) {
    int flag = Partion(s, low, high);
    if (flag > low + 1) {//保证有两个数据才需要排序
        QuickSort(s, low, flag - 1);
    }
    if (flag < high - 1) {
        QuickSort(s, flag + 1, high);
    }
}
bool isAnagram(char * s, char * t){
    int len_s, len_t;
    len_s = strlen(s);
    len_t = strlen(t);
    if (len_s != len_t) return false;
    QuickSort(s, 0, len_s - 1);
    QuickSort(t, 0, len_t - 1);
    for (int i = 0; i < len_s; i++) {
        if (s[i] != t[i]) {
            return false;
        }
    }
    return true;
}
