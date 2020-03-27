#include <cstdio>
#include <cmath>
#include<cstring>
#include<cctype>
#include <iostream>

#define LIMIT 101

using namespace std;

//xinput set-int-prop 13 "Device Enabled" 8 0
int main() {
	
	int t, a, b;
	scanf("%d", &t);
	
	for(int i = 1; i <= t; i++) {
		scanf("%d %d", &a, &b);
		int sum = 0;
		
		for(int j = (a % 2 == 0 ? a + 1 : a) ; j <= (b % 2 == 0 ? b - 1 : b) ; j += 2) {
			sum += j;
		}
		
		printf("Case %d: %d\n", i, sum);
	}
	return 0;
}