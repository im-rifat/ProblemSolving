#include <cstdio>
#include <cmath>
#include<cstring>
#include<cctype>
#include <iostream>

#define LIMIT 101

using namespace std;

int find(int* arr, int r) {
	if(arr[r] == r) return r;
	else {
		arr[r] = find(arr, arr[r]);
		return arr[r];
	}
}

void uniont(int* arr, int a, int b, int *disjointSet) {
	int parA = find(arr, a);
	int parB = find(arr, b);
	
	//printf("%d %d === %d %d\n", a, parA, b, parB);
	
	if(parA != parB) {
		arr[parA] = parB;
		*disjointSet -= 1;
		
		//printf("%d\n", *disjointSet);
	}
}

//xinput set-int-prop 13 "Device Enabled" 8 0
int main() {
	int n, m, caseNo = 0;
	while(scanf("%d %d", &n, &m) == 2 && n != 0 && m != 0) {
		int arr[n];
		
		for(int i = 0; i < n; i++) arr[i] = i;
		
		int i, j, disjointSets = n;
		for(int k = 0; k < m; k++) {
			scanf("%d %d", &i, &j);
			uniont(arr, i - 1, j - 1, &disjointSets);
		}
		
		printf("Case %d: %d\n", ++caseNo, disjointSets);
	}
	return 0;
}
