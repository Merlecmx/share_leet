void duplicateZeros(int* arr, int arrSize) {
    int i = 0;
    int count = 0;
    for (i; i < arrSize; i++) {
        count++;
        if (arr[i] == 0) {
            count++;
        }
        if (count >= arrSize) {//加入0后需要的长度
            break;
        }
    }
    for (int j = arrSize - 1; j >= 0; j--) {
        if (arr[i] != 0) {
            arr[j] = arr[i];
        } else if (arr[i] == 0 && count > arrSize && j == arrSize - 1) {//当最后一个是0时，不需要再复制0
            arr[j] = arr[i];
        } else {
            arr[j] = arr[i];//0不在最后一个
            arr[j - 1] = arr[i];
            j--;
        }
        i--;
    }
}
