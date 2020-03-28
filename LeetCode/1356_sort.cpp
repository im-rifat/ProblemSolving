

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int getNumberOf1Bit(int a) {
    int count = 0;
    
    while(a != 0) {
        if(a % 2 == 1) count++;
        a /= 2;
    }
    
    return count;
}

void mergeSort(int* arr, int* bits, int l, int r) {
    if(l < r) {
        int m = l + ((r - l) / 2);
        
        mergeSort(arr, bits, l, m);
        mergeSort(arr, bits, m + 1, r);
        merge(arr, bits, l, m, r);
    }
}

void merge(int* arr, int *bits, int l, int m, int r) {
    int n1 = m - l + 1, n2 = r - m;
    int a[n1], b[n2];
    
    for(int i = 0; i < n1; i++) {
        a[i] = arr[l + i];
    }
    
    for(int i = 0; i < n2; i++) {
        b[i] = arr[m + i + 1];
    }
    
    int i = 0, j = 0, k = l;
    
    for(; i < n1 && j < n2;) {
        if(bits[a[i]] < bits[b[j]]) {
            arr[k] = a[i++];
        } else if(bits[a[i]] > bits[b[j]]){
            arr[k] = b[j++];
        } else {
            if(a[i] <= b[j]) {
                arr[k] = a[i++];
            } else {
                arr[k] = b[j++];
            }
        }
        k++;
    }
    
    while(i < n1) {
        arr[k++] = a[i++];
    }
    
    while(j < n2) {
        arr[k++] = b[j++];
    }
}

int* sortByBits(int* arr, int arrSize, int* returnSize){
    int SIZE = 10001;
    int* bits = (int*)malloc(SIZE * sizeof(int));
    for(int i = 0; i < SIZE; i++) bits[i] = 0;
    
    int* a = (int*)malloc(arrSize * sizeof(int));
    
    for(int i = 0; i < arrSize; i++) {
        bits[arr[i]] = getNumberOf1Bit(arr[i]);
        //printf("%d ", bits[i]);
        a[i] = arr[i];
    }
    
    mergeSort(a, bits, 0, arrSize - 1);
    *returnSize = arrSize;
    
    return a;
}

