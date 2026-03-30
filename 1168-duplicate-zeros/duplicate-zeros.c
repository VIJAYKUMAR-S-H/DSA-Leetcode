void duplicateZeros(int* arr, int arrSize) {
    for(int i = 0; i < arrSize; i++) {
        if(arr[i] == 0) {
            // shift elements to right
            for(int j = arrSize - 1; j > i; j--) {
                arr[j] = arr[j - 1];
            }
            i++; // skip next element (new zero)
        }
    }
}