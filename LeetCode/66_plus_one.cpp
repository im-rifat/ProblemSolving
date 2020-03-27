

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize){
    int carry = 1;
    int sum = 0;
    int d[digitsSize];
    
    for(int i = digitsSize - 1; i >=0; i--) {
        sum = digits[i] + carry;
        d[i] = sum % 10;
        carry = sum / 10;
    }
    
    int size = carry == 0 ? digitsSize : (digitsSize + 1);
    int* rreturnSize = (int*)malloc(size * sizeof(int));

    for(int i = size - 1, j = digitsSize - 1; carry == 0 ? i >= 0 : i >= 1 ; i--, j--) {
        rreturnSize[i] = d[j];
    }
    
    if(carry != 0) rreturnSize[0] = carry;
    *returnSize = size;
    
    return rreturnSize;
}

