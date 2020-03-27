#include <cstdio>
#include <cmath>
#include<cstring>
#include<cctype>
#include <iostream>

#define LIMIT 101

using namespace std;

//xinput set-int-prop 13 "Device Enabled" 8 0
int main() {
	
	int r, b;
	scanf("%d %d", &r, &b); // red & blue socks
	int diff = 0, same = 0;

	if(r > b) {
		diff = b;
		r = r - b;
		
		same = r / 2;
	} else {
		diff = r;
		b = b - r;
		
		same = b / 2;
	}
	
	printf("%d %d\n", diff, same);
	
	return 0;
}