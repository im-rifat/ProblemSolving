

int getLen(char *s) {
    int i = 0;
    
    for(; s[i] != '\0'; i++) {}
    
    return i;
}

char * addStrings(char * num1, char * num2){
    int len1 = getLen(num1);
    int len2 = getLen(num2);
    
    int maxL = len1 > len2 ? (len1 + 2) : (len2 + 2);
    char* s = malloc(sizeof(char)*(maxL));;
    
    int carry = 0;
    int i, j, k;
    int sum = 0;
    
    for(i = 0, j = len1 -1, k = len2 - 1; j >= 0 && k >=0; i++, j--, k--) {
        sum = num1[j] - '0' + num2[k] - '0' + carry;
        
        s[i] = (sum % 10) + '0';
        carry = sum / 10;
    }
    
    if(j >= 0) {
        while(j >= 0) {
            sum = num1[j--] - '0' + carry;
            s[i++] = (sum % 10) + '0';
            carry = sum / 10;
        }
        
        if(carry != 0) s[i++] = carry + '0';
    } else if(k >= 0) {
        while(k >= 0) {
            sum = num2[k--] - '0' + carry;
            s[i++] = (sum % 10) + '0';
            carry = sum / 10;
        }
        
        if(carry != 0) s[i++] = carry + '0';
    } else {
        if(carry != 0) s[i++] = carry + '0';
    }
    
    for(j = 0, k = i -1 ; j <= k; j++, k--) {
        char a = s[j];
        char b = s[k];
        s[j] = b;
        s[k] = a;
    }
    
    s[i] = '\0';
    
    //printf("%s", s);
    
    return s;
}