class Solution {
public:
    string reverseString(string s) {
        char o[s.length() + 1];
        
        int i = 0, j = s.length() - 1;
        if(j == -1) return "";
        
        for(; j >= 0; i++, j--) {
            o[i] = s[j];
            //cout << o << endl;
        }
        
        o[i] = '\0';
        return string(o);
    }
};