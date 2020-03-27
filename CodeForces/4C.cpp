#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <cctype>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>

#define LIMIT 33

const int MASK=97;

using namespace std;

//xinput set-int-prop 13 "Device Enabled" 8 0
int main() {
	string a;
	int n;
	map<string, int> db;
	
	scanf("%d", &n);
	getchar();
	for(int i = 0; i < n; i++) {
		cin >> a;
		
		if(db.find(a) == db.end()) {
			printf("OK\n");
			db[a] = 0;
		} else {
			db[a] += 1;
			printf("%s%d\n", a.c_str(), db[a]);
		}
	}

	return 0;
}