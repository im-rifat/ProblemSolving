#include <cstdio>
#include <cmath>
#include <iostream>

using namespace std;

bool isInside(int, int, int, int, int, int);

//xinput set-int-prop 13 "Device Enabled" 8 0
int main() {
	int testCase;
	scanf("%d", &testCase);
	int x1, y1; // bottom left
	int x2, y2; // upper right
	int M;
	int a, b;

	for(int i = 1; i <= testCase; i++) {
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		scanf("%d", &M);
		printf("Case %d:\n", i);
		for(int j = 0; j < M; j++) {
			scanf("%d %d", &a, &b);
			bool inside = isInside(x1, y1, x2, y2, a, b);
			if(inside) {
				printf("Yes\n");
			} else printf("No\n");
		}
	}

	return 0;
}

bool isInside(int x1, int y1, int x2, int y2,int a, int b) { // bottom left, upper right
	return a > x1 && b > y1 && a < x2 && b < y2;
}