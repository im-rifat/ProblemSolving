class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        return bfs(string("0000"), target, deadends);
    }
    
    int bfs(string src, string target, vector<string> &deadends) {
        map<string, bool> deadEnds;
        int size = deadends.size();
        
        for(int i = 0; i < size;i ++) {
            deadEnds[deadends[i]] = true;
        }
        
        if(deadEnds.find(src) != deadEnds.end()) return -1;
        
        queue<string> Q;
        map<string, int> distance;
        distance[src] = 0;
        Q.push(src);
        
        while(!Q.empty()) {
            string a = Q.front();
            Q.pop();
            
            if(a == target) return distance[a];
            for(int i = 0; i < 4; i++) {
                string b = a;
                b[i] += 1;
                if(b[i] > '9') b[i] = '0';
                
                if(deadEnds[b]) continue;
                if(distance.find(b) != distance.end()) continue;
                distance[b] = distance[a] + 1;
                
                if(b == target) return distance[b];
                Q.push(b);
            }
            
            for(int i = 0; i < 4; i++) {
                string b = a;
                b[i] -= 1;
                if(b[i] < '0') b[i] = '9';
                
                if(deadEnds[b]) continue;
                if(distance.find(b) != distance.end()) continue;
                distance[b] = distance[a] + 1;
                
                if(b == target) return distance[b];
                Q.push(b);
            }
        }
        
        return -1;
    }
};