#include <cstdio>
#include <cmath>
#include<cstring>
#include<cctype>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>

#define LIMIT 17

const int MASK=97;

using namespace std;

struct Toy {
	int digit[3];
	
	Toy() {
		for(int i=0;i<3;i++) {
			this->digit[i]=-1;
		}
	}
	
	Toy(char c[]) {
		for(int i=0;i<3;i++) {
			this->digit[i]=c[i]-MASK;
		}
	}
	
	bool operator == (const Toy &t) const {
		for(int i=0;i<3;i++) {
			if(this->digit[i]!=t.digit[i]) return false;
		}
		
		return true;
	}
	
	bool operator < (const Toy &t) const {
		for(int i=0;i<3;i++) {
			if(this->digit[i]!=t.digit[i]) {
				return this->digit[i]<t.digit[i];
			}
		}
		
		return false;
	}
};

int bfs();
void initForbiddenWord();

map<Toy, int> visited;
bool isItForbidden(Toy&);
bool forbidden[51][3][26];
int N;
Toy src, dst;

//xinput set-int-prop 13 "Device Enabled" 8 0
int main() {
	int t;
	char a[MASK];
	
	scanf("%d", &t);
	for(int i = 1; i <= t; i++) {
		initForbiddenWord();
		
		scanf("%s", a);
		src = Toy(a);
		
		scanf("%s", a);
		dst = Toy(a);
		
		scanf("%d", &N);
		
		for(int j = 0; j < N; j++) {
			for(int k = 0; k < 3; k++) {
				scanf("%s", a);
				for(int l = 0; a[l] != '\0'; l++) {
					forbidden[j][k][a[l] - MASK] = true;
				}
			}
		}
		
		printf("Case %d: %d\n", i, bfs());
		visited.clear();
	}

	return 0;
}

int bfs() {
	if(isItForbidden(src)) return -1;
	if(isItForbidden(dst)) return -1;
	
	visited[src] = 0;
	queue<Toy> Q;
	Q.push(src);
	
	while(!Q.empty()) {
		Toy a = Q.front();
		Q.pop();
		
		if(a == dst) return visited[a];
		int newLevel = visited[a];
		
		for(int i = 0; i < 3; i++) {
			Toy b = a;
			b.digit[i] -= 1;
			if(b.digit[i] < 0) b.digit[i] = 25;
			if(isItForbidden(b)) continue;
			if(visited.find(b) != visited.end()) continue;
			
			if(b == dst) return newLevel + 1;
			visited[b] = newLevel + 1;
			Q.push(b);
		}
		
		for(int i = 0; i < 3; i++) {
			Toy b = a;
			b.digit[i] += 1;
			if(b.digit[i] > 25) b.digit[i] = 0;
			if(isItForbidden(b)) continue;
			if(visited.find(b) != visited.end()) continue;
			
			if(b == dst) return newLevel + 1;
			visited[b] = newLevel + 1;
			Q.push(b);
		}
	}
	
	return -1;
}

bool isItForbidden(Toy &toy) {
	for(int i = 0; i < N; i++) {
		bool flag = true;
		for(int j = 0; j < 3; j++) {
			flag &= forbidden[i][j][toy.digit[j]];
		}
		
		if(flag) return true;
	}
	
	return false;
}

void initForbiddenWord() {
	for(int i = 0; i < 51; i++) {
		for(int j = 0; j < 3; j++) {
			for(int k = 0; k < 26; k++) {
				forbidden[i][j][k] = false;
			}
		}
	}
}