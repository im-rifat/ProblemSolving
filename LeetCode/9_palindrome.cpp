class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) return false;
        
        char asStr[13];
        
        int i = 0;
        while(x != 0) {
            asStr[i++] = (x % 10) + '0';
            x /= 10;
        }
        if(i == 0) asStr[i++] = '0';
        asStr[i] = '\0';
        
        for(int j = 0, k = i - 1; j <= k; j++, k--) {
            if(asStr[j] != asStr[k]) return false;
        }
        
        return true;
    }
};