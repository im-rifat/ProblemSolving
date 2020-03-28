

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

void mergeSort(int* a, int* b, int l, int r) {
    if(l < r) {
        int m = l + ((r - l) / 2);
        
        mergeSort(a, b, l, m);
        mergeSort(a, b, m + 1, r);
        merge(a, b, l, m, r);
    }
}

void merge(int* a, int* b, int l, int m, int r) {
    int n1 = m - l + 1, n2 = r - m;
    int x[n1], y[n2];
    
    for(int i = 0; i < n1; i++) x[i] = a[l + i];
    for(int i = 0; i < n2; i++) y[i] = a[m + i + 1];
    
    int i = 0, j = 0, k = l;
    for(;i < n1 && j < n2;) {
        int index1 = b[x[i]];
        int index2 = b[y[j]];
        
        if(index1 == -1 && index2 != -1) {
            a[k++] = y[j++];
        } else if(index1 != -1 && index2 == -1) {
            a[k++] = x[i++];
        } else if(index1 == -1 && index2 == -1) {
          if(x[i] <= y[j]) {
              a[k++] = x[i++];
          } else {
              a[k++] = y[j++];
          }
        } else {
            if(index1 <= index2) {
                a[k++] = x[i++];
            } else {
                a[k++] = y[j++];
            }
        }
    }
    
    while(i < n1) {
        a[k++] = x[i++];
    }
    
    while(j < n2) {
        a[k++] = y[j++];
    }
}

int* relativeSortArray(int* arr1, int arr1Size, int* arr2, int arr2Size, int* returnSize){
    int SIZE = 1001;
    int* appears = (int*) malloc(SIZE * sizeof(int));
    
    for(int i = 0; i < SIZE; i++) appears[i] = -1;
    
    for(int i = 0; i < arr2Size; i++) appears[arr2[i]] = i;
    
    int* a = (int*) malloc(arr1Size * sizeof(int));
    
    for(int i = 0; i < arr1Size; i++) a[i] = arr1[i];
    
    mergeSort(a, appears, 0, arr1Size - 1);
    
    *returnSize = arr1Size;
    
    return a;
}

