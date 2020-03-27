
int getDigitsSquaredSum(int n) {
    int sum = 0;
    
    while(n != 0) {
        int d = n % 10;
        sum += (d*d);
        
        n /= 10;
    }
    
    return sum;
}

bool isHappy(int n){
    int sum = 0;
    
    bool happy = true;
    do {
        sum = getDigitsSquaredSum(n);
        
        //printf("sum %d\n", sum);
        if(sum < 10 && sum != 1 && sum != 7) {
            happy = false;
            
            break;
        }
        
        n = sum;
        
    } while(sum != 1);
    
    return happy;
}
