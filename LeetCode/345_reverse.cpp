class Solution {
public:
    string reverseVowels(string s) {
        
        int l = s.length();
        char o[l + 1];
        char v[l + 1];
        int posInd[l + 1];
        int posV = 0;
        
        if(l == 0) return "";
        
        for(int i = 0 ; i < l; i++) {
            o[i] = s[i];
            char alpha = tolower(s[i]);
            if(alpha == 'a' || alpha =='e' || alpha == 'i' || alpha == 'o' || alpha == 'u') {
                v[posV] = s[i];
                posInd[posV] = i;
                posV++;
            }
        }
        
        for(int i = posV - 1, j = 0; i >= 0; i--, j++) {
            o[posInd[j]] = v[i];
        }
        
        o[l] = '\0';
        
        return string(o);
    }
};