void duplicateZeros(int* arr, int arrSize) {
    for (int i = 0; i < arrSize; i++) {
        if (arr[i] ==0) {
            int j = arrSize - 1;
            for (j; j > i + 1; j--) {//0�����������һλ
                arr[j] = arr[j - 1];
            }
            arr[j] = 0;
            i++;
        }
    }
}
