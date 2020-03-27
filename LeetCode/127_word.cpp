class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        return bfs(beginWord, endWord, wordList);
    }
    
    int bfs(string src, string dst, vector<string>& wordList) {
        map<string, bool> dict;
        int size = wordList.size();
        
        for(int i = 0; i < size; i++) {
            dict[wordList[i]] = true;
        }
        
        if(dict.find(dst) == dict.end()) return 0;
        
        queue<string> Q;
        map<string, int> distance;
        distance[src] = 0;
        Q.push(src);
        
        int word_length = src.length();
        
        while(!Q.empty()) {
            string a = Q.front();
            Q.pop();
            
            if(a == dst) return distance[a];
            
            for(int i = 0; i < word_length; i++) { 
                
                for(int j = 0; j < 26; j++) {
                    string b = a;
                    b[i] = 'a' + j;
                
                    if(dict.find(b) == dict.end()) continue;
                    if(distance.find(b) != distance.end()) continue;
                
                    distance[b] = distance[a] + 1;
                    
                    if(b == dst) return distance[b]+1;
                    Q.push(b);
                    
                }
            }
        }
        
        return 0;
    }
};