

int getLength(char* s) {
    int i = 0;
    
    while(s[i] != '\0') {
        i++;
    }
    
    return i;
}

char * addBinary(char * a, char * b){
    int len1 = getLength(a), len2 = getLength(b);
    int newlen = len1 > len2 ? len1 : len2;
    newlen += 1;
    
    int carry = 0, sum;
    char* s = (int*)malloc(newlen * sizeof(int));
    int i = len1 - 1, j = len2 - 1, k = 0;
    
    for(; i >= 0 && j >= 0; i--, j--) {
        sum = a[i] - '0' + b[j] - '0' + carry;
        //printf("sum %d\n", sum);
        s[k++] = (sum % 2) + '0';
        //printf("char %c\n", s[k-1]);
        carry = sum / 2;
    }
    
    while(i >= 0) {
        sum = a[i] - '0' + carry;
        s[k++] = (sum % 2) + '0';
        carry = sum / 2;
        i--;
    }
    
    while(j >= 0) {
        sum = b[j] - '0' + carry;
        s[k++] = (sum % 2) + '0';
        carry = sum / 2;
        j--;
    }
    
    if(carry != 0) s[k++] = carry + '0';
    s[k] = '\0';
    
    for(i = 0, j = k - 1; i <= j; i++, j--) {
        char u = s[i], v = s[j];
        s[i] = v;
        s[j] = u;
    }
    
    return s;
}

