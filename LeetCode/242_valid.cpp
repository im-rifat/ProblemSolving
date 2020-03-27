
void mergeSort(char* s, int l, int r) {
    if(l < r) {
        int mid = l + ((r - l) / 2);
        mergeSort(s, l, mid);
        mergeSort(s, mid+1, r);
        mergeO(s, l, mid, r);
    }
}

void mergeO(char* s, int l, int m, int r) {
    int sizeA = m - l + 1, sizeB = r - m;
    
    char a[sizeA], b[sizeB];
    
    for(int i = 0; i < sizeA; i++) {
        a[i] = s[l + i];
    }
    
    for(int i = 0; i < sizeB; i++) {
        b[i] = s[m + i + 1];
    }
    
    int i = l, j = 0, k = 0;
    
    for(; j < sizeA && k < sizeB;) {
        if(a[j] <= b[k]) {
            s[i] = a[j];
            j++;
        } else {
            s[i] = b[k];
            k++;
        }
        i++;
    }
    
    //printf("hi %d %d %s\n", sizeA, sizeB, s);
    
    while(j < sizeA) {
        s[i++] = a[j++];
    }
    
    while(k < sizeB) {
        s[i++] = b[k++];
    }
    
   // printf("%d %d %s\n", sizeA, sizeB, s);
}

int getLen(char* s) {
    int sum = 0;
    
    for(sum = 0; s[sum] != '\0'; sum++){}
    
    return sum;
}


bool isAnagram(char * s, char * t){
    int lenA = getLen(s), lenB = getLen(t);
    
    if(lenA != lenB) return false;
    
    mergeSort(s, 0, lenA - 1);
    mergeSort(t, 0, lenB - 1);
    
    //printf("%s %s", s, t);
    
    for(int i = 0; i < lenA; i++) {
        if(s[i] != t[i]) return false;
    }
    
    return true;
}
