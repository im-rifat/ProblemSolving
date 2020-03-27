#include <cstdio>
#include <cmath>
#include <iostream>

using namespace std;

//xinput set-int-prop 13 "Device Enabled" 8 0
int main() {
	int ground = 0; // ground floor
	int testCase;
	scanf("%d", &testCase);
	int a; // my position
	int b; // life position
	int adjacentTime = 4; // time in seconds
	int lift = 3; // close or open
	int myTime = 5; // enter or exit

	for(int i = 1; i <= testCase; i++) {
		scanf("%d %d", &a, &b);
		int diff = abs(a - b);
		int totalTime = diff * adjacentTime + a * adjacentTime + 3 * lift + 2 * myTime;
		printf("Case %d: %d\n", i, totalTime);
	}

	return 0;
}