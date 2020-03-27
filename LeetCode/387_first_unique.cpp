

int firstUniqChar(char * s){
    int alpha[26];
    for(int i = 0; i < 26; i++) alpha[i] = 0;
    
    int index = -1;
    
    for(int i = 0; s[i] != '\0'; i++) {
        int pos = s[i] - 'a';
        alpha[pos]++;
    }
    
    for(int i = 0; s[i] != '\0'; i++) {
        if(alpha[s[i] - 'a'] == 1) return i;
    }
    
    return index;
}