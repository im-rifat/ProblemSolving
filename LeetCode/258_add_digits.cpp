int getDigitsSum(int num) {
    int sum = 0;
    
    while(num != 0) {
        sum += (num % 10);
        num /= 10;
    }
    
    return sum;
}

int addDigits(int num){
    int sum = 0;
    
    do {
        sum = getDigitsSum(num);
        num = sum;
    } while(num >9);
    
    return sum;
}