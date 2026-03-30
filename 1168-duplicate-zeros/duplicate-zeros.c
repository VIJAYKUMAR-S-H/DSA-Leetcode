void duplicateZeros(int* arr, int n) {
    int zeros = 0;

    // Count zeros
    for(int i = 0; i < n; i++) {
        if(arr[i] == 0) {
            zeros++;
        }
    }

    int i = n - 1;
    int j = n + zeros - 1;

    // Traverse from back
    while(i >= 0) {
        // Copy element if within bounds
        if(j < n) {
            arr[j] = arr[i];
        }

        // If zero, duplicate it
        if(arr[i] == 0) {
            j--;
            if(j < n) {
                arr[j] = 0;
            }
        }

        i--;
        j--;
    }
}